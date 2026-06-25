#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from geometry_msgs.msg import Point

from cv_bridge import CvBridge
import cv2
import mediapipe as mp
import numpy as np


class GestureDetectorNode(Node):

    def __init__(self):
        super().__init__('gesture_detector_node')

        self.bridge = CvBridge()

        self.declare_parameter('image_topic', '/image_raw')
        image_topic = self.get_parameter('image_topic').value

        # Saltar frames: MediaPipe es lo mas caro del pipeline en la Jetson Nano.
        # Procesar 1 de cada N frames reduce mucho la carga de CPU.
        self.declare_parameter('process_every_n_frames', 2)
        self.process_every_n_frames = int(self.get_parameter('process_every_n_frames').value)
        self.frame_count = 0

        # QoS sensor: best_effort + depth 1 para quedarnos siempre con el frame
        # mas reciente y descartar los atrasados (evita acumular latencia).
        image_qos = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
        )

        # Subscripción
        self.create_subscription(Image, image_topic, self.image_callback, image_qos)

        # Publicaciones
        self.greeting_pub = self.create_publisher(Bool, '/greeting_detected', 10)
        self.hand_center_pub = self.create_publisher(Point, '/hand_center', 10)

        # MediaPipe — compatible con 0.8.5 (sin model_complexity) y >=0.8.7 (con).
        self.mp_hands = mp.solutions.hands
        hands_kwargs = dict(
            static_image_mode=False,
            max_num_hands=1,
            min_detection_confidence=0.45,
            min_tracking_confidence=0.45,
        )
        try:
            self.hands = self.mp_hands.Hands(model_complexity=0, **hands_kwargs)
        except TypeError:
            self.hands = self.mp_hands.Hands(**hands_kwargs)

        # Memoria corta de mano
        self.last_hand_center = None
        self.hand_countdown = 0
        self.hand_hold_frames = 8

        # Memoria corta de greeting
        self.greeting_countdown = 0
        self.greeting_hold_frames = 6

        self.get_logger().info(f"Gesture Detector iniciado en tópico: {image_topic}")

    def is_open_palm(self, landmarks):
        lm = self.mp_hands.HandLandmark
        wrist = landmarks[lm.WRIST]

        def extended(tip_idx, mcp_idx):
            tip = landmarks[tip_idx]
            mcp = landmarks[mcp_idx]
            d_tip = ((tip.x - wrist.x) ** 2 + (tip.y - wrist.y) ** 2) ** 0.5
            d_mcp = ((mcp.x - wrist.x) ** 2 + (mcp.y - wrist.y) ** 2) ** 0.5
            return d_tip > d_mcp * 1.3

        raised = sum([
            extended(lm.INDEX_FINGER_TIP,  lm.INDEX_FINGER_MCP),
            extended(lm.MIDDLE_FINGER_TIP, lm.MIDDLE_FINGER_MCP),
            extended(lm.RING_FINGER_TIP,   lm.RING_FINGER_MCP),
            extended(lm.PINKY_TIP,         lm.PINKY_MCP),
        ])
        return raised >= 3

    def image_callback(self, msg: Image):
        self.frame_count += 1
        if self.frame_count % self.process_every_n_frames != 0:
            return

        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'cv_bridge error: {e}')
            return

        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = self.hands.process(rgb)

        greeting_msg = Bool()
        greeting_msg.data = False

        hand_center = Point()
        hand_center.x = -1.0
        hand_center.y = -1.0
        hand_center.z = 0.0

        hand_detected = False
        greeting_detected_now = False

        if results.multi_hand_landmarks:
            hand_landmarks = results.multi_hand_landmarks[0]
            lms = hand_landmarks.landmark

            hand_detected = True
            greeting_detected_now = self.is_open_palm(lms)

            xs = [lm.x for lm in lms]
            ys = [lm.y for lm in lms]

            cx = float(np.mean(xs))
            cy = float(np.mean(ys))

            self.last_hand_center = (cx, cy)
            self.hand_countdown = self.hand_hold_frames

            hand_center.x = cx
            hand_center.y = cy
            hand_center.z = 0.0

        else:
            if self.hand_countdown > 0 and self.last_hand_center is not None:
                self.hand_countdown -= 1
                hand_center.x = self.last_hand_center[0]
                hand_center.y = self.last_hand_center[1]
                hand_center.z = 0.0
            else:
                self.last_hand_center = None

        # Memoria corta de greeting
        if greeting_detected_now:
            self.greeting_countdown = self.greeting_hold_frames
        else:
            if self.greeting_countdown > 0:
                self.greeting_countdown -= 1

        greeting_msg.data = self.greeting_countdown > 0

        self.greeting_pub.publish(greeting_msg)
        self.hand_center_pub.publish(hand_center)


def main(args=None):
    rclpy.init(args=args)
    node = GestureDetectorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
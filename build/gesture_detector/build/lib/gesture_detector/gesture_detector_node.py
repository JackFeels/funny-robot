#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

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

        # Subscripciones
        self.create_subscription(Image, '/image_raw', self.image_callback, 10)

        # Publicaciones
        self.greeting_pub = self.create_publisher(Bool, '/greeting_detected', 10)
        self.hand_center_pub = self.create_publisher(Point, '/hand_center', 10)

        # MediaPipe
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(
            static_image_mode=False,
            max_num_hands=1,
            min_detection_confidence=0.35,
            min_tracking_confidence=0.35
        )

        # Memoria de mano (para estabilidad)
        self.last_hand_center = None
        self.hand_countdown = 0
        self.hand_hold_frames = 10

        self.get_logger().info("Gesture Detector iniciado")

    # -------------------------
    # DETECCIÓN DE SALUDO
    # -------------------------
    def is_open_palm(self, landmarks):
        lm = self.mp_hands.HandLandmark

        index_up = landmarks[lm.INDEX_FINGER_TIP].y < landmarks[lm.INDEX_FINGER_MCP].y
        middle_up = landmarks[lm.MIDDLE_FINGER_TIP].y < landmarks[lm.MIDDLE_FINGER_MCP].y
        ring_up = landmarks[lm.RING_FINGER_TIP].y < landmarks[lm.RING_FINGER_MCP].y
        pinky_up = landmarks[lm.PINKY_TIP].y < landmarks[lm.PINKY_MCP].y

        thumb_open = abs(landmarks[lm.THUMB_TIP].x - landmarks[lm.THUMB_CMC].x) > 0.02

        raised = sum([index_up, middle_up, ring_up, pinky_up])

        return raised >= 3 and thumb_open

    # -------------------------
    # CALLBACK PRINCIPAL
    # -------------------------
    def image_callback(self, msg: Image):
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

        if results.multi_hand_landmarks:
            hand_landmarks = results.multi_hand_landmarks[0]
            lms = hand_landmarks.landmark

            # Detectar saludo
            greeting_msg.data = self.is_open_palm(lms)

            # Centro de la mano
            xs = [lm.x for lm in lms]
            ys = [lm.y for lm in lms]

            cx = float(np.mean(xs))
            cy = float(np.mean(ys))

            # Guardar memoria
            self.last_hand_center = (cx, cy)
            self.hand_countdown = self.hand_hold_frames

            hand_center.x = cx
            hand_center.y = cy
            hand_center.z = 0.0

        else:
            # Mantener última posición unos frames
            if self.hand_countdown > 0 and self.last_hand_center is not None:
                self.hand_countdown -= 1
                hand_center.x = self.last_hand_center[0]
                hand_center.y = self.last_hand_center[1]
                hand_center.z = 0.0
            else:
                self.last_hand_center = None

        # Publicar
        self.greeting_pub.publish(greeting_msg)
        self.hand_center_pub.publish(hand_center)


# -------------------------
# MAIN
# -------------------------
def main(args=None):
    rclpy.init(args=args)
    node = GestureDetectorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
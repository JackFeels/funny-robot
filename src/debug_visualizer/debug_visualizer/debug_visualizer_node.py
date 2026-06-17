import cv2
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from geometry_msgs.msg import Point
from cv_bridge import CvBridge

from tb3_interfaces.msg import TrackedPersonArray, TargetInfo


class DebugVisualizerNode(Node):
    def __init__(self):
        super().__init__('debug_visualizer_node')

        self.declare_parameter('image_topic', '/image_raw')
        self.image_topic = self.get_parameter('image_topic').value

        self.bridge = CvBridge()

        self.latest_frame = None
        self.latest_greeting = False
        self.latest_hand = None
        self.latest_people = []
        self.latest_target = None

        # QoS sensor: best_effort + depth 1 para quedarnos con el frame mas reciente.
        image_qos = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.image_sub = self.create_subscription(
            Image, self.image_topic, self.image_callback, image_qos
        )
        self.greeting_sub = self.create_subscription(
            Bool, '/greeting_detected', self.greeting_callback, 10
        )
        self.hand_sub = self.create_subscription(
            Point, '/hand_center', self.hand_callback, 10
        )
        self.people_sub = self.create_subscription(
            TrackedPersonArray, '/tracked_persons', self.people_callback, 10
        )
        self.target_sub = self.create_subscription(
            TargetInfo, '/target_info', self.target_callback, 10
        )

        self.timer = self.create_timer(0.03, self.draw_loop)

        self.get_logger().info(f'Debug visualizer escuchando imagen en {self.image_topic}')

    def image_callback(self, msg: Image):
        try:
            self.latest_frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'cv_bridge error: {e}')

    def greeting_callback(self, msg: Bool):
        self.latest_greeting = msg.data

    def hand_callback(self, msg: Point):
        if msg.x >= 0.0 and msg.y >= 0.0:
            self.latest_hand = (msg.x, msg.y)
        else:
            self.latest_hand = None

    def people_callback(self, msg: TrackedPersonArray):
        self.latest_people = msg.persons

    def target_callback(self, msg: TargetInfo):
        self.latest_target = msg

    def draw_loop(self):
        if self.latest_frame is None:
            return

        frame = self.latest_frame.copy()
        h, w = frame.shape[:2]

        # Texto saludo
        greeting_text = f"Greeting: {'TRUE' if self.latest_greeting else 'FALSE'}"
        greeting_color = (0, 255, 0) if self.latest_greeting else (0, 0, 255)
        cv2.putText(frame, greeting_text, (20, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.8, greeting_color, 2)

        # Mano
        if self.latest_hand is not None:
            hx = int(self.latest_hand[0] * w)
            hy = int(self.latest_hand[1] * h)
            cv2.circle(frame, (hx, hy), 10, (255, 255, 0), -1)
            cv2.putText(frame, "HAND", (hx + 10, hy - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 2)

        # Personas
        target_id = -1
        target_locked = False
        if self.latest_target is not None:
            target_id = self.latest_target.target_id
            target_locked = self.latest_target.locked

        for p in self.latest_people:
            cx = int(p.cx * w)
            cy = int(p.cy * h)
            bw = int(p.width * w)
            bh = int(p.height * h)

            x1 = int(cx - bw / 2)
            y1 = int(cy - bh / 2)
            x2 = int(cx + bw / 2)
            y2 = int(cy + bh / 2)

            color = (255, 0, 0)
            label = f"ID {p.id}"

            if target_locked and p.id == target_id:
                color = (0, 255, 0)
                label = f"TARGET {p.id}"

            cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
            cv2.circle(frame, (cx, cy), 4, color, -1)
            cv2.putText(frame, label, (x1, max(20, y1 - 10)),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, color, 2)

        # Punto de seguimiento por mano (fallback, sin caja HOG)
        if (self.latest_target is not None
                and self.latest_target.locked
                and self.latest_target.target_id == -2
                and self.latest_hand is not None):
            hx = int(self.latest_hand[0] * w)
            hy = int(self.latest_hand[1] * h)
            cv2.circle(frame, (hx, hy), 18, (0, 165, 255), 3)
            cv2.putText(frame, "HAND TARGET", (hx + 14, hy - 14),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 165, 255), 2)

        # Estado target
        if self.latest_target is not None:
            tid = self.latest_target.target_id
            tid_str = "HAND" if tid == -2 else str(tid)
            searching = getattr(self.latest_target, 'searching', False)
            state = "LOCKED" if self.latest_target.locked else ("SEARCHING" if searching else "NONE")
            target_text = f"State: {state} | Target ID: {tid_str}"
            cv2.putText(frame, target_text, (20, 65),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

            # Al buscar, dibujar hacia donde se vio por ultima vez el objetivo
            if searching and not self.latest_target.locked:
                lx = int(self.latest_target.cx * w)
                cv2.arrowedLine(frame, (w // 2, h - 30), (lx, h - 30),
                                (0, 165, 255), 3, tipLength=0.3)
                cv2.putText(frame, "BUSCANDO", (lx - 40, h - 40),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 165, 255), 2)

        cv2.imshow("Debug TurtleBot", frame)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = DebugVisualizerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    cv2.destroyAllWindows()
    node.destroy_node()
    rclpy.shutdown()
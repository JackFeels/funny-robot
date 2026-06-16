import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from tb3_interfaces.msg import TargetInfo


class FollowControllerNode(Node):
    def __init__(self):
        super().__init__('follow_controller_node')

        self.target_sub = self.create_subscription(TargetInfo, '/target_info', self.target_callback, 10)

        # El LDS-01 publica /scan con QoS best_effort (sensor data). Un suscriptor
        # reliable NO recibiria nada -> la evasion de obstaculos quedaria muerta.
        scan_qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, scan_qos)
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        self.current_target = None
        self.front_obstacle_distance = 999.0
        self.left_obstacle_distance  = 999.0
        self.right_obstacle_distance = 999.0

        self.declare_parameter('desired_width', 0.25)
        self.declare_parameter('linear_gain', 0.6)
        self.declare_parameter('angular_gain', 1.8)
        self.declare_parameter('max_linear', 0.18)
        self.declare_parameter('max_angular', 0.9)
        self.declare_parameter('stop_distance', 0.45)

        self.desired_width = float(self.get_parameter('desired_width').value)
        self.linear_gain = float(self.get_parameter('linear_gain').value)
        self.angular_gain = float(self.get_parameter('angular_gain').value)
        self.max_linear = float(self.get_parameter('max_linear').value)
        self.max_angular = float(self.get_parameter('max_angular').value)
        self.stop_distance = float(self.get_parameter('stop_distance').value)

        self.timer = self.create_timer(0.1, self.control_loop)

    def _sector_min(self, ranges, angles, lo_deg, hi_deg):
        lo = np.radians(lo_deg)
        hi = np.radians(hi_deg)
        mask = (angles >= lo) & (angles <= hi)
        vals = ranges[mask]
        vals = vals[np.isfinite(vals)]
        return float(np.min(vals)) if len(vals) > 0 else 999.0

    def target_callback(self, msg: TargetInfo):
        self.current_target = msg

    def scan_callback(self, msg: LaserScan):
        n = len(msg.ranges)
        if n == 0:
            self.front_obstacle_distance = 999.0
            self.left_obstacle_distance  = 999.0
            self.right_obstacle_distance = 999.0
            return

        angles = msg.angle_min + np.arange(n) * msg.angle_increment
        angles = (angles + np.pi) % (2 * np.pi) - np.pi
        ranges = np.array(msg.ranges, dtype=np.float32)

        self.front_obstacle_distance = self._sector_min(ranges, angles, -30,  30)
        self.left_obstacle_distance  = self._sector_min(ranges, angles,  30,  90)
        self.right_obstacle_distance = self._sector_min(ranges, angles, -90, -30)

    def control_loop(self):
        twist = Twist()

        if self.current_target is None or not self.current_target.locked:
            self.cmd_pub.publish(twist)
            return

        error_x = self.current_target.cx - 0.5
        target_width = self.current_target.width

        angular = -self.angular_gain * error_x
        angular = max(-self.max_angular, min(self.max_angular, angular))

        width_error = self.desired_width - target_width
        linear = self.linear_gain * width_error
        linear = max(-self.max_linear * 0.5, min(self.max_linear, linear))

        if self.front_obstacle_distance < self.stop_distance:
            linear = min(0.0, linear)
            # Girar hacia el lado con más espacio libre
            if self.left_obstacle_distance >= self.right_obstacle_distance:
                angular = self.max_angular   # gira izquierda
            else:
                angular = -self.max_angular  # gira derecha

        twist.linear.x = linear
        twist.angular.z = angular
        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = FollowControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

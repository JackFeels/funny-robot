import signal
import time

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
        self.last_target_time = 0.0
        self.front_obstacle_distance = 999.0
        self.left_obstacle_distance  = 999.0
        self.right_obstacle_distance = 999.0
        self.range_min = 0.05  # actualizado con cada scan; filtra los 0.0 invalidos del LDS

        self.declare_parameter('desired_width', 0.25)
        self.declare_parameter('linear_gain', 0.6)
        # Bajado de 1.8 a 0.9: con tracker a ~5 Hz, el control de 10 Hz aplicaba
        # 2 ticks del target viejo antes de recibir uno nuevo -> overshoot
        # constante en el lockeo. Menos ganancia = menos overshoot.
        self.declare_parameter('angular_gain', 0.9)
        self.declare_parameter('max_linear', 0.18)
        # Bajado de 0.9 a 0.5: limita la velocidad maxima de giro para que el
        # tracker tenga tiempo de re-encuadrar antes que el robot lo pierda.
        self.declare_parameter('max_angular', 0.5)
        self.declare_parameter('stop_distance', 0.45)
        # Bajado de 0.5 a 0.3: misma razon que max_angular.
        self.declare_parameter('search_angular', 0.3)  # giro minimo al buscar un target perdido
        # Zona muerta: si el target esta cerca del centro, no girar (evita
        # oscilacion alrededor del centro por jitter del tracker).
        self.declare_parameter('angular_deadband', 0.08)
        # Los Dynamixel no vencen la friccion estatica con comandos muy chicos:
        # pedidos < ~0.04 m/s no mueven el robot (stall silencioso).
        self.declare_parameter('min_linear', 0.05)
        # En modo HAND (target_id=-2) el ancho es ficticio y no hay estimacion
        # de distancia por bbox -> capear el avance y dejar que el LiDAR
        # (stop_distance) sea quien frene cerca de la persona.
        self.declare_parameter('hand_max_linear', 0.10)
        # Si /target_info deja de llegar (murio el selector/tracker/camara),
        # detenerse en vez de repetir el ultimo comando para siempre.
        self.declare_parameter('target_timeout', 0.8)

        self.desired_width = float(self.get_parameter('desired_width').value)
        self.linear_gain = float(self.get_parameter('linear_gain').value)
        self.angular_gain = float(self.get_parameter('angular_gain').value)
        self.max_linear = float(self.get_parameter('max_linear').value)
        self.max_angular = float(self.get_parameter('max_angular').value)
        self.stop_distance = float(self.get_parameter('stop_distance').value)
        self.search_angular = float(self.get_parameter('search_angular').value)
        self.angular_deadband = float(self.get_parameter('angular_deadband').value)
        self.min_linear = float(self.get_parameter('min_linear').value)
        self.hand_max_linear = float(self.get_parameter('hand_max_linear').value)
        self.target_timeout = float(self.get_parameter('target_timeout').value)

        self.timer = self.create_timer(0.1, self.control_loop)

    def publish_stop(self):
        self.cmd_pub.publish(Twist())

    def _sector_min(self, ranges, angles, lo_deg, hi_deg):
        lo = np.radians(lo_deg)
        hi = np.radians(hi_deg)
        mask = (angles >= lo) & (angles <= hi)
        vals = ranges[mask]
        # El LDS reporta 0.0 (o < range_min) en mediciones invalidas; sin este
        # filtro min() daria 0 y el robot creeria que hay un obstaculo pegado
        # SIEMPRE -> quedaria en modo evasion eterna.
        vals = vals[np.isfinite(vals) & (vals > self.range_min)]
        return float(np.min(vals)) if len(vals) > 0 else 999.0

    def target_callback(self, msg: TargetInfo):
        self.current_target = msg
        self.last_target_time = time.monotonic()

    def scan_callback(self, msg: LaserScan):
        self.range_min = max(0.05, float(msg.range_min))
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

        target = self.current_target

        # Watchdog: si /target_info dejo de llegar (nodo upstream muerto),
        # el ultimo target queda congelado -> sin esto el robot repetiria
        # el ultimo comando para siempre.
        if target is not None and (time.monotonic() - self.last_target_time) > self.target_timeout:
            self.current_target = None
            target = None

        # Sin objetivo y sin busqueda activa -> parar
        if target is None or (not target.locked and not target.searching):
            self.cmd_pub.publish(twist)
            return

        # Objetivo perdido hace poco: girar (sin avanzar) hacia su ultima
        # direccion conocida para volver a meterlo en el encuadre. Esto cubre
        # el caso de perderlo de vista al esquivar un obstaculo.
        if not target.locked and target.searching:
            error_x = target.cx - 0.5
            angular = -self.angular_gain * error_x
            # garantizar un giro minimo aunque la ultima posicion fuera central
            if abs(angular) < self.search_angular:
                angular = self.search_angular if error_x <= 0 else -self.search_angular
            angular = max(-self.max_angular, min(self.max_angular, angular))
            twist.linear.x = 0.0
            twist.angular.z = angular
            self.cmd_pub.publish(twist)
            return

        error_x = self.current_target.cx - 0.5
        target_width = self.current_target.width

        # Deadband: si el target esta cerca del centro, no girar. Evita
        # oscilacion por jitter del tracker cuando ya esta encuadrado.
        if abs(error_x) < self.angular_deadband:
            angular = 0.0
        else:
            angular = -self.angular_gain * error_x
            angular = max(-self.max_angular, min(self.max_angular, angular))

        width_error = self.desired_width - target_width
        linear = self.linear_gain * width_error
        linear = max(-self.max_linear * 0.5, min(self.max_linear, linear))

        # Modo HAND: el ancho es ficticio (0.08 fijo), no hay estimacion real
        # de distancia -> capear el avance; el LiDAR (stop_distance) frena cerca.
        if self.current_target.target_id == -2:
            linear = min(linear, self.hand_max_linear)

        # Floor de velocidad: los motores no vencen la friccion estatica con
        # comandos muy chicos -> redondear al minimo util (solo si hay intencion
        # real de moverse; el "quieto por distancia alcanzada" queda en 0).
        if 0.0 < linear < self.min_linear:
            linear = self.min_linear if width_error > 0.02 else 0.0
        elif -self.min_linear < linear < 0.0:
            linear = -self.min_linear if width_error < -0.02 else 0.0

        if self.front_obstacle_distance < self.stop_distance:
            linear = min(0.0, linear)
            # Girar suave hacia el lado con mas espacio libre. A max_angular
            # contra un mueble era agresivo y barria el frente contra el.
            avoid_turn = min(0.3, self.max_angular)
            if self.left_obstacle_distance >= self.right_obstacle_distance:
                angular = avoid_turn    # gira izquierda
            else:
                angular = -avoid_turn   # gira derecha

        twist.linear.x = linear
        twist.angular.z = angular
        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = FollowControllerNode()

    # Al recibir SIGTERM/SIGINT publicar Twist cero ANTES de morir: el OpenCR
    # mantiene el ultimo comando, asi que sin esto un `pkill` (sin -9) deja al
    # robot moviendose indefinidamente.
    def _stop_and_exit(signum, frame):
        try:
            for _ in range(5):
                node.publish_stop()
                time.sleep(0.03)
        finally:
            raise SystemExit(0)

    signal.signal(signal.SIGTERM, _stop_and_exit)
    signal.signal(signal.SIGINT, _stop_and_exit)

    try:
        rclpy.spin(node)
    finally:
        try:
            for _ in range(5):
                node.publish_stop()
                time.sleep(0.03)
        except Exception:
            pass
        node.destroy_node()
        rclpy.shutdown()

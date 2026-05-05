import math

import rclpy
from rclpy.node import Node

from std_msgs.msg import Bool
from geometry_msgs.msg import Point
from tb3_interfaces.msg import TrackedPersonArray, TargetInfo


class TargetSelectorNode(Node):
    def __init__(self):
        super().__init__('target_selector_node')

        self.greeting_sub = self.create_subscription(Bool, '/greeting_detected', self.greeting_callback, 10)
        self.hand_sub = self.create_subscription(Point, '/hand_center', self.hand_callback, 10)
        self.people_sub = self.create_subscription(TrackedPersonArray, '/tracked_persons', self.people_callback, 10)

        self.target_pub = self.create_publisher(TargetInfo, '/target_info', 10)

        self.latest_greeting = False
        self.latest_hand = None
        self.latest_people = []
        self.locked_id = -1
        self.last_seen_countdown = 0
        self.max_lost_cycles = 30 # Numero de ciclos que se considera que el objetivo sigue presente después de perderlo de vista.
        self.last_target_position = None

        self.greeting_countdown = 0
        self.greeting_hold_frames = 10

    def greeting_callback(self, msg: Bool):
        if msg.data:
            self.greeting_countdown = self.greeting_hold_frames
        else:
            if self.greeting_countdown > 0:
                self.greeting_countdown -= 1

        self.latest_greeting = self.greeting_countdown > 0

    def hand_callback(self, msg: Point):
        if msg.x >= 0.0 and msg.y >= 0.0:
            self.latest_hand = (msg.x, msg.y)
        else:
            self.latest_hand = None

    def people_callback(self, msg: TrackedPersonArray):
        self.latest_people = msg.persons
        self.update_target()

    def update_target(self):
        target_msg = TargetInfo()
        target_msg.locked = False
        target_msg.target_id = -1
        target_msg.cx = 0.0
        target_msg.cy = 0.0
        target_msg.width = 0.0
        target_msg.height = 0.0

        # 1) Si ya hay un target bloqueado, intentar mantenerlo por ID
        if self.locked_id != -1:
            for p in self.latest_people:
                if p.id == self.locked_id:
                    target_msg.locked = True
                    target_msg.target_id = p.id
                    target_msg.cx = p.cx
                    target_msg.cy = p.cy
                    target_msg.width = p.width
                    target_msg.height = p.height

                    self.last_target_position = (p.cx, p.cy)
                    self.last_seen_countdown = self.max_lost_cycles
                    self.target_pub.publish(target_msg)
                    return

            # 2) Si no apareció el mismo ID, intentar recuperar por cercanía
            if self.last_target_position is not None and len(self.latest_people) > 0:
                lx, ly = self.last_target_position
                best_dist = 9999.0
                best_person = None

                for p in self.latest_people:
                    d = math.sqrt((p.cx - lx) ** 2 + (p.cy - ly) ** 2)
                    if d < best_dist:
                        best_dist = d
                        best_person = p

                # Umbral de cercanía para reasignar
                if best_person is not None and best_dist < 0.2:
                    self.locked_id = best_person.id

                    target_msg.locked = True
                    target_msg.target_id = best_person.id
                    target_msg.cx = best_person.cx
                    target_msg.cy = best_person.cy
                    target_msg.width = best_person.width
                    target_msg.height = best_person.height

                    self.last_target_position = (best_person.cx, best_person.cy)
                    self.last_seen_countdown = self.max_lost_cycles
                    self.target_pub.publish(target_msg)
                    return

            # 3) Si no pudo recuperar, descontar tiempo
            self.last_seen_countdown -= 1
            if self.last_seen_countdown <= 0:
                self.locked_id = -1
                self.last_target_position = None

        # 4) Si no hay target bloqueado, intentar elegir uno con saludo + mano
        if self.locked_id == -1 and self.latest_greeting and self.latest_hand is not None and len(self.latest_people) > 0:
            hx, hy = self.latest_hand

            best_person = None
            best_score = -9999.0

            for p in self.latest_people:
                # Caja normalizada
                x1 = p.cx - p.width / 2.0
                y1 = p.cy - p.height / 2.0
                x2 = p.cx + p.width / 2.0
                y2 = p.cy + p.height / 2.0

                # Expandimos la caja para tolerar mano levantada y cajas mal ajustadas
                expand_x = p.width * 0.35
                expand_y = p.height * 0.60

                ex1 = x1 - expand_x
                ey1 = y1 - expand_y
                ex2 = x2 + expand_x
                ey2 = y2 + expand_y

                hand_inside = (ex1 <= hx <= ex2) and (ey1 <= hy <= ey2)

                if not hand_inside:
                    continue

                # Solo entre personas que tienen la mano dentro: elegir la más cercana
                dist = math.sqrt((p.cx - hx) ** 2 + (p.cy - hy) ** 2)
                score = -dist

                if score > best_score:
                    best_score = score
                    best_person = p

            if best_person is not None:
                self.locked_id = best_person.id
                self.last_seen_countdown = self.max_lost_cycles
                self.last_target_position = (best_person.cx, best_person.cy)

                target_msg.locked = True
                target_msg.target_id = best_person.id
                target_msg.cx = best_person.cx
                target_msg.cy = best_person.cy
                target_msg.width = best_person.width
                target_msg.height = best_person.height

            elif self.latest_hand is not None:
                # Fallback: HOG no detectó persona pero hay saludo+mano activos.
                # Seguir usando el centro de la mano con ancho ficticio pequeño
                # para que el robot se acerque hasta alcanzar desired_width.
                hx, hy = self.latest_hand
                target_msg.locked = True
                target_msg.target_id = -2
                target_msg.cx = hx
                target_msg.cy = hy
                target_msg.width = 0.08
                target_msg.height = 0.15

        self.target_pub.publish(target_msg)

def main(args=None):
    rclpy.init(args=args)
    node = TargetSelectorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

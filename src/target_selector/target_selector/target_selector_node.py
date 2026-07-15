import math
import time

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
        # Ventana de gracia en TIEMPO REAL (no ciclos): update_target puede
        # correr a ~10 Hz (HOG) o ~40 Hz (hand-mode), y con un contador de
        # ciclos la misma constante daba 3 s o 0.7 s segun el modo.
        self.lost_grace_seconds = 3.0
        self.lost_deadline = 0.0
        self.last_target_position = None

        self.greeting_countdown = 0
        # gesture_detector publica a ~30 Hz; con 30 frames mantenemos el saludo
        # vivo ~1 s aun si el usuario lo intercala -> el frame del tracker
        # (~10 Hz) lo atrapa con casi total seguridad.
        self.greeting_hold_frames = 30

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
        # En modo HAND-only el lock depende solo de la mano (mediapipe ~30 Hz).
        # No hace falta esperar al frame de HOG (~10 Hz) para refrescar el target.
        if self.locked_id == -2:
            self.update_target()

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

        # 0) HAND-mode (target_id == -2): seguimos la mano directamente,
        #    sin depender de IDs de HOG. Persiste mientras haya mano detectada.
        if self.locked_id == -2:
            if self.latest_hand is not None:
                hx, hy = self.latest_hand
                target_msg.locked = True
                target_msg.target_id = -2
                target_msg.cx = hx
                target_msg.cy = hy
                target_msg.width = 0.08
                target_msg.height = 0.15
                self.last_target_position = (hx, hy)
                self.lost_deadline = time.monotonic() + self.lost_grace_seconds
                self.target_pub.publish(target_msg)
                return
            # Sin mano: misma ventana de gracia que HOG
            if time.monotonic() < self.lost_deadline and self.last_target_position is not None:
                target_msg.searching = True
                target_msg.cx = self.last_target_position[0]
                target_msg.cy = self.last_target_position[1]
                self.target_pub.publish(target_msg)
                return
            else:
                self.locked_id = -1
                self.last_target_position = None

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
                    self.lost_deadline = time.monotonic() + self.lost_grace_seconds
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

                # Umbral de cercanía para reasignar. 0.2 -> 0.35: al girar rapido
                # el bbox salta hasta 20 % de frame entre updates de HOG, con 0.2
                # el recover fallaba y perdiamos el lock al primer tramo giratorio.
                if best_person is not None and best_dist < 0.35:
                    self.locked_id = best_person.id

                    target_msg.locked = True
                    target_msg.target_id = best_person.id
                    target_msg.cx = best_person.cx
                    target_msg.cy = best_person.cy
                    target_msg.width = best_person.width
                    target_msg.height = best_person.height

                    self.last_target_position = (best_person.cx, best_person.cy)
                    self.lost_deadline = time.monotonic() + self.lost_grace_seconds
                    self.target_pub.publish(target_msg)
                    return

            # 3) Si no pudo recuperar, descontar tiempo. Mientras dure la ventana
            #    de gracia avisamos "searching" con la ultima posicion conocida,
            #    para que el controlador gire a buscar en vez de frenar.
            if time.monotonic() < self.lost_deadline and self.last_target_position is not None:
                target_msg.searching = True
                target_msg.cx = self.last_target_position[0]
                target_msg.cy = self.last_target_position[1]
                self.target_pub.publish(target_msg)
                return
            else:
                self.locked_id = -1
                self.last_target_position = None

        # 4) Si no hay target bloqueado, intentar elegir uno con saludo + mano
        if self.locked_id == -1 and self.latest_greeting and self.latest_hand is not None:
            hx, hy = self.latest_hand

            best_person = None
            best_score = -9999.0

            for p in self.latest_people:
                # Caja normalizada
                x1 = p.cx - p.width / 2.0
                y1 = p.cy - p.height / 2.0
                x2 = p.cx + p.width / 2.0
                y2 = p.cy + p.height / 2.0

                # Expandimos generosamente hacia arriba para mano levantada,
                # y a los lados para cajas HOG mal ajustadas.
                expand_x = p.width * 0.45
                expand_top = p.height * 1.20  # mucho mas hacia arriba
                expand_bot = p.height * 0.40

                ex1 = x1 - expand_x
                ey1 = y1 - expand_top
                ex2 = x2 + expand_x
                ey2 = y2 + expand_bot

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
                self.lost_deadline = time.monotonic() + self.lost_grace_seconds
                self.last_target_position = (best_person.cx, best_person.cy)

                target_msg.locked = True
                target_msg.target_id = best_person.id
                target_msg.cx = best_person.cx
                target_msg.cy = best_person.cy
                target_msg.width = best_person.width
                target_msg.height = best_person.height
            else:
                # Fallback: HOG no detecto a la persona O la mano quedo fuera de
                # cualquier caja. Igual hay saludo+mano: lockear al centro de la
                # mano con ancho ficticio para que el robot avance hasta acercarse.
                # (Antes este fallback estaba dentro de "if len(people) > 0" y
                #  nunca disparaba cuando HOG no detectaba nada.)
                hx, hy = self.latest_hand
                self.locked_id = -2
                self.lost_deadline = time.monotonic() + self.lost_grace_seconds
                self.last_target_position = (hx, hy)

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

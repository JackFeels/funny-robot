"""Streamer MJPEG de debug: http://<jetson>:8080

Muestra el video de /image_raw con overlay del estado real del target
(LOCKED / SEARCHING / NONE), el saludo y los FPS del pipeline.
Pensado para correr dentro del container junto a los demas nodos:

    python3 tools/stream.py

Endpoints:
    /        pagina con el stream embebido
    /stream  MJPEG multipart
    /snap    ultimo frame JPEG (para curl / healthcheck)
"""
import http.server
import socketserver
import threading
import time

import cv2
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Bool

from tb3_interfaces.msg import TargetInfo

br = CvBridge()
state = {
    "frame": None,
    "target": None,
    "greeting": False,
    "lock": threading.Lock(),
    "fps": 0.0,
    "_t": time.time(),
    "_n": 0,
}


class Streamer(Node):
    def __init__(self):
        super().__init__("camera_streamer")
        self.create_subscription(Image, "/image_raw", self.on_img, 5)
        self.create_subscription(TargetInfo, "/target_info", self.on_tgt, 5)
        self.create_subscription(Bool, "/greeting_detected", self.on_greet, 5)
        self.get_logger().info("Streamer en http://0.0.0.0:8080")

    def on_img(self, msg):
        img = br.imgmsg_to_cv2(msg, "bgr8")
        h, w = img.shape[:2]
        tgt = state["target"]

        # Estado REAL del target (no "llego un mensaje": eso confundia el debug)
        if tgt is not None and tgt.locked:
            tstate = "LOCKED id=" + ("HAND" if tgt.target_id == -2 else str(tgt.target_id))
            color = (0, 255, 0)
        elif tgt is not None and tgt.searching:
            tstate = "SEARCHING"
            color = (0, 165, 255)
        else:
            tstate = "NONE"
            color = (128, 128, 128)

        if tgt is not None and (tgt.locked or tgt.searching):
            cx, cy = int(tgt.cx * w), int(tgt.cy * h)
            bw, bh = max(4, int(tgt.width * w)), max(4, int(tgt.height * h))
            x1, y1 = max(0, cx - bw // 2), max(0, cy - bh // 2)
            x2, y2 = min(w, cx + bw // 2), min(h, cy + bh // 2)
            cv2.rectangle(img, (x1, y1), (x2, y2), color, 3)
            cv2.circle(img, (cx, cy), 5, color, -1)

        banner = f"FPS:{state['fps']:.1f}  greet:{state['greeting']}  {tstate}"
        cv2.rectangle(img, (0, 0), (w, 28), (0, 0, 0), -1)
        cv2.putText(img, banner, (8, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.55, color, 1)

        ok, buf = cv2.imencode(".jpg", img, [cv2.IMWRITE_JPEG_QUALITY, 70])
        if ok:
            with state["lock"]:
                state["frame"] = buf.tobytes()

        state["_n"] += 1
        if state["_n"] >= 10:
            now = time.time()
            state["fps"] = state["_n"] / (now - state["_t"])
            state["_t"], state["_n"] = now, 0

    def on_tgt(self, msg):
        state["target"] = msg

    def on_greet(self, msg):
        state["greeting"] = msg.data


class Handler(http.server.BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def do_GET(self):
        if self.path in ("/", "/index.html"):
            html = (b"<html><body style='margin:0;background:#111'>"
                    b"<img src='/stream' style='width:100%'></body></html>")
            self.send_response(200)
            self.send_header("Content-Type", "text/html")
            self.end_headers()
            self.wfile.write(html)
        elif self.path == "/stream":
            self.send_response(200)
            self.send_header("Content-Type", "multipart/x-mixed-replace; boundary=frame")
            self.send_header("Cache-Control", "no-cache")
            self.end_headers()
            try:
                while True:
                    with state["lock"]:
                        f = state["frame"]
                    if f:
                        self.wfile.write(b"--frame\r\nContent-Type: image/jpeg\r\n"
                                         b"Content-Length: " + str(len(f)).encode()
                                         + b"\r\n\r\n" + f + b"\r\n")
                    time.sleep(0.08)
            except (BrokenPipeError, ConnectionResetError):
                pass
        elif self.path == "/snap":
            with state["lock"]:
                f = state["frame"]
            if f:
                self.send_response(200)
                self.send_header("Content-Type", "image/jpeg")
                self.end_headers()
                self.wfile.write(f)
            else:
                self.send_response(503)
                self.end_headers()
        else:
            self.send_response(404)
            self.end_headers()


class TS(socketserver.ThreadingTCPServer):
    allow_reuse_address = True
    daemon_threads = True


def main():
    rclpy.init()
    node = Streamer()
    threading.Thread(target=lambda: TS(("0.0.0.0", 8080), Handler).serve_forever(),
                     daemon=True).start()
    try:
        rclpy.spin(node)
    finally:
        rclpy.shutdown()


if __name__ == "__main__":
    main()

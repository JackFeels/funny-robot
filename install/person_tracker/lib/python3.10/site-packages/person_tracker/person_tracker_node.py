#!/usr/bin/env python3

import cv2
import numpy as np

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from tb3_interfaces.msg import TrackedPerson, TrackedPersonArray


def iou(box_a, box_b):
    ax1, ay1, aw, ah = box_a
    bx1, by1, bw, bh = box_b

    ax2, ay2 = ax1 + aw, ay1 + ah
    bx2, by2 = bx1 + bw, by1 + bh

    inter_x1 = max(ax1, bx1)
    inter_y1 = max(ay1, by1)
    inter_x2 = min(ax2, bx2)
    inter_y2 = min(ay2, by2)

    if inter_x2 <= inter_x1 or inter_y2 <= inter_y1:
        return 0.0

    inter_area = (inter_x2 - inter_x1) * (inter_y2 - inter_y1)
    union_area = aw * ah + bw * bh - inter_area
    return inter_area / union_area if union_area > 0 else 0.0


class PersonTrackerNode(Node):
    def __init__(self):
        super().__init__('person_tracker_node')

        self.declare_parameter('image_topic', '/image_raw')
        self.image_topic = self.get_parameter('image_topic').value

        self.bridge = CvBridge()
        self.image_sub = self.create_subscription(Image, self.image_topic, self.image_callback, 10)
        self.tracks_pub = self.create_publisher(TrackedPersonArray, '/tracked_persons', 10)

        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

        self.next_id = 1
        self.tracks = {}
        self.max_missed = 8

        self.frame_count = 0
        self.process_every_n_frames = 3

        self.get_logger().info(f'Person tracker listening on: {self.image_topic}')

    def non_max_suppression(self, boxes, overlapThresh=0.5):
        if len(boxes) == 0:
            return []

        boxes = np.array(boxes)

        pick = []
        x1 = boxes[:, 0]
        y1 = boxes[:, 1]
        x2 = boxes[:, 0] + boxes[:, 2]
        y2 = boxes[:, 1] + boxes[:, 3]

        area = (x2 - x1 + 1) * (y2 - y1 + 1)
        idxs = np.argsort(y2)

        while len(idxs) > 0:
            last = idxs[-1]
            pick.append(last)

            xx1 = np.maximum(x1[last], x1[idxs[:-1]])
            yy1 = np.maximum(y1[last], y1[idxs[:-1]])
            xx2 = np.minimum(x2[last], x2[idxs[:-1]])
            yy2 = np.minimum(y2[last], y2[idxs[:-1]])

            w = np.maximum(0, xx2 - xx1 + 1)
            h = np.maximum(0, yy2 - yy1 + 1)

            overlap = (w * h) / area[idxs[:-1]]

            idxs = np.delete(
                idxs,
                np.concatenate(([len(idxs) - 1], np.where(overlap > overlapThresh)[0]))
            )

        return boxes[pick].astype("int")

    def image_callback(self, msg: Image):
        self.frame_count += 1
        if self.frame_count % self.process_every_n_frames != 0:
            return

        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'cv_bridge error: {e}')
            return

        rects, _ = self.hog.detectMultiScale(
            frame,
            winStride=(4, 8),
            padding=(8, 8),
            scale=1.05
        )

        # NMS para quitar duplicados
        rects = self.non_max_suppression(rects, overlapThresh=0.5)

        # Filtrar cajas pequeñas
        filtered = []
        for (x, y, w, h) in rects:
            if w >= 60 and h >= 120:
                filtered.append((x, y, w, h))

        rects = filtered

        detections = []
        for (x, y, w, h) in rects:
            detections.append(((x, y, w, h), 1.0))

        updated_tracks = {}
        used_detection_indices = set()

        # Match por IoU
        for track_id, track_data in self.tracks.items():
            best_iou = 0.0
            best_idx = -1

            for idx, (det_box, _) in enumerate(detections):
                if idx in used_detection_indices:
                    continue

                score_iou = iou(track_data['bbox'], det_box)
                if score_iou > best_iou:
                    best_iou = score_iou
                    best_idx = idx

            if best_idx >= 0 and best_iou > 0.3:
                det_box, _ = detections[best_idx]
                used_detection_indices.add(best_idx)
                updated_tracks[track_id] = {'bbox': det_box, 'missed': 0}
            else:
                missed = track_data['missed'] + 1
                if missed <= self.max_missed:
                    updated_tracks[track_id] = {'bbox': track_data['bbox'], 'missed': missed}

        # Nuevas detecciones
        for idx, (det_box, _) in enumerate(detections):
            if idx not in used_detection_indices:
                updated_tracks[self.next_id] = {'bbox': det_box, 'missed': 0}
                self.next_id += 1

        self.tracks = updated_tracks

        out = TrackedPersonArray()
        for track_id, track_data in self.tracks.items():
            x, y, w, h = track_data['bbox']

            person = TrackedPerson()
            person.id = track_id
            person.cx = float(x + w / 2.0) / float(frame.shape[1])
            person.cy = float(y + h / 2.0) / float(frame.shape[0])
            person.width = float(w) / float(frame.shape[1])
            person.height = float(h) / float(frame.shape[0])
            person.score = 1.0

            out.persons.append(person)

        self.tracks_pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = PersonTrackerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
SHELL        := /bin/bash
PROJECT_DIR  := $(shell pwd)
ROS_SETUP    := source /opt/ros/humble/setup.bash
PKG_SETUP    := source $(PROJECT_DIR)/install/setup.bash

# ─── Build ─────────────────────────────────────────────────────────────────────

.PHONY: build
build:
	$(ROS_SETUP) && cd $(PROJECT_DIR) && colcon build && $(PKG_SETUP)

.PHONY: clean
clean:
	rm -rf $(PROJECT_DIR)/build $(PROJECT_DIR)/install $(PROJECT_DIR)/log

# ─── Cameras ───────────────────────────────────────────────────────────────────

.PHONY: camera-c922
camera-c922:
	$(ROS_SETUP) && ros2 run v4l2_camera v4l2_camera_node \
		--ros-args -p video_device:=/dev/video2 -p image_size:=[640,480]

.PHONY: camera-facetime
camera-facetime:
	$(ROS_SETUP) && ros2 run v4l2_camera v4l2_camera_node \
		--ros-args -p video_device:=/dev/video0 -p image_size:=[640,480]

# ─── Nodes ─────────────────────────────────────────────────────────────────────

.PHONY: gesture
gesture:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run gesture_detector gesture_detector_node \
		--ros-args -p image_topic:=/image_raw

.PHONY: tracker
tracker:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run person_tracker person_tracker_node \
		--ros-args -p image_topic:=/image_raw

.PHONY: selector
selector:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run target_selector target_selector_node

.PHONY: controller
controller:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run follow_controller follow_controller_node

.PHONY: debug
debug:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run debug_visualizer debug_visualizer_node \
		--ros-args -p image_topic:=/image_raw

# ─── Help ──────────────────────────────────────────────────────────────────────

.PHONY: help
help:
	@echo ""
	@echo "  BUILD"
	@echo "    make build            Compilar todos los paquetes con colcon"
	@echo "    make clean            Borrar build/, install/ y log/"
	@echo ""
	@echo "  CÁMARA (abrir en terminal separada primero)"
	@echo "    make camera-c922      Cámara C922  (/dev/video2)"
	@echo "    make camera-facetime  Cámara FaceTime (/dev/video0)"
	@echo ""
	@echo "  NODOS (cada uno en su propia terminal)"
	@echo "    make gesture          gesture_detector_node"
	@echo "    make tracker          person_tracker_node"
	@echo "    make selector         target_selector_node"
	@echo "    make controller       follow_controller_node"
	@echo "    make debug            debug_visualizer_node"
	@echo ""

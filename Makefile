SHELL        := /bin/bash
PROJECT_DIR  := $(shell pwd)
# Dentro del contenedor la ruta es /opt/ros/humble/install/setup.bash (con install/)
ROS_SETUP    := source /opt/ros/humble/install/setup.bash
PKG_SETUP    := source $(PROJECT_DIR)/install/setup.bash
TB3_PARAMS   := $(PROJECT_DIR)/install/turtlebot3_node/share/turtlebot3_node/param/waffle.yaml

# ─── Build ─────────────────────────────────────────────────────────────────────

.PHONY: build
build:
	$(ROS_SETUP) && cd $(PROJECT_DIR) && colcon build --symlink-install && $(PKG_SETUP)

.PHONY: clean
clean:
	rm -rf $(PROJECT_DIR)/build $(PROJECT_DIR)/install $(PROJECT_DIR)/log

# ─── Hardware ──────────────────────────────────────────────────────────────────

.PHONY: camera
camera:
	$(ROS_SETUP) && ros2 run v4l2_camera v4l2_camera_node \
		--ros-args -p video_device:=/dev/video0 -p image_size:=[640,480]

.PHONY: lidar
lidar:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	ros2 run hls_lfcd_lds_driver hlds_laser_publisher \
		--ros-args -p port:=/dev/ttyUSB0 -p frame_id:=base_scan

.PHONY: robot
robot:
	$(ROS_SETUP) && $(PKG_SETUP) && \
	TURTLEBOT3_MODEL=waffle ros2 run turtlebot3_node turtlebot3_ros \
		--ros-args --params-file $(TB3_PARAMS)

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

.PHONY: stream
stream:
	$(ROS_SETUP) && $(PKG_SETUP) && python3 -u $(PROJECT_DIR)/tools/stream.py

# ─── Help ──────────────────────────────────────────────────────────────────────

.PHONY: help
help:
	@echo ""
	@echo "  BUILD"
	@echo "    make build       Compilar todos los paquetes con colcon"
	@echo "    make clean       Borrar build/, install/ y log/"
	@echo ""
	@echo "  HARDWARE (cada uno en su propia terminal)"
	@echo "    make camera      Camara C920 (/dev/video0)"
	@echo "    make lidar       LiDAR LDS-01 (/dev/ttyUSB0)"
	@echo "    make robot       Driver TurtleBot3 Waffle (OpenCR, /dev/ttyACM0)"
	@echo ""
	@echo "  NODOS (cada uno en su propia terminal)"
	@echo "    make gesture     gesture_detector_node"
	@echo "    make tracker     person_tracker_node"
	@echo "    make selector    target_selector_node"
	@echo "    make controller  follow_controller_node  (EL ROBOT SE MUEVE)"
	@echo "    make debug       debug_visualizer_node   (necesita pantalla)"
	@echo "    make stream      Streamer MJPEG de debug en :8080"
	@echo ""
	@echo "  TODO JUNTO (desde el host de la Jetson, no dentro del contenedor)"
	@echo "    ./scripts/start_robot.sh            Lanza el sistema completo"
	@echo "    ./scripts/start_robot.sh --no-move  Sin controlador (robot quieto)"
	@echo "    ./scripts/stop_robot.sh             Parada de emergencia"
	@echo ""

#!/bin/bash
# Arranque completo del funny-robot (TurtleBot3 Waffle + Jetson Nano).
#
# Se ejecuta EN LA JETSON (host), no dentro del contenedor: lanza cada nodo
# dentro del contenedor `funny-robot` con `docker exec -d`.
#
# Los nodos se lanzan con AUTO-RESTART: si alguno crashea (p.ej. el fallo
# intermitente de GPU/EGL de MediaPipe) revive solo en ~2 s.
#
# Uso:
#   ./start_robot.sh            lanza todo (el robot puede moverse)
#   ./start_robot.sh --no-move  todo menos follow_controller (robot quieto)
set -e

CONTAINER=funny-robot
WS=/workspace

echo "== Autorizar X para el EGL de MediaPipe =="
# MediaPipe necesita un display X activo para acelerar por GPU.
DISPLAY=:0 XAUTHORITY=/run/user/1000/gdm/Xauthority xhost +local: >/dev/null 2>&1 || true

echo "== Contenedor =="
docker start $CONTAINER >/dev/null 2>&1 || true
sleep 2

echo "== Matar procesos previos =="
docker exec $CONTAINER bash -c '
  ps -eo pid,cmd | grep -E "ros2|_node|stream.py|v4l2|turtlebot3_ros|hlds|autorestart" \
    | grep -vE "grep|daemon" | awk "{print \$1}" | xargs -r kill -9
  sleep 2
' || true

# Lanza un comando dentro del contenedor con reinicio automatico si muere.
#   $1 = nombre del log   $2... = comando
run_node() {
  local log=$1; shift
  docker exec -d $CONTAINER bash -c "
    source /opt/ros/humble/install/setup.bash
    source $WS/install/setup.bash
    export TURTLEBOT3_MODEL=waffle
    echo autorestart-$log
    while true; do
      $* >> /tmp/$log.log 2>&1
      echo \"[\$(date)] $log murio (exit \$?), reiniciando en 2s...\" >> /tmp/$log.log
      sleep 2
    done"
}

echo "== 1/6 turtlebot3_node (Waffle) =="
run_node tb3 "ros2 run turtlebot3_node turtlebot3_ros --ros-args \
  --params-file $WS/install/turtlebot3_node/share/turtlebot3_node/param/waffle.yaml"
sleep 9   # calibracion del giroscopo

echo "== 2/6 LiDAR LDS-01 =="
run_node lidar "ros2 run hls_lfcd_lds_driver hlds_laser_publisher --ros-args \
  -p port:=/dev/ttyUSB0 -p frame_id:=base_scan"
sleep 4

echo "== 3/6 Camara C920 =="
run_node camera "ros2 run v4l2_camera v4l2_camera_node --ros-args \
  -p video_device:=/dev/video0 -p image_size:=[640,480]"
sleep 4

echo "== 4/6 Vision: gesture + tracker + selector =="
run_node gesture_detector "python3 -u $WS/install/gesture_detector/lib/gesture_detector/gesture_detector_node \
  --ros-args -p image_topic:=/image_raw"
sleep 1
run_node person_tracker "python3 -u $WS/install/person_tracker/lib/person_tracker/person_tracker_node \
  --ros-args -p image_topic:=/image_raw"
sleep 1
run_node target_selector "python3 -u $WS/install/target_selector/lib/target_selector/target_selector_node"
sleep 1

echo "== 5/6 Streamer de debug (:8080) =="
run_node stream "python3 -u $WS/tools/stream.py"
sleep 2

if [ "$1" != "--no-move" ]; then
  echo "== 6/6 follow_controller (EL ROBOT PUEDE MOVERSE) =="
  run_node controller "python3 -u $WS/install/follow_controller/lib/follow_controller/follow_controller_node"
else
  echo "== 6/6 follow_controller OMITIDO (--no-move) =="
fi

sleep 6
echo ""
echo "== Verificacion =="
docker exec $CONTAINER bash -c '
  source /opt/ros/humble/install/setup.bash
  export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
  timeout 5 ros2 topic info /cmd_vel 2>&1 | grep -E "Publisher|Subscription"'

IP=$(hostname -I | awk '{print $1}')
echo ""
echo "LISTO. Stream de debug: http://$IP:8080"
echo "Detener el robot:       ./stop_robot.sh"

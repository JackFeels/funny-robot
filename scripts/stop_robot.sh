#!/bin/bash
# Parada de emergencia: detiene el robot dejando el resto del sistema en pie.
#
# Mata el follow_controller (y su bucle de auto-restart) y ademas inunda
# /cmd_vel con ceros. Lo segundo es necesario porque el OpenCR RETIENE el
# ultimo comando recibido: sin un cero explicito el robot sigue moviendose.
#
# Nota: se usa kill normal (SIGTERM), no -9, para que el controlador alcance
# a publicar velocidad cero en su handler de cierre.
CONTAINER=funny-robot

docker exec $CONTAINER bash -c '
  ps -eo pid,cmd | grep -E "autorestart-controller|follow_controller_node" \
    | grep -v grep | awk "{print \$1}" | xargs -r kill
  sleep 1
  # Por si algun proceso sobrevivio al SIGTERM
  ps -eo pid,cmd | grep -E "autorestart-controller|follow_controller_node" \
    | grep -v grep | awk "{print \$1}" | xargs -r kill -9

  source /opt/ros/humble/install/setup.bash
  export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
  timeout 3 ros2 topic pub --rate 20 /cmd_vel geometry_msgs/Twist "{}" >/dev/null 2>&1
  echo "Robot detenido (motores en cero)."
'

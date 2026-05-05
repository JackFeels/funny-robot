import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jackfeels/Documents/PROYECTO_TURTLEBOT/install/gesture_detector'

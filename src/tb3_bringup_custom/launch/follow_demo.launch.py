from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gesture_detector',
            executable='gesture_detector_node',
            name='gesture_detector_node',
            parameters=[{'image_topic': '/camera/image_raw'}]
        ),
        Node(
            package='person_tracker',
            executable='person_tracker_node',
            name='person_tracker_node',
            parameters=[{'image_topic': '/camera/image_raw'}]
        ),
        Node(
            package='target_selector',
            executable='target_selector_node',
            name='target_selector_node'
        ),
        Node(
            package='follow_controller',
            executable='follow_controller_node',
            name='follow_controller_node'
        ),
        Node(
            package='debug_visualizer',
            executable='debug_visualizer_node',
            name='debug_visualizer_node',
            parameters=[{'image_topic': '/camera/image_raw'}]
        ),
    ])

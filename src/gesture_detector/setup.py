from setuptools import setup

package_name = 'gesture_detector'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='estudiante',
    maintainer_email='estudiante@udec.cl',
    description='Gesture detector node',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'gesture_detector_node = gesture_detector.gesture_detector_node:main',
        ],
    },
)

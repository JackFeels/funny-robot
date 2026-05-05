from setuptools import setup

package_name = 'debug_visualizer'

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
    description='Visualizador de debugging para proyecto TurtleBot',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'debug_visualizer_node = debug_visualizer.debug_visualizer_node:main',
        ],
    },
)
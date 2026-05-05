from setuptools import setup

package_name = 'target_selector'

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
    description='Target selector node',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'target_selector_node = target_selector.target_selector_node:main',
        ],
    },
)

from setuptools import find_packages
from setuptools import setup

setup(
    name='tb3_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('tb3_interfaces', 'tb3_interfaces.*')),
)

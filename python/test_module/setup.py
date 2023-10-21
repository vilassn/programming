from setuptools import setup, find_packages

setup(
    name='package',
    version='0.1',
    packages=find_packages(),
    install_requires=[
        'requests',
    ],
    entry_points={
        'console_scripts': [
            'my_script=my_package.my_module:main',
        ],
    },
)

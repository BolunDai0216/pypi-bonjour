from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "pypi_bonjour.common_cpp",
        ["pypi_bonjour/common_cpp.cpp"],
    ),
]

setup(ext_modules=ext_modules)

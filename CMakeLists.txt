cmake_minimum_required(VERSION 3.12)
project(pypi_bonjour)

# Find pybind11
find_package(pybind11 REQUIRED)

# Set up the Python module for common_cpp_cmake
pybind11_add_module(common_cpp_cmake pypi_bonjour/common_cpp_cmake.cpp)
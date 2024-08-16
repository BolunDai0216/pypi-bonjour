#!/bin/bash

set -e

# remove caches
rm -rf build/
rm -rf /tmp/cibuildwheel/

# install pybind11
pip install "pybind11[global]"
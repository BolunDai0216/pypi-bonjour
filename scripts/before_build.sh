#!/bin/bash

set -e

# upgrade pip
python -m pip install -U pip

# remove caches
rm -rf build/
rm -rf /tmp/cibuildwheel/

# install pybind11
pip install "pybind11[global]"

# install dependencies
pip install cmeel-assimp cmeel-octomap cmeel-qhull pin[build]
# Tutorial

This tutorial is a step-by-step guide on how to publish a Python package to PyPI. The package is called `pypi-bonjour`.

## Step 1: Create a Python package

Create a Python package with the following structure:

```bash
pypi-bonjour/
├── pypi_bonjour/
│   ├── __init__.py
│   └── common.py
├── .gitignore
├── LICENSE
├── README.md
└── pyproject.toml
```

The `pyproject.toml` file enables the `pip install` of the package. Then, to push the package to PyPI, you need to create a PyPI account and get the API token. Once that is done you can run 

```bash
python3 -m build
twine upload dist/*
```

which builds the source distribution and a pure Python wheel (not platform specific) and uploads them to PyPI.

## Step 2: Add dependencies

Add NumPy as one of the dependencies. This can be done by adding the following line to the `pyproject.toml` file:

```toml
[build-system]
...
dependencies = ["numpy>=1.26.4"]
...
```

Then, run the following command to build the source distribution and a pure Python wheel and upload them to PyPI:

```bash
python3 -m build
twine upload dist/*
```

## Step 3: Add C++ projects that are built by CMake

Add C++ projects that are built by CMake. The code for this function and creating the Python bindings is

```cpp
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>

namespace py = pybind11;

// Function to add two Eigen vectors
Eigen::VectorXd add_vectors(const Eigen::VectorXd &vec1, const Eigen::VectorXd &vec2)
{
    return vec1 + vec2;
}

PYBIND11_MODULE(common_cpp_cmake, m)
{
    m.def("add_vectors", &add_vectors, "Add two Eigen vectors",
          py::arg("vec1"), py::arg("vec2"));
}
```

The Python bindings are created by the following `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.12)
project(pypi_bonjour)

# Find pybind11
find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

# Set up the Python module for common_cpp_cmake
pybind11_add_module(common_cpp_cmake pypi_bonjour/common_cpp_cmake.cpp)
target_link_libraries(common_cpp_cmake PRIVATE Eigen3::Eigen)
```

The `setup.py` file is updated according to the [official `pybind11` + `cmake` example](https://github.com/pybind/cmake_example/blob/master/setup.py). No need to change this at all, just need to copy it to your `setup.py` file.

You also need to setup the `build-system` in the `pyproject.toml` file to use `pybind11`:

```toml
[build-system]
requires = ["setuptools >= 61.0.0", "pybind11 >= 2.10.0", "cmake", "wheel"]
build-backend = "setuptools.build_meta"
```

## Step 4: Build the wheels

To build the wheels for `CPython`, non-alpine Linux, `x86_64` and `aarch64` platforms, add the following command to the `pyproject.toml` file:

```toml
[tool.cibuildwheel]
archs = "x86_64 aarch64"  # build only for x86_64 and aarch64
before-all = "bash scripts/before_all.sh"
before-build = "bash scripts/before_build.sh"
manylinux-aarch64-image = "quay.io/pypa/manylinux_2_28_aarch64"  # it's still CentOS :(
manylinux-x86_64-image = "quay.io/pypa/manylinux_2_28_x86_64"  # it's still CentOS :(
skip = "pp* *musllinux*"  # skip building for PyPy and musllinux
```

Then, run `cibuildwheel` in the root directory. These commands will generate the built distributions in the `wheelhouse` directory, which can then be uploaded to PyPI using the command

```bash
twine upload wheelhouse/*
```

Note that the source distribution (only the source code) is still missing. To generate it and upload it to PyPI, run the commands

```bash
python3 -m build --sdist
twine upload dist/*
```

## Step 5: cibuildwheel with GitHub Actions

To automate the build and publish to PyPI process, you can use GitHub Actions. For details see [`build_publish_pypi.yml`](../../.github/workflows/build_publish_pypi.yml).


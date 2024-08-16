# $\texttt{PyPI-Bonjour}$ 🥖

<a href="https://github.com/BolunDai0216/pypi-bonjour/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-MIT-cfd8dc?style=flat-square&labelColor=orange&color=lightgray" alt="License"/></a>
<a href="https://badge.fury.io/py/pypi-bonjour"><img src="https://img.shields.io/pypi/v/pypi-bonjour?style=flat-square&labelColor=darkorange&color=lightgray" alt="pypi version"></a>

Tutorial on publishing to PyPI.

## Tutorial

The `pypi-bonjour` package gradually adds more functionality over different versions.

### v0.0.1: the hello-world example

This version publishes the barebone skeleton code to `pypi`, which includes:

- the source code with the single pure Python function `hello_world` (in contrast with pybinded functions)
- a `pyproject.toml` file for enabling `pip install` of the package
- the GitHub workflow that publishes the package to `pypi` upon release publish

See this [video](https://youtu.be/J0ClmuAbiMA?si=83Xe7eJW5LNUr5yP) by Prof.Qiusheng Wu for an introduction to PyPI packaging.

### v0.0.2: add dependencies

This version adds NumPy as one of the dependencies.

### v0.0.3: add pybind11-binded C++ function

This version adds a function that is `pybind11`-binded from C++ from Python without the use of CMake. See [here](https://pybind11.readthedocs.io/en/stable/compiling.html#modules-with-setuptools) for an intro regarding using `pybind11` with `setuptools`.

See this [video](https://youtu.be/80j-MRtHMek?si=f-o5LCoFGKja3P59) by anthonywritescode for an introduction to `manylinux`. Building these `manylinux` wheels requires the installation of a docker image and building the wheels inside that docker image. This process is automated by `cibuildwheel`. Furthermore, to enable the build for different architectures on a computer, one should download QEMU for architecture emulation

```bash
python3 -m pip install cibuildwheel
sudo apt-get install qemu-system  # for Ubuntu, see https://www.qemu.org/download for more details
```

To build the wheels only for `CPython` (what is `PyPy`...), non-alpine Linux (what is `musllinux`...), `x86_64` and `aarch64` platforms use the following command:

```bash
export CIBW_SKIP="pp* *musllinux*"
export CIBW_ARCHS="x86_64 aarch64"
cibuildwheel
```

These can also be added to the `pyproject.toml` file 

```toml
[tool.cibuildwheel]
skip = "pp* *musllinux*"
archs = "x86_64 aarch64" 
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

The final result is [here](https://pypi.org/project/pypi-bonjour/0.0.3/#files). Note that the GitHub actions are not setup yet, so the action that this release triggered did not successfully upload the wheels to PyPI.

### v0.0.4: added build and publish to PyPI GitHub workflow

For details see [`build_publish_pypi.yml`](.github/workflows/build_publish_pypi.yml).

### v0.0.5: added C++ projects that are built by CMake

Added a `CMakeLists.txt` file to build the Python bindings using `pybind11` and `cmake`. The `setup.py` file is updated according to the [official `pybind11` + `cmake` example](https://github.com/pybind/cmake_example/blob/master/setup.py), if you prefer a video that goes through this process see [this one](https://youtu.be/H2wOlriHGmM?si=lF9kVxETq_msUT7a) by Facile Tutorials.

### v0.0.6: added external C++ dependencies

Added functions that uses `Eigen`. This involves installing `Eigen` in the `CIBW_BEFORE_ALL` script. However, there are certain limitations to CentOS [that needs to be taken cared of](https://stackoverflow.com/questions/74345206/centos-7-docker-yum-installation-gets-stuck).

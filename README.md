# pypi-bonjour

Tutorial on publishing to PyPI.

## Tutorial

The `pypi-bonjour` package gradually adds more functionality over different versions.

### v0.0.1: the hello-world example

This version publishes the barebone skeleton code to `pypi` which includes:

- the source code with the single pure Python function `hello_world` (in contrast with pybinded functions)
- a `pyproject.toml` file for enabling `pip install` of the package
- the GitHub workflow that publishes the package to `pypi` upon release publish

See this [video](https://youtu.be/J0ClmuAbiMA?si=83Xe7eJW5LNUr5yP) by Prof.Qiusheng Wu for an intro to PyPI packaging.

### v0.0.2: add dependencies

This version adds NumPy as one of the dependencies.

### v0.0.3: add pybind11-binded C++ function

This version adds a function that is `pybind11`-binded from C++ from Python without the use of CMake. See [here](https://pybind11.readthedocs.io/en/stable/compiling.html#modules-with-setuptools) for an intro regarding using `pybind11` with `setuptools`.

See this [video](https://youtu.be/80j-MRtHMek?si=f-o5LCoFGKja3P59) by anthonywritescode for an introduction to `manylinux`.
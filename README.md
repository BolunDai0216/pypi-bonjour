# pypi-bonjour

Tutorial on publishing to PyPI.

## Tutorial

The `pypi-bonjour` package gradually adds more functionality over different versions.

### v0.0.1: the hello-world example

This version publishes the barebone skeleton code to `pypi` which includes:

- the source code with the single pure Python function `hello_world` (in contrast with pybinded functions)
- a `pyproject.toml` file for enabling `pip install` of the package
- the GitHub workflow that publishes the package to `pypi` upon release publish

See this [video](https://youtu.be/J0ClmuAbiMA?si=83Xe7eJW5LNUr5yP) by Prof.Qiusheng Wu for an introduction to PyPI packaging.

### v0.0.2: add dependencies

This version adds NumPy as one of the dependencies.

### v0.0.3: add pybind11-binded C++ function

This version adds a function that is `pybind11`-binded from C++ from Python without the use of CMake. See [here](https://pybind11.readthedocs.io/en/stable/compiling.html#modules-with-setuptools) for an intro regarding using `pybind11` with `setuptools`.

See this [video](https://youtu.be/80j-MRtHMek?si=f-o5LCoFGKja3P59) by anthonywritescode for an introduction to `manylinux`.

To build the wheels only for `CPython` (what is `PyPy`...), non alpine linux (what is `musllinux`...), `x86_64` and `aarch64` platforms use the following command:

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

then running `cibuildwheel` in the root directory. These commands will generate the built distributions in the `wheelhouse` directory, which can then be uploaded to PyPI using the command

```bash
twine upload wheelhouse/*
```

Note that the source distribution (only the source code) is still missing, to generate it and upload it to PyPI run the commands

```bash
python3 -m build --sdist
twine upload dist/*
```

The final result is [here](https://pypi.org/project/pypi-bonjour/0.0.3/#files).
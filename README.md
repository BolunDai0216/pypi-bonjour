# pypi-bonjour

Tutorial on publishing to PyPI.

## Tutorial

The `pypi-bonjour` package gradually adds more functionality over different versions.

### v0.0.1: the hello-world example

This version publishes the barebone skeleton code to `pypi` which includes:

- the source code with the single pure Python function `hello_world` (in contrast with pybinded functions)
- a `pyproject.toml` file for enabling `pip install` of the package
- the GitHub workflow that publishes the package to `pypi` upon release publish

### v0.0.2: add dependencies

This version adds NumPy as one of the dependencies.
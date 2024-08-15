"""The common module contains common functions and classes used by the other modules.
"""


def hello_world() -> None:
    """Prints "Hello World!" to the console."""
    print("Hello World!")


def numpy_hello_world() -> float:
    """Prints "Hello World!" to the console using numpy."""
    import numpy as np

    random_number = np.random.rand()
    print(random_number)

    return random_number

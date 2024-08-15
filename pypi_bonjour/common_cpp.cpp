#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

std::string greet()
{
    return "Hello, World!";
}

PYBIND11_MODULE(common_cpp, m)
{
    m.def("greet", &greet, "A function that returns a hello world message");
}
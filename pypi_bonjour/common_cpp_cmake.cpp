#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

std::string greet_cmake()
{
    return "Hello, World! (from CMake)";
}

PYBIND11_MODULE(common_cpp_cmake, m)
{
    m.def("greet_cmake", &greet_cmake, "A function that returns a hello world message");
}
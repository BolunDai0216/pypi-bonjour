#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>

#include <string>

namespace py = pybind11;

std::string greet_cmake()
{
    return "Hello, World! (from CMake)";
}

// Function to add two Eigen vectors
Eigen::VectorXd add_vectors(const Eigen::VectorXd &vec1, const Eigen::VectorXd &vec2)
{
    return vec1 + vec2;
}

PYBIND11_MODULE(common_cpp_cmake, m)
{
    m.def("greet_cmake", &greet_cmake, "A function that returns a hello world message");
    m.def("add_vectors", &add_vectors, "Add two Eigen vectors",
          py::arg("vec1"), py::arg("vec2"));
}
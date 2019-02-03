#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

class Pet{
public:
	Pet(py::array_t<unsigned char> input1){
		m_data = input1;
	}
	unsigned char get_elem(int idy, int idx){
		py::buffer_info buf1 = m_data.request();
		auto ptr1 = (unsigned char *) buf1.ptr;
		size_t w = buf1.shape[1];
		return ptr1[idy*w+ idx];

	}
	py::array_t<unsigned char> m_data;
};

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: cmake_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";


	py::class_<Pet>(m, "Pet")
		.def(py::init<py::array_t<unsigned char>>())
		.def("get_elem", &Pet::get_elem);


    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}

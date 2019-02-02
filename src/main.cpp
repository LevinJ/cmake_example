#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

class Pet{
public:
	Pet(py::array_t<int> input1){
		m_data = input1;
	}
	int get(int idx, int idy){
		py::buffer_info buf1 = m_data.request();
		int *ptr1 = (int *) buf1.ptr;
		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];
		return ptr1[idx*Y+ idy];

	}
	py::array_t<int> m_data;
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
		.def(py::init<py::array_t<int>>())
		.def("get", &Pet::get);


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

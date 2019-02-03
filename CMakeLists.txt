cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

message("PYTHON_INCLUDE_DIRS=" ${PYTHON_INCLUDE_DIRS})
message("PYTHON_LIBRARIES=" ${PYTHON_LIBRARIES})
add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/main.cpp)

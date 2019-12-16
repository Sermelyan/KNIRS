cmake_minimum_required(VERSION 3.15)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_library(list_cpp cpp/ListGraph.cpp)
add_library(matrix_cpp cpp/MatrixGraph.cpp)
add_library(matrixrp_cpp cpp/MatrixRPGraph.cpp)
add_library(set_cpp cpp/SetGraph.cpp)
add_library(arc_cpp cpp/ArcGraph.cpp)

add_library(utils_c c/utils.c)
add_library(matrix_c c/matrix_graph.c)
target_link_libraries(matrix_c utils)

add_executable(test test.cpp)
target_link_libraries(test list_cpp matrix_cpp matrixrp_cpp set_cpp arc_cpp utils_c gtest)
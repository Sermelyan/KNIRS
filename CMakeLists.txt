cmake_minimum_required(VERSION 3.3)
project(graph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

include_directories(cpp/include)
include_directories(c/include)

add_library(list_cpp cpp/src/ListGraph.cpp)
add_library(matrix_cpp cpp/src/MatrixGraph.cpp)
add_library(matrixrp_cpp cpp/src/MatrixRPGraph.cpp)
add_library(set_cpp cpp/src/SetGraph.cpp)
add_library(uset_cpp cpp/src/UnorderedSetGraph.cpp)
add_library(arc_cpp cpp/src/ArcGraph.cpp)

add_library(utils_c c/src/utils.c)
add_library(matrix_c c/src/matrix_graph.c)
target_link_libraries(matrix_c utils_c)
add_library(list_c c/src/list_graph.c)
target_link_libraries(list_c utils_c)
add_library(arc_c c/src/arc_graph.c)
target_link_libraries(arc_c utils_c)

add_executable(cpp_graph_unit_test tests/cpp_graph_unit_test.cpp)
target_link_libraries(cpp_graph_unit_test list_cpp matrix_cpp matrixrp_cpp set_cpp uset_cpp arc_cpp gtest)

add_executable(c_graph_unit_test tests/c_graph_unit_test.cpp)
target_link_libraries(c_graph_unit_test matrix_c list_c arc_c utils_c gtest)

add_executable(c_vector_test tests/c_vector_test.cpp)
target_link_libraries(c_vector_test utils_c gtest)

add_executable(cpp_set_test tests/cpp_set_test.cpp)
target_link_libraries(cpp_set_test set_cpp uset_cpp list_cpp gtest)
cmake_minimum_required(VERSION 3.15)
project(KNIRS_heap)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(heap_node_c STATIC src/heap_node.c)

add_executable(test test/test.cpp)
target_link_libraries(test heap_node_c)
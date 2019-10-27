cmake_minimum_required(VERSION 3.15)
project(KNIRS_heap)

# if work with c++
set(CMAKE_CXX_STANDARD 17)
# if work with c
set(CMAKE_C_STANDARD 11)

include_directories(include)

# Оставить ту библиотеку, которую реализуете

add_library(heap_array_c STATIC src/heap_array.c)

add_library(heap_node_c STATIC src/heap_node.c)

add_library(heap_array_cpp STATIC src/heap_array.cpp)

add_library(heap_node_cpp STATIC src/heap_node.cpp)

# Нужен для локального тестирования(для вас, проверить работает ли код)
add_executable(test src/test.cpp)
# Оставить только ту библиотеку, которую реализуйте
target_link_libraries(test heap_array_c heap_node_c heap_array_cpp heap_node_cpp)
cmake_minimum_required(VERSION 2.8)
project(algorithm_solving)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(combinations combinations/main.cpp)
target_link_libraries(combinations pthread)

add_executable(div_and_conq_quad_tree div_and_conq_quad_tree/main.cpp)

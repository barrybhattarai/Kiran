cmake_minimum_required(VERSION 3.21)
project(Sage)

set(CMAKE_CXX_STANDARD 17)
link_directories(lib)
include_directories(include)
add_executable(Sage main.cpp glad.c)
target_link_libraries(Sage glfw3)


cmake_minimum_required(VERSION 3.6)
project(A2_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp my_vector.h payload.cpp payload.h)
add_executable(A2_2 ${SOURCE_FILES})
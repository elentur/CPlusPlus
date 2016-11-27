cmake_minimum_required(VERSION 3.2)

project(A2_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp payload.cpp test21.cpp vector.h)
add_executable(test_it ${SOURCE_FILES})
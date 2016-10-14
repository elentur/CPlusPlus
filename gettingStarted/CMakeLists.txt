cmake_minimum_required(VERSION 3.5)
project(A0_Getting_Started)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp x.cpp x.h y.cpp y.h)
add_executable(A0_Getting_Started ${SOURCE_FILES})
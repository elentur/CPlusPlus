cmake_minimum_required(VERSION 3.6)
project(A1_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vec3f.cpp Vec3f.h test11.h test11.cpp)
add_executable(A1_1 ${SOURCE_FILES})
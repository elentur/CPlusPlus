cmake_minimum_required(VERSION 3.6)
project(A1_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vec.h test11.h test11.cpp testGen.h )
add_executable(A1_2 ${SOURCE_FILES})
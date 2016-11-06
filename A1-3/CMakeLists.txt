cmake_minimum_required(VERSION 3.6)
project(A1_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vec.h Mat.h util.h test11.h test11.cpp testMat.h testGen.h)
add_executable(A1_3 ${SOURCE_FILES})
#pragma once

#include "Vec.h"
#include "Mat.h"

using namespace my;


template<typename T, int N>
void to_string(Vec<T, N> vec){
    std::cout << "[";
    if (N > 0)
        std::cout << vec[0];

    for (int i = 1; i < N; i++) {
        std::cout << ", " << vec[i];
    }
    std::cout << "]";
};

template<typename T, int N>
void to_string(Mat<T, N> mat){
    std::cout << "[";
    if (N > 0)
        std::cout << mat[0];

    for (int i = 1; i < N; i++) {
        std::cout << std::endl << mat[i];
    }
    std::cout << "]";
};

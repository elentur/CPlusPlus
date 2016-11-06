#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "Vec.h"
#include "Mat.h"

/**
 * Takes a vector and transforms it in a readable format
 * @param v - vector to transform
 * @param width - sets the width parameter of the stream out to exactly number.
 * @param decimals - sets the precision parameter of the stream out to exactly number
 * @return std::string
 */
template<typename T, int N>
std::string vek_to_string(my::Vec<T, N> v, int width = 1, int decimals = 0) {
    std::ostringstream s;
    s << " |";
    for (int i = 0; i < N; i++) {
        s << " " << std::fixed << std::setw(width) << std::setprecision(decimals) << v[i];
    }
    s << " |" << std::endl;
    return s.str();
}

/**
 * Takes a matrix and transforms it in a readable format with its width and decimal precision.
 * @param m - matrix to transform
 * @param width - sets the width parameter of the stream out to exactly number.
 * @param decimals - sets the precision parameter of the stream out to exactly number
 * @return std::string
 */
template<typename T, int N>
std::string to_string(my::Mat<T, N> m, int width = 1, int decimals = 0) {
    std::ostringstream s;

    s << " Matrix(" << typeid(T).name() << " " << N << " * " << N << ") width: " << width << " decimals: " << decimals
      << std::endl;
    for (int i = 0; i < N; i++) {
        s << vek_to_string(m[i],width,decimals);
    }
    std::string ss = s.str();

    return ss;
}

/**
 * Takes a vector and converts it into a readable format with its width and decimal precision.
 * @param v - vector to transform
 * @param width - sets the width parameter of the stream out to exactly number.
 * @param decimals - sets the precision parameter of the stream out to exactly number
 * @return std::string
 */
template<typename T, int N>
std::string to_string(my::Vec<T, N> v, int width = 1, int decimals = 0) {
    std::ostringstream s;

    s << " Vector(" << typeid(T).name() << " " << N << ")" << " width: " << width << " decimals: " << decimals
      << std::endl;
    s << vek_to_string(v,width,decimals);

    return s.str();
}


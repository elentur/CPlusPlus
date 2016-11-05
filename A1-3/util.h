#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "Vec.h"
#include "Mat.h"

template <typename T, int N>
std::string to_string(my::Mat<T,N> m, int width = 1 , int decimals = 0)
{
    std::ostringstream s;
    
    s << "Matrix(" << typeid(T).name() << " " << N << " * " << N << ") width: " << width << " decimals: " << decimals <<std::endl;
    for (int i = 0; i < N; i++)
    {
    s << vek_to_string(m[i]) ;
    }
    std::string ss =  s.str();
    
    return ss ;
}
template <typename T, int N>
std::string to_string(my::Vec<T,N> v, int width = 1 , int decimals = 0)
{
    std::ostringstream s;
    s << "Vector(" << typeid(T).name() << " " << N << ")" << "width: " << width << " decimals: " << decimals <<std::endl;
    s << vek_to_string(v);
    return s.str();
}
template <typename T, int N>
std::string vek_to_string(my::Vec<T,N> v, int width = 1 , int decimals = 0)
{
    std::ostringstream s;
    s << "|";
    for (int i = 0; i < N; i++)
    {
    s << " "  << std::fixed << std::setw(width) << std::setprecision(decimals) << v[i];
    }
    s << " |" << std::endl;
    return s.str();
}

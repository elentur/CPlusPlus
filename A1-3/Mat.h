#include <array>
#include <iostream>
#include <cassert>
#include "vec.h"

#pragma once

namespace my
{
/**
       Represents a Matrix object with N * N dimensions and the valuetype T
       overloaded operators are ==, != , *, unary -, << for toString usage and
       the static method entity for the entity matrix.
    */
template <typename T = float, int N = 3>
class Mat
{
  public:
    Mat();
    Mat(std::initializer_list<Vec<T,N>> const &l);
    /**
        represents the value typ of Mat<T,N> 
        */
    using value_type = T;
    /**
        represent the number of dimensions of Mat
        */
    static constexpr int dimension = N;
    /**
        returns a entity matrix
    */
    static Mat<T,N> Mat<T,N>::entity()
    {
        Mat<T,N> m;
        for ( int  i = 0; i < N; i++)
        {
            m[i][i]=1;
        }
        return m;
    }
    /**
        Overloading operator [] for reading purpose
        */
    Vec<T,N> operator[](std::size_t index) const;
    /**
        Overloading operator [] for writing purpose
        */
    Vec<T,N> &operator[](std::size_t index);

  private:
    /**
       mArgs represents the Mat N *N as 
       an array of size N of typ T
        */
    std::array<Vec<T, N>,N> mArgs;
};
/**
        Constructors of Mat
    */
template <typename T, int N>
Mat<T, N>::Mat() : mArgs(std::array<Vec<T, N>,N>{})
{
}

template <typename T, int N>
Mat<T, N>::Mat(std::initializer_list<Vec<T,N>> const &l) : mArgs(std::array<Vec<T, N>,N>{})
{
    assert(l.size() == N);
    std::copy_n(l.begin(), N, mArgs.begin());
}

//   Overloading operator [] for reading purpose
template <typename T, int N>
Vec<T,N> Mat<T, N>::operator[](std::size_t index) const
{
    if (index >= dimension)
    {
        std::cout << "index out of bounds";
        exit(0);
    }
    return mArgs[index];
}

//  Overloading operator [] for writing purpose
template <typename T, int N>
Vec<T,N> &Mat<T, N>::operator[](std::size_t index)
{
    if (index >= dimension)
    {
        std::cout << "index out of bounds";
        exit(0);
    }
    return mArgs[index];
}

//  Overloading operator << for toString usage
template <typename T, int N>
std::ostream &operator<<(std::ostream &lhs, Mat<T, N> rhs)
{

    lhs << "[";
    if (N > 0)
        lhs << rhs[0];

    for (int i = 1; i < N; i++)
    {
        lhs  << std::endl << rhs[i];
    }
    lhs << "]";
    return lhs;
}

//  Overloading operator ==
template <typename T, int N>
bool operator==(const Mat<T,N> &lhs, const Mat<T,N> &rhs)
{
    
    for (int i = 1; i < N; i++)
    {
       if( lhs[i] != rhs[i] ) return false;
    }
    return true;
}

//  Overloading operator !=
template <typename T, int N>
bool operator!=(const Mat<T,N> &lhs, const Mat<T,N> &rhs)
{
    return !(lhs == rhs);
}

//Overloading unary operator -
template <typename T, int N> 
Mat<T,N> operator-(const Mat<T,N> &rhs)
{
    Mat<T,N> newMat;
     for(int i = 0; i <N ; i++)
     {
         newMat[i] = -rhs[i];
     }
    return newMat;
}
// overloading the operator * for Mat<T,N> * Vec<T,N>
template <typename T, int N>
Vec<T,N> operator*(const Mat<T,N> &lhs, const Vec<T,N> &rhs)
{
     Vec<T,N> value;
     for(int i = 0; i <N ; i++)
     {
         value[i] = dot(lhs[i], rhs);
     }
    return value;
}
// overloading the operator * for Mat<T,N> * Mat<T,N>
template <typename T, int N>
Mat<T,N> operator*(const Mat<T,N> &lhs, const Mat<T,N> &rhs)
{
    Mat<T,N> value;
     for(int i = 0; i <N ; i++)
     {
         value[i] = lhs*rhs[i];
     }
    return value;
}
}
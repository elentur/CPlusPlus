#include <array>
#include <iostream>
#include <cassert>
#include <algorithm>

#pragma once

namespace my {
/**
       Represents a Vector object with 3 dimensions and the valuetype T
       overloaded operators are ==, != , +=, +, unary -, << for toString usage
       also the function dot for calclating the dot product of 2 Vec<T,N> objects
    */
    template<typename T = float, int N = 3>
    class Vec {
    public:
        Vec();

        Vec(std::initializer_list<T> const &l);
        /**
            represents the value typ of Vec<T,N>
            */
        using value_type = T;
        /**
            represent the number of dimensions of Vec
            */
        static constexpr int dimension = N;

        /**
            Overloading operator [] for reading purpose
            */
        T operator[](std::size_t index) const;

        /**
            Overloading operator [] for writing purpose
            */
        T &operator[](std::size_t index);

    private:
        /**
           mArgs represents the vector 3 as
           an array of size 3 of typ T
            */
        std::array<T, N> mArgs;
    };

/**
        Constructors of Vec
    */
    template<typename T, int N>
    Vec<T, N>::Vec() : mArgs(std::array<T, N>{}) {
    }

    template<typename T, int N>
    Vec<T, N>::Vec(std::initializer_list<T> const &l) : mArgs(std::array<T, N>{}) {
        assert(l.size() == N);
        std::copy_n(l.begin(), N, mArgs.begin());
    }

//   Overloading operator [] for reading purpose
    template<typename T, int N>
    T Vec<T, N>::operator[](std::size_t index) const {
        if (index >= dimension) {
            std::cout << "index out of bounds";
            exit(0);
        }
        return mArgs[index];
    }

//  Overloading operator [] for writing purpose
    template<typename T, int N>
    T &Vec<T, N>::operator[](std::size_t index) {
        if (index >= dimension) {
            std::cout << "index out of bounds";
            exit(0);
        }
        return mArgs[index];
    }

//  Overloading operator << for toString usage
    template<typename T, int N>
    std::ostream &operator<<(std::ostream &lhs, Vec<T, N> rhs) {

        lhs << "[";
        if (N > 0)
            lhs << rhs[0];

        for (int i = 1; i < N; i++) {
            lhs << ", " << rhs[i];
        }
        lhs << "]";
        return lhs;
    }

//  Overloading operator ==
    template<typename T, int N>
    bool operator==(const Vec<T, N> &lhs, const Vec<T, N> &rhs) {

        for (int i = 1; i < N; i++) {
            if (lhs[i] != rhs[i]) return false;
        }
        return true;
    }

//  Overloading operator !=
    template<typename T, int N>
    bool operator!=(const Vec<T, N> &lhs, const Vec<T, N> &rhs) {
        return !(lhs == rhs);
    }

    //   Overloading operator +=
    template<typename T, int N>
    Vec<T, N> &operator+=(Vec<T, N> &lhs, const Vec<T, N> &rhs) {
        for (int i = 0; i < N; i++) {
            lhs[i] = lhs[i] + rhs[i];
        }
        return lhs;
    }

//  Overloading operator +
    template<typename T, int N>
    Vec<T, N> operator+(Vec<T, N> lhs, const Vec<T, N> &rhs) {
        return lhs += rhs;
    }

//Overloading unary operator -
    template<typename T, int N>
    Vec<T, N> operator-(const Vec<T, N> &rhs) {
        Vec<T, N> newVec;
        for (int i = 0; i < N; i++) {
            newVec[i] = -rhs[i];
        }
        return newVec;
    }

//dot function for vector3 returns scalar as T
    template<typename T, int N>
    T dot(const Vec<T, N> &lhs, const Vec<T, N> &rhs) {
        T value = 0;
        for (int i = 0; i < N; i++) {
            value += lhs[i] * rhs[i];
        }
        return value;
    }
}
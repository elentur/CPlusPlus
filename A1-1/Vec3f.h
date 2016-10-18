//
// Created by roberto on 17.10.16.
//
#include <array>
#include <iostream>


#pragma once

namespace my {
    /**
       Represents a Vector object with 3 dimensions and the valuetype float
       overloaded operators are ==, != , +=, +, unary -, << for toString usage
       also the function dot for calclating the dot product of 2 Vec3f objects
    */
    class Vec3f {
    public:
        Vec3f();
        Vec3f(float x, float y, float z);
        Vec3f(std::array<float,3> args);
        /**
        represents the value typ of Vec3f 
        */
        using value_type = float;
        /**
        represent the number of dimensions of Vec3f
        */
        static constexpr int dimension=3;
        /**
        Overloading operator [] for reading purpose
        */
        float operator[](std::size_t index) const;
        /**
        Overloading operator [] for writing purpose
        */
        float& operator[](std::size_t index) ;
    private:
        /**
       mArgs represents the vector 3 as 
       an array of size 3 of typ float
        */ 
       std::array<float,3> mArgs;
    };

    
/**
        Overloading operator << for toString usage
*/
std::ostream& operator<<(std::ostream& lhs, Vec3f rhs);
/**
        Overloading operator == 
*/
bool operator==(const Vec3f& lhs, const Vec3f& rhs);
/**
        Overloading operator != 
*/
bool operator!=(const Vec3f& lhs, const Vec3f& rhs);
/**
        Overloading operator +=
*/
Vec3f& operator+=(Vec3f& lhs, const Vec3f& rhs);
/**
        Overloading operator +
*/
Vec3f operator+( Vec3f lhs, const Vec3f& rhs);
/**
        Overloading unary operator - 
*/
Vec3f operator-(const Vec3f& rhs);
/**
        dot function for vector3
        returns scalar as float
*/
float dot(const Vec3f& lhs, const Vec3f& rhs);
}


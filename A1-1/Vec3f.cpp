//
// Created by roberto on 17.10.16.
//

#include "Vec3f.h"
#include <iostream>

my::Vec3f::Vec3f() : mArgs(std::array<float,3>{0,0,0})
{

}

my::Vec3f::Vec3f(float x, float y, float z) : mArgs(std::array<float,3>{x,y,z}) 
{

}

my::Vec3f::Vec3f(std::array<float, 3> &args): mArgs(std::array<float,3>{args[0],args[1],args[2]}) 
{

}

float my::Vec3f::x() const {
    return mArgs[0];
}

float my::Vec3f::y() const {
    return mArgs[1];
}

float my::Vec3f::z() const {
    return mArgs[2];
}
 float  my::Vec3f::operator[]( std::size_t index) const{
    if(index >= dimension)
    {
        std::cout << "index out of bounds";
        exit(0);
    }
    return mArgs[index];
}
 float&  my::Vec3f::operator[]( std::size_t index) {
    if(index >= dimension)
    {
        std::cout << "index out of bounds";
        exit(0);
    }
    return mArgs[index];
}


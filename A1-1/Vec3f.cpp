//
// Created by roberto on 17.10.16.
//

#include "Vec3f.h"
#include <iostream>


namespace my{
    /**
        Constructors of Vec3f
    */
    my::Vec3f::Vec3f() : mArgs(std::array<float,3>{0,0,0})
    {

    }

    my::Vec3f::Vec3f(float x, float y, float z) : mArgs(std::array<float,3>{x,y,z}) 
    {

    }

    my::Vec3f::Vec3f(std::array<float, 3> args): mArgs(std::array<float,3>{args[0],args[1],args[2]}) 
    {

    }

    /**
        Overloading operator [] for reading purpose
    */
    float  my::Vec3f::operator[]( std::size_t index) const{
        if(index >= dimension)
        {
            std::cout << "index out of bounds";
            exit(0);
        }
        return mArgs[index];
    }
     /**
        Overloading operator [] for writing purpose
    */
    float&  my::Vec3f::operator[]( std::size_t index) {
        if(index >= dimension)
        {
            std::cout << "index out of bounds";
            exit(0);
        }
        return mArgs[index];
    }

    /**
        Overloading operator << for toString usage
    */
    std::ostream& operator<<(std::ostream& lhs, my::Vec3f rhs){
    return lhs << "[" << rhs.x() << "," << rhs.y() << "," << rhs.z() << "]";
    }

     /**
        Overloading operator == 
    */
    bool operator==(const my::Vec3f& lhs, const my::Vec3f& rhs)
    {
        return lhs[0]==rhs[0] && lhs[1]==rhs[1] && lhs[2]==rhs[2];
    }
    /**
        Overloading operator != 
    */
    bool operator!=(const my::Vec3f& lhs, const my::Vec3f& rhs)
    {
        return !(lhs==rhs);
    }
    /**
        Overloading operator +=
    */
    my::Vec3f& operator+=(my::Vec3f& lhs, const my::Vec3f& rhs)
    {
        lhs[0]=lhs[0]+rhs[0];
        lhs[1]=lhs[1]+rhs[1];
        lhs[2]=lhs[2]+rhs[2];
        return lhs;
    }
    /**
        Overloading operator +
    */
    my::Vec3f operator+( my::Vec3f lhs, const my::Vec3f& rhs)
    {
        return lhs+=rhs;
    }
    /**
        Overloading unary operator - 
    */
    my::Vec3f operator-(const my::Vec3f& rhs)
    {
        return my::Vec3f(-rhs[0],-rhs[1],-rhs[2]);
    }
    /**
        dot function for vector3
        returns scalar as float
    */
    float dot(const my::Vec3f& lhs, const my::Vec3f& rhs)
    {
        return lhs[0]*rhs[0] + lhs[1] *rhs[1] + lhs[2]*rhs[2];
    }
}
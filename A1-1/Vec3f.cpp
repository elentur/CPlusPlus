//
// Created by roberto on 17.10.16.
//

#include <iostream>
#include "Vec3f.h"

my::Vec3f::Vec3f() {
    Vec3f(0.f,0.f,0.f);
}

my::Vec3f::Vec3f(float x, float y, float z) : mArgs(std::array<float,3>{x,y,z}) {

}

my::Vec3f::Vec3f(std::array<float, 3> args) {
    Vec3f(args.at(0),args.at(1),args.at(2));
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


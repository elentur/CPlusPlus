//
// Created by roberto on 17.10.16.
//

#include "Vec3f.h"

Vec3::Vec3f::Vec3f() {
    Vec3f(0.f,0.f,0.f);
}

Vec3::Vec3f::Vec3f(float x, float y, float z) : mArgs(std::array<float,3>{x,y,z}) {

}

Vec3::Vec3f::Vec3f(std::array<float, 3> args) {
    Vec3f(args.at(0),args.at(1),args.at(2));
}

float Vec3::Vec3f::x() const {
    return mArgs[0];
}

float Vec3::Vec3f::y() const {
    return mArgs[1];
}

float Vec3::Vec3f::z() const {
    return mArgs[2];
}


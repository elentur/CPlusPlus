//
// Created by roberto on 17.10.16.
//

#include <iostream>
#include "Vec3f.h"

my::Vec3f::Vec3f() : mArgs(std::array<float, 3>{0, 0, 0}) {}

my::Vec3f::Vec3f(float x, float y, float z) : mArgs(std::array<float, 3>{x, y, z}) {}

my::Vec3f::Vec3f(std::array<float, 3> args) : mArgs(std::array<float, 3>{args.at(0), args.at(1), args.at(2)}) {}

bool my::operator==(const my::Vec3f &lhs, const my::Vec3f &rhs) {
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

bool my::operator!=(const my::Vec3f &lhs, const my::Vec3f &rhs) {
    return lhs[0] != rhs[0] || lhs[1] != rhs[1] || lhs[2] != rhs[2];
}


my::Vec3f my::operator+=(my::Vec3f &lhs, my::Vec3f rhs) {

    lhs[0] = lhs[0] + rhs[0];
    lhs[1] = lhs[1] + rhs[1];
    lhs[2] = lhs[2] + rhs[2];

    return lhs;
}


my::Vec3f my::operator+(my::Vec3f lhs, my::Vec3f rhs) {
    return lhs += rhs;
}

my::Vec3f my::operator-(my::Vec3f lhs) {

    lhs[0] = -lhs[0];
    lhs[1] = -lhs[1];
    lhs[2] = -lhs[2];

    return lhs;
}

float my::dot(const my::Vec3f &lhs, const my::Vec3f &rhs) {
    return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
}
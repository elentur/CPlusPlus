//
// Created by roberto on 17.10.16.
//
#include <array>

#ifndef A1_1_VEC3F_H
#define A1_1_VEC3F_H

namespace Vec3 {

    class Vec3f {


    public:
        Vec3f();
        Vec3f(float x, float y, float z);
        Vec3f(std::array<float,3> args);
        float x() const ;
        float y() const ;
        float z() const ;
    private:
        std::array<float,3> mArgs;
    };
}


#endif //A1_1_VEC3F_H

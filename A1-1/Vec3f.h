//
// Created by roberto on 17.10.16.
//
#include <array>

#pragma once

namespace my {

    class Vec3f {
    public:
        Vec3f();
        Vec3f(float x, float y, float z);
        Vec3f(std::array<float,3> &args);
        float x() const ;
        float y() const ;
        float z() const ;
        using value_type = float;
        static constexpr int dimension=3;
        float operator[](std::size_t index) const;
        float& operator[](std::size_t index) ;
    private:
    //wenn const, wird bei overwirte [] float& abgelehnt 
       std::array<float,3> mArgs;
    };
}


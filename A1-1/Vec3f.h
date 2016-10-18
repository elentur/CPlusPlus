//
// Created by roberto on 17.10.16.
//
#include <array>

#ifndef A1_1_VEC3F_H
#define A1_1_VEC3F_H

namespace my {

    class Vec3f {

    public:
        Vec3f();
        Vec3f(float x, float y, float z);
        Vec3f(std::array<float,3> args);
        float x() const ;
        float y() const ;
        float z() const ;

        using value_type = float;

        static constexpr int dimension = 3;

        /*
         * überschreibt den [] operator
         * gibt ein float zurück
         * nimmt den Index des Arrays entgegen
         * und gibt den Inhalt des arrays an dieser Stelle zurück
         * const-Methoden dürfen den Zustand des Objekts nicht verändern
         *
         * */
        const float operator[] (std::size_t idx) const{
            return mArgs[idx];
        }

        float& operator[] (std::size_t idx){
            return mArgs[idx];
        }

    private:
        std::array<float,3> mArgs;
    };

    inline bool operator== (const Vec3f& lhs, const Vec3f& rhs){
        return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
    }

    inline bool operator!= (const Vec3f& lhs, const Vec3f& rhs){
        return lhs[0] != rhs[0] || lhs[1] != rhs[1] || lhs[2] != rhs[2];
    }

    Vec3f operator+ (const Vec3f& lhs, const Vec3f& rhs){
        return Vec3f(
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
                lhs[2] + rhs[2]
        );
    }

    Vec3f operator+= (const Vec3f& rhs){
        return Vec3f(
                *this[0] + rhs[0],
                *this[1] + rhs[1],
                *this[2] + rhs[2]
        );
    }
}


#endif //A1_1_VEC3F_H

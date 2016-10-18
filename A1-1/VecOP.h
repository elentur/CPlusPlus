#include "Vec3f.h"
#include <iostream>

std::ostream& operator<<(std::ostream& lhs, my::Vec3f rhs);

bool operator==(my::Vec3f lhs, my::Vec3f rhs);
bool operator!=(my::Vec3f lhs, my::Vec3f rhs);
my::Vec3f& operator+=(my::Vec3f& lhs, my::Vec3f rhs);
my::Vec3f operator+(my::Vec3f lhs, my::Vec3f rhs);
my::Vec3f operator-(my::Vec3f rhs);
float dot(my::Vec3f lhs,my::Vec3f rhs);
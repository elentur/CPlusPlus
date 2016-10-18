#include "VecOP.h"

std::ostream& operator<<(std::ostream& lhs, my::Vec3f rhs){
   return lhs << "[" << rhs.x() << "," << rhs.y() << "," << rhs.z() << "]";
}

bool operator==(my::Vec3f lhs, my::Vec3f rhs)
{
    return lhs[0]==rhs[0] && lhs[1]==rhs[1] && lhs[2]==rhs[2];
}
bool operator!=(my::Vec3f lhs, my::Vec3f rhs)
{
    return !(lhs==rhs);
}
 
my::Vec3f& operator+=(my::Vec3f& lhs, my::Vec3f rhs)
{
      lhs[0]=lhs[0]+rhs[0];
      lhs[1]=lhs[1]+rhs[1];
      lhs[2]=lhs[2]+rhs[2];
      return lhs;
}
my::Vec3f operator+(my::Vec3f lhs, my::Vec3f rhs)
{
    return lhs+=rhs;
}
my::Vec3f operator-(my::Vec3f lhs)
{
    return my::Vec3f(-lhs[0],-lhs[1],-lhs[2]);
}

float dot(my::Vec3f lhs,my::Vec3f rhs)
{
    return lhs[0]*rhs[0] + lhs[1] *rhs[1] + lhs[2]*rhs[2];
}
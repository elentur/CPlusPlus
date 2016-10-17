#include "VecOP.h"

    std::ostream& operator<<(std::ostream& lhs, my::Vec3f rhs){
        return lhs << "[" << rhs.x() << "," << rhs.y() << "," << rhs.z() << "]";
    }


 
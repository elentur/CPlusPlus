#include <iostream>
#include "test11.h"
#include "Vec3f.h"

int main() {

    Vec3::Vec3f a = Vec3::Vec3f();

    std::cout << a.x() << std::endl;
    std::cout << a.y() << std::endl;
    std::cout << a.z() << std::endl;

    a = Vec3::Vec3f(5,6,7);

    std::cout << a.x() << std::endl;
    std::cout << a.y() << std::endl;
    std::cout << a.z() << std::endl;

    Vec3::Vec3f b = Vec3::Vec3f(std::array<float,3> {2.5f,-3,4});

    std::cout << b.x() << std::endl;
    std::cout << b.y() << std::endl;
    std::cout << b.z() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
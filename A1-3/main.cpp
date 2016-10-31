//#include <iostream>
#include "Vec.h"
//#include "VecOP.h"
#include "test11.h"
#include "testGen.h"
#include "Mat.h"



int main() {
   
/*   using namespace my;
    Vec<float,3> a{1,2,3};
  std::cout << a[0] << std::endl;
  std::cout << a << std::endl;

    Vec<float,3> c{5,6,7};

    const Vec<float,3> b{1,2,3};

    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(3.4f)*3 << std::endl;
    //std::cout << (typeid(Vec3f::value_type).name() == typeid(float).name()) << std::endl;
 
    std::cout << (c.dimension == 3 ) << std::endl;
    std::cout << b<< std::endl;
    auto x = b[1];
    std::cout << x << std::endl;
    a[1] = 5.6f;
    std::cout << a[1] << std::endl;
    std::cout << (a==b) << std::endl;
    std::cout << (a!=b) << std::endl;
    
    a[0] =1;
    a[1] =2;
    a[2] =3;
    std::cout << (a==b) << std::endl;
    Vec<float,3> d;
    std::cout << d << std::endl;
    Vec<float,3> e=  d+a+b;
    std::cout << d << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << e << std::endl;
     std::cout << -e << std::endl;*/



    test_Vec();
    test_VecGen<float,3>();
    return 0;
}


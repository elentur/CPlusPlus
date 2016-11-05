#pragma once

#include <iostream>
#include <cassert>
#include <typeinfo>
using namespace std;

#include "Vec.h"
#include "Mat.h"
#include "util.h"
using namespace my;

template<typename T, int N>
void test_VecGen()
{
    Vec<T,N> a;
    for(int i = 0; i<N;i++){
        a[i] = T(rand());
    }
  std::cout << a[0] << std::endl;
  std::cout << a << std::endl;

    Vec<T,N> c;
    for(int i = 0; i<N;i++){
        c[i] = T(rand() );
    }
    std::cout << c << std::endl;
    const Vec<T,N> b = a;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(3.4f)*3 << std::endl;
 
    std::cout << (c.dimension == 3 ) << std::endl;
    std::cout << b<< std::endl;
    auto x = b[1];
    std::cout << x << std::endl;
    a[1] = T(rand());
    std::cout << a[1] << std::endl;
    std::cout << (a==b) << std::endl;
    std::cout << (a!=b) << std::endl;
    
    a[0] =1;
    a[1] =2;
    a[2] =3;
    std::cout << (a==b) << std::endl;
    Vec<T,N> d;
    std::cout << d << std::endl;
    Vec<T,N> e=  d+a+b;
    std::cout << d << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << e << std::endl;
    std::cout << -e << std::endl;
    
    Mat<T,N> m1;
    std::cout << m1 << std::endl;

    Mat<T,N> m2{a,b,c};
    std::cout << m2 << std::endl;

    std::cout << Mat<T,N>::entity() << std::endl;

    std::cout << (m2==m2) << std::endl;
    std::cout << (m2!=m2) << std::endl;
   
    std::cout << a << std::endl;
    Mat<T,N> m3 = Mat<T,N>::entity();
    std::cout << (m3*a) << std::endl;
    Mat<T,N> m4 = {{1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.000f,9.12345f}};
   // std::cout << (m4) << std::endl;
    std::cout << (m3*m4) << std::endl;
    std::cout << to_string(m4) << std::endl;

}
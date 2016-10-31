#pragma once

#include <iostream>
#include <cassert>
#include <typeinfo>
using namespace std;

#include "Vec.h"
using namespace my;

template<typename T, int N>
void test_VecGen()
{
    Vec<T,N> a;
    for(int i = 0; i<N;i++){
        a[i] = T(rand() *100);
    }
  std::cout << a[0] << std::endl;
  std::cout << a << std::endl;

    Vec<T,N> c;
    for(int i = 0; i<N;i++){
        c[i] = T(rand() *100);
    }
    std::cout << c << std::endl;
    const Vec<T,N> b = a;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(3.4f)*3 << std::endl;
 
    std::cout << (c.dimension == 3 ) << std::endl;
    std::cout << b<< std::endl;
    auto x = b[1];
    std::cout << x << std::endl;
    a[1] = T(rand() *100);
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
}
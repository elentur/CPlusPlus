// Testtreiber für Aufgabe 2: my::vector
// Autor: Hartmut Schirmacher

#include <iostream>
#include "my_vector.h"
#include "payload.h"
#include <cassert>

using namespace std;

//void test_21();


int main()
{
    cout << "Starting tests (2.1) --------------------" << endl;
    //test_21();

    // cout << "Starting tests (2.2) --------------------" << endl;
    // test22();

    cout << "End of tests ----------------------------" << endl;


    my::vector<Payload> v;
    v.reserve(1);
//std::cout << Payload::count() << std::endl;
//std::cout << v.size() << std::endl;
    v.push_back(Payload(-1,-1,-1));
    v.push_back(Payload(-2,-1,-2));
    std::cout << Payload::count() << std::endl;
     assert(Payload::count() == 2);
    std::cout <<v[0] <<std::endl;

    std::cout <<v[1] <<std::endl;
     Payload p = v.pop_back();

     std::cout << "PCount: " << Payload::count()<< std::endl;
     std::cout << "p: " <<p << std::endl;
     Payload p2 = Payload(std::move(p));
     std::cout << "p2: " << p2 << std::endl;
     std::cout << "p: " << p << std::endl;
    std::cout << "PCount: " << Payload::count()<< std::endl;

     std::cout <<Payload::count() <<std::endl;
     assert(Payload::count() == 2);
    std::cout <<v[0] <<std::endl;

    std::cout <<v[1] <<std::endl;
    return 0;
}

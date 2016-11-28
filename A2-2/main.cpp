// Testtreiber für Aufgabe 2: my::vector
// Autor: Hartmut Schirmacher

#include <iostream>
#include "my_vector.h"
#include "payload.h"
#include <cassert>

using namespace std;

void test_22();

int main()
{

    cout << "Starting tests (2.2) --------------------" << endl;
    test_22();

    cout << "End of tests ----------------------------" << endl;

    /*  my::vector<Payload> v;
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
    v.reserve(100);
    std::cout <<"Size: "<< v.size() <<std::endl;
    std::cout <<"Capacity: "<< v.capacity() <<std::endl;
     v.shrink_to_fit();
    std::cout <<"Size: "<< v.size() <<std::endl;
    std::cout <<"Capacity: "<< v.capacity() <<std::endl;

    std::cout << "PCount: " << Payload::count()<< std::endl;
    std::cout << "v[0]: " << v[0]<< std::endl;
    my::vector<Payload> v1 = v;
std::cout << "PCount: " << Payload::count()<< std::endl;
std::cout << "v[0]: " << v[0]<< std::endl;
my::vector<Payload> v2 = std::move(v);
std::cout << "PCount: " << Payload::count()<< std::endl;
std::cout << "v[0]: " << v[0]<< std::endl;

*/
    return 0;
}

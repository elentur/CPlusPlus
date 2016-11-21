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
    std::cout << "Hallo";
    //v.push_back(Payload(-1,-1,-1));
   // assert(Payload::count() == 1);
  //  v.at(1) =10.2;
   // std::cout <<v[0];
    return 0;
}

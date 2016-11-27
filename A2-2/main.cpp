// Testtreiber für Aufgabe 2: my::vector
// Autor: Hartmut Schirmacher

#include <iostream>
#include <vector>
#include <assert.h>
#include "vector.h"
#include "payload.h"


using namespace std;

void test_21();


int main()
{
    //cout << "Starting tests (2.1) --------------------" << endl;
    test_21();

    //cout << "Starting tests (2.2) --------------------" << endl;
    //test22();

    //cout << "End of tests ----------------------------" << endl;

    {
        cout << "Start of tests (2.2)----------------------------" << endl;

        cout << "add vector array without initialisation Payload" << endl;

        my::vector<Payload> v;
        assert(Payload::count() == 0);
        assert(v.size() == 0);
        assert(v.capacity() == 0);

        cout << "Ok" << endl;

        cout << "Reserving memory for vector without initialisation Payload" << endl;

        v.reserve(1);
        assert(Payload::count() == 0);
        assert(v.size() == 0);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Adding a Payload to the array" << endl;

        v.push_back(Payload(1, 1, 1));
        assert(Payload::count() == 1);

        cout << v.size() << endl;

        assert(v.size() == 1);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Adding a Payload into a too small array" << endl;

        v.push_back(Payload(2, 2, 2));
        assert(Payload::count() == 2);
        assert(v.size() == 2);
        assert(v.capacity() == 2);

        cout << "Ok" << endl;

        cout << "End of tests ----------------------------" << endl;


    }

    return 0;
}

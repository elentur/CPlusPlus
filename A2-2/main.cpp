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
    //test_21();

    //cout << "Starting tests (2.2) --------------------" << endl;
    //test22();

    //cout << "End of tests ----------------------------" << endl;

    {
        cout << "Start of tests (2.2)----------------------------" << endl;

        my::vector<Payload> v;
        if (v)
            cout << "ERROR: default-constructed my::vector points to something." << endl;
        else
            cout << "Default-constructed my::vector points to nothing." << endl;
        assert(!v);
        assert(Payload::count() == 0);
        assert(v.size() == 0);
        assert(v.capacity() == 0);

        cout << "Ok" << endl;

        cout << "Reserving memory for vector without initialisation Payload" << endl;

        v.reserve(1);
        assert(v);
        assert(Payload::count() == 0);
        assert(v.size() == 0);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Adding a Payload to the array" << endl;

        v.push_back(Payload(1, 1, 1));
        assert(Payload::count() == 1);
        assert(v.size() == 1);
        assert(v.capacity() == 1);
        assert(!v.empty());

        cout << "Ok" << endl;

        cout << "Adding a Payload into a too small array" << endl;

        v.push_back(Payload(2, 2, 2));
        assert(Payload::count() == 2);
        assert(v.size() == 2);
        assert(v.capacity() == 2);

        cout << "Ok" << endl;

        cout << "Can we clear the vector?" << endl;
        // de-referencing
        assert(!v.empty());
        v.clear();
        assert(v.empty());

        cout << "Ok" << endl;


        cout << "Reserving memory for vector with 100 without initialisation Payload" << endl;

        v.reserve(100);
        assert(Payload::count() == 0);
        assert(v.size() == 0);
        assert(v.capacity() == 100);

        cout << "Ok" << endl;

        cout << "Add 1 Payload and shrink_to_fit from 100 to 1 " << endl;

        v.push_back(Payload(1, 1, 1));
        v.shrink_to_fit();
        assert(Payload::count() == 1);
        assert(v.size() == 1);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Pop back a Paylaod form vector" << endl;

        Payload a = v.pop_back();
        assert(a == Payload(1, 1, 1));
        assert(Payload::count() == 1);
        assert(v.size() == 0);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Pop back a empty Paylaod form vector" << endl;
        // TODO soll das so? sollte ein 0 Payload zurückgegeben werden?

        assert(v.pop_back());

        assert(Payload::count() == 2);
        assert(v.size() == 0);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;


        cout << "Moving r-value into vector - counts one up" << endl;
        v.clear();
        v.push_back(std::move(Payload(2, 2, 2)));
        assert(Payload::count() == 1);
        assert(v.size() == 1);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Moving l-value into vector - counts one up" << endl;
        v.clear();
        Payload payload = Payload(2, 2, 2);
        v.push_back(std::move(payload));
        assert(Payload::count() == 1);
        assert(v.size() == 1);
        assert(v.capacity() == 1);

        cout << "Ok" << endl;

        cout << "Copy Payload a into c - keeps count the same" << endl;

        Payload b = a;
        assert(Payload::count() == 2);

        cout << "Ok" << endl;

        cout << "Moving Payload a into b" << endl;

        Payload c = std::move(a);
        assert(Payload::count() == 2);

        cout << "Ok" << endl;




        cout << "End of tests ----------------------------" << endl;

    }

    return 0;
}

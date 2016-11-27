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
        if(v)
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

        cout << "Ok" << endl;

        cout << "Adding a Payload into a too small array" << endl;

        v.push_back(Payload(2, 2, 2));
        assert(Payload::count() == 2);
        assert(v.size() == 2);
        assert(v.capacity() == 2);

        cout << "Ok" << endl;

        cout << "Can we clear the vector?" << endl;

        // de-referencing using "->"
        assert(!v.empty());
        v.clear();
        assert(v.empty());

        cout << "Ok" << endl;
/*
        // const-ness
        const uptr<string> coptr(new string("I AM CONST, DO NOT TOUCH ME"));
        assert(coptr);
        assert(!coptr->empty());
        cout << "const ptr to: " << *coptr << " - size()=" << coptr->size() << endl;

        // make function like std::make_unique()
        auto p = uptr<string>::make();
        (*p) += "Hello, World";

        // make function with variadic arguments
        auto q = uptr<string>::make("Hello variadic template world!");
        cout << "make() with args: " << *q << endl;*/

        cout << "End of tests ----------------------------" << endl;

        /*
         * // what do we want to do with uptr<>?
    uptr<string> ptr;
    if(ptr)
        cout << "ERROR: default-constructed uptr points to something." << endl;
    else
        cout << "OK: default-constructed uptr points to nothing." << endl;
    assert(!ptr);

    // take over a newly created resource
    ptr = uptr<string>(new string("Hello unique pointer!"));
    assert(ptr);

    // de-referencing
    cout << "now points to: " << *ptr << endl;
    (*ptr) += " Hello World";
    cout << "now points to: " << *ptr << endl;

    // de-referencing using "->"
    assert(!ptr->empty());
    ptr->clear();
    assert(ptr->empty());

    // const-ness
    const uptr<string> coptr(new string("I AM CONST, DO NOT TOUCH ME"));
    assert(coptr);
    assert(!coptr->empty());
    cout << "const ptr to: " << *coptr << " - size()=" << coptr->size() << endl;

    // make function like std::make_unique()
    auto p = uptr<string>::make();
    (*p) += "Hello, World";

    // make function with variadic arguments
    auto q = uptr<string>::make("Hello variadic template world!");
    cout << "make() with args: " << *q << endl;*/


    }

    return 0;
}

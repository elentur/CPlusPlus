// treiber für Aufgabe 2: my::vector
// Autor: Hartmut Schirmacher

#include <iostream>
#include <cassert>
#include "my_vector.h"
#include "payload.h"

void test_22()
{
    using my::vector;
    using std::cout;
    using std::endl;

    {
        cout << "construction/destruction, size() ... ";
        vector<Payload> v0;
        assert(v0.size() == 0);
        assert(Payload::count() == 0);

        {
            // are the elements created?
            vector<Payload> v1(3, Payload(-1, -1, -1));
            assert(v1.size() == 1);
            assert(Payload::count() == v1.size());
        }

        // are the elements destroyed?
        assert(Payload::count() == 0);
        cout << " done." << endl;
    }
    {
        cout << "reserve & shrink ... ";
        {
            vector<Payload> v;
            assert(v.capacity() == 0);
            assert(v.size() == 0);
            v.push_back(Payload(0, 0, 0));
            assert(v.size() == 1);
            assert(v.capacity() == 1);
            v.push_back(Payload(1, 1, 1));
            assert(v.size() == 2);
            assert(v.capacity() == 2);
            v.reserve(100);
            assert(v.size() == 2);
            assert(Payload::count() == v.size());
            assert(v.capacity() == 100);
            v.push_back(Payload(2, 2, 2));
            assert(v.size() == 3);
            assert(Payload::count() == v.size());
            assert(v.capacity() == 100);
            v.shrink_to_fit();
            assert(v.size() == 3);
            assert(Payload::count() == v.size());
            assert(v.capacity() == 3);
        }
        cout << " done." << endl;
    }
    {
        cout << "clear, empty... ";
        {
            vector<Payload> v;
            assert(v.empty());
            v.push_back(Payload(0, 0, 0));
            v.push_back(Payload(1, 1, 1));
            v.push_back(Payload(2, 2, 2));
            v.clear();
            assert(v.size() == 0);
            assert(Payload::count() == 0);
        }
        cout << " done." << endl;
    }
    {
        cout << "push_back(), pop_back(), size(), empty() ... ";
        {
            vector<Payload> v;
            v.reserve(10);
            assert(v.size() == 0);
            assert(v.empty());
            v.push_back(Payload(0, 0, 0));
            v.push_back(Payload(1, 1, 1));
            v.push_back(Payload(2, 2, 2));
            assert(v.size() == 3);
            assert(!v.empty());
            assert(Payload::count() == 3);
            assert(v.pop_back() == Payload(2, 2, 2));
            assert(v.size() == 2);
            assert(Payload::count() == 2);

            assert(v.pop_back() == Payload(1, 1, 1));
            assert(v.size() == 1);
            assert(Payload::count() == 1);

            assert(v.pop_back() == Payload(0, 0, 0));
            assert(v.size() == 0);
            assert(v.empty());
            assert(Payload::count() == 0);
            // check exception
            try
            {
                v.pop_back();
                assert(!"should have thrown exception");
            }
            catch (std::out_of_range ex)
            {
                cout << "exception: " << ex.what();
            }
        }
        assert(Payload::count() == 0);
        cout << " done." << endl;
    }

    {
        cout << "operator[] ... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1, 2, 3));
            v.push_back(Payload(7, 8, 9));
            assert(v.size() == 2);

            // check reading
            assert(v[0] == Payload(1, 2, 3));
            assert(v[1] == Payload(7, 8, 9));

            // check writing
            v[1] = Payload(-1, -1, -1);
            assert(v[1] == Payload(-1, -1, -1));
        }
        cout << " done." << endl;
    }

    {
        cout << "at() ... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1, 2, 3));
            v.push_back(Payload(7, 8, 9));
            assert(v.size() == 2);

            // check reading
            assert(v.at(0) == Payload(1, 2, 3));
            assert(v.at(1) == Payload(7, 8, 9));

            // check writing
            v.at(1) = Payload(-1, -1, -1);
            assert(v.at(1) == Payload(-1, -1, -1));

            // check exception
            try
            {
                v.at(2) = Payload(0, 0, 0);
                assert(!"should have thrown exception");
            }
            catch (std::out_of_range ex)
            {
                cout << "exception: " << ex.what();
            }
        }
        cout << " done." << endl;
    }

    {
        cout << "constness... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1, 2, 3));
            v.push_back(Payload(7, 8, 9));

            // const ref (read-only ref)
            const vector<Payload> &vconst = v;

            // all this must compile without problems, else you are missing const :-)
            assert(!vconst.empty());
            assert(vconst.size() == 2);
            assert(vconst[0] == Payload(1, 2, 3));
            assert(vconst.at(0) == Payload(1, 2, 3));
        }
        cout << " done." << endl;
    }

    {
        cout << "copy & move... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1, 2, 3));
            v.push_back(Payload(7, 8, 9));
            assert(Payload::count() == 2);
            vector<Payload> v2(std::move(v));
            assert(Payload::count() == 2);
            v = std::move(v2);
            vector<Payload> v3(v);
            assert(v3[0] == v[0]);
            assert(v3[1] == v[1]);
            assert(Payload::count() == 4);
            v2 = v3;
            assert(Payload::count() == 6);
        }
        cout << " done." << endl;
    }
}

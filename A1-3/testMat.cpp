#include <iostream>
#include <cassert>
#include <typeinfo>
#include "Vec.h"
#include "Mat.h"
#include "util.h"

using namespace std;
using namespace my;

void test_Mat() {
#ifndef NDEBUG
    cout << "=================" << endl;
    cout << " Testing Mat<T,N>" << endl;
    cout << "=================" << endl;

    Mat<float, 3> matEmpty;
    Mat<float, 3> matA{{1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f}};
    Mat<float, 3> matB{{1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f}};
    Mat<float, 3> matC{{7.0f,8.0f,9.0f},{4.0f,5.0f,6.0f},{1.0f,2.0f,3.0f}};
    Mat<float, 3> matD{{4.0f,5.0f,6.0f},{1.0f,2.0f,3.0f},{7.0f,8.0f,9.0f}};

    Vec<float,3> vecA = {1.0f,2.0f,3.0f};
    Vec<float,3> vecB = {4.0f,5.0f,6.0f};
    Vec<float,3> vecC = {7.0f,8.0f,9.0f};


    {
        cout << "  value type and dimension: ";
        assert(typeid(Mat<float, 3>::value_type).name() == typeid(float).name());
        assert((Mat<float, 3>::dimension) == 3);

        cout << "passed." << endl;
    }

    {
        cout << "  content type == 3 * Vec3<float,3>: ";
        Vec<float,3> emptyVec = {0.0f,0.0f,0.0f};
        assert(
                typeid(matEmpty[0]).name() == typeid(emptyVec).name()
                && typeid(matEmpty[1]).name() == typeid(emptyVec).name()
                && typeid(matEmpty[2]).name() == typeid(emptyVec).name()
        );
        cout << "passed." << endl;
    }

    {
        // do not tolerate any memory overhead
        cout << "  sizeof(Mat<float,3> ) == 36 bytes: ";
        assert(sizeof(Mat<float, 3>) == 3 * 3 * sizeof(float));
        cout << "passed." << endl;
    }

    {
        cout << "  constructor & index operator: ";
        Vec<float,3> emptyVec = {0.0f,0.0f,0.0f};
        assert(matEmpty[0] == emptyVec && matEmpty[1] == emptyVec && matEmpty[2] == emptyVec);
        assert(matB[0] == vecA && matB[1] == vecB && matB[2] == vecC);
        cout << "passed." << endl;
    }

    {
        cout << "  read-only access to const object: ";
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert(matA[1] == vecB);
        cout << "passed." << endl;
    }

    {
        cout << "  write access to a non-const object: ";
        Mat<float,3>matE = matD;
        matE[1] = vecB;
        assert(matE[0] == vecB
               && matE[1] == vecB
               && matE[2] == vecC
        );
        cout << "passed." << endl;
    }

    {
        cout << "  comparison: ";
        assert(matA == matB);
        assert(matA == matA);
        assert(matA != matC);
        assert(matB != matD);
        assert(!(matA != matB));
        cout << "passed." << endl;
    }

    {
        // should work out of the box when using std container (!)
        cout << "  assignment: " << endl;
        cout << to_string(matA[0]) << " "; // to make sure these values are not optimized away!
        Mat<float,3>matE = matC;
        assert(matE[0] == vecC && matE[1] == vecB && matE[2] == vecA);
        cout << "passed." << endl;
    }

    {
        cout << "  unary minus: ";
        assert(-matA == (Mat<float, 3>{{-1.0f,-2.0f,-3.0f},{-4.0f,-5.0f,-6.0f},{-7.0f,-8.0f,-9.0f}}));
        cout << "  passed." << endl;
    }

    {
        cout << "  Mat - Vec product: " << endl;
        cout << to_string(matA) << endl;
        cout << to_string(vecA) << endl;
        cout << " product = ";
        Vec<float,3> pro = matA * vecA;
        cout << to_string(pro) << endl;
        assert( pro  == (Vec<float,3>{14.0f, 32.0f, 50.0f}));
        cout << "  passed." << endl;
    }

    {
        cout << "  Mat - Mat product: " << endl;
        cout << to_string(matA) << endl;
        cout << to_string(matB) << endl;
        Mat<float,3> pro = matA * matB;
        cout << to_string(pro) << endl;
        assert( pro  == (Mat<float,3>{{30.0f,36.0f,42.0f},{66.0f,81.0f,96.0f},{102.0f,126.0f,150.0f}}));
        cout << "  passed." << endl;
    }

    {
        cout << "  Mat - entity: ";
        Mat<float,3> entity = Mat<float,3>::entity();
        assert( entity  == (Mat<float,3>{{1.0f,0.0f,0.0f},{0.0f,1.0f,0.0f},{0.0f,0.0f,1.0f}}));
        cout << "  passed." << endl;
    }

    {
        cout << "  width and decimal: " << endl;
        Mat<float, 3> test = {{-1.123f,-2.123f,-3.123f},{-4.9876f,-5.9876f,-6.9876f},{-7.123456789f,-8.123456789f,-9.123456789f}};
        cout << to_string(test,0,0) << endl;
        cout << to_string(test,2,2) << endl;
        cout << to_string(test,2,8) << endl;
        cout << to_string(test,8,2) << endl;
        cout << "  passed?" << endl;
    }

    cout << "all Mat<float,3>  tests passed." << endl
         << endl;


#endif // not NDEBUG
}
#pragma once
#include <iostream>
#include <cassert>
#include <typeinfo>
#include <stdlib.h>
#include <functional>
#include "Vec.h"
#include "Mat.h"
#include "util.h"

using namespace std;
using namespace my;

template<typename T, int N>
Vec<T,N> genRandVec(){
    Vec<T,N> a;
    for(int i = 0; i<N;i++){
        a[i] = T(rand());
    }

    return a;
}

template<typename T, int N>
Mat<T,N> genRandMat(){
    Mat<T,N> a;
    for(int i = 0; i<N;i++){
        a[i] = genRandVec<T,N>();
    }

    return a;
}


template<typename T, int N>
void test_Mat() {

#ifndef NDEBUG
    cout << "=================" << endl;
    cout << " Testing Mat<T,N>" << endl;
    cout << "=================" << endl;


    Mat<T, N> matEmpty;
    Mat<T, N> matA;
    Mat<T, N> matB;
    Mat<T, N> matC = genRandMat<T,N>();
    Mat<T, N> matD = genRandMat<T,N>();

    Vec<T,N> emptyVec;

    Vec<T,N> vecList [N];

    for(int i = 0; i<N;i++){
        vecList[i] = genRandVec<T,N>();
        matA[i] =  vecList[i];
    }

    matB = matA;

    {
        cout << "  value type and dimension: ";
        assert(typeid(typename Mat<T, N>::value_type).name() == typeid(T).name());
        assert((Mat<T, N>::dimension) == N);
        cout << "passed." << endl;
    }

    {
        cout << "  content type == N * Vec<T,N>: ";
        for (int i = 0; i < N; ++i) {
            assert(typeid(matEmpty[i]).name() == typeid(emptyVec).name());
        }
        cout << "passed." << endl;
    }

    {
        // do not tolerate any memory overhead
        cout << "  sizeof(Mat<T,N> ) == N * N * T bytes: ";
        assert(sizeof(Mat<T, N>) == N * N * sizeof(T));
        cout << "passed." << endl;
    }

    {
        cout << "  constructor & index operator: ";
        for (int i = 0; i < N; ++i) {
            assert(matEmpty[i] == emptyVec);
        }

        for (int i = 0; i < N; ++i) {
            assert(matA[i] == vecList[i]);
        }
        cout << "passed." << endl;
    }

    {
        cout << "  read-only access to const object: ";
        // the next line will throw a compiler error if there is no proper "operator[] const"
        for (int i = 0; i < N; ++i) {
            assert(matA[i] == vecList[i]);
        }
        cout << "passed." << endl;
    }

    {
        cout << "  write access to a non-const object: ";

        Mat<T,N>matE = matA;
        Vec<T,N> vecA = genRandVec<T,N>();

        matE[N/2] = vecA;

        for (int i = 0; i < N; ++i) {
            if(i==(N/2)){
                assert(matE[i] == vecA);
            }else{
                assert(matE[i] == vecList[i]);
            }
        }

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
        Mat<T,N>matE = matA;
        for (int i = 0; i < N; ++i) {
            assert(matE[i] == vecList[i]);
        }
        cout << "passed." << endl;
    }

    {
        cout << "  unary minus: ";

        Mat<T,N> negMatA;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                negMatA[i][j] =  matA[i][j] * T(-1);
            }
        }

        assert(-matA == negMatA);
        cout << "  passed." << endl;
    }


    Mat<float, 3> mat3A{{1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f}};
    Mat<float, 3> mat3B{{1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f}};

    Vec<float,3> vecA = {1.0f,2.0f,3.0f};

    {
        cout << "  Mat - Vec product: " << endl;
        cout << to_string(mat3A) << endl;
        cout << to_string(vecA) << endl;
        cout << " product = ";
        Vec<float,3> pro = mat3A * vecA;
        cout << to_string(pro) << endl;
        assert( pro  == (Vec<float,3>{14.0f, 32.0f, 50.0f}));
        cout << "  passed." << endl;
    }

    {
        cout << "  Mat - Mat product: " << endl;
        cout << to_string(mat3A) << endl;
        cout << to_string(mat3B) << endl;
        Mat<float,3> pro = mat3A * mat3B;
        cout << to_string(pro) << endl;
        assert( pro  == (Mat<float,3>{{30.0f,36.0f,42.0f},{66.0f,81.0f,96.0f},{102.0f,126.0f,150.0f}}));
        cout << "  passed." << endl;
    }

    {
        cout << "  Mat - entity: ";
        Mat<T,N> entity = Mat<T,N>::entity();

        Mat<T,N> control;

        for (int i = 0; i < N; ++i) {
            control[i][i] = 1;
        }

        assert( entity == control );
        cout << "  passed." << endl;
    }

    {
        cout << "  width and decimal: " << endl;
        cout << to_string(matA,0,0) << endl;
        cout << to_string(matA,2,2) << endl;
        cout << to_string(matA,2,8) << endl;
        cout << to_string(matA,8,2) << endl;
        cout << "  passed?" << endl;
    }

    cout << "all Mat<T,N>  tests passed." << endl
         << endl;


#endif // not NDEBUG
}
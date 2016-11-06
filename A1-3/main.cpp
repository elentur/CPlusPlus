//#include <iostream>
#include "Vec.h"
//#include "VecOP.h"
#include "test11.h"
#include "testMat.h"
#include "testGen.h"
#include "Mat.h"


int main() {

    test_Vec();
    test_Mat();
    test_VecGen<float,3>();
    return 0;
}


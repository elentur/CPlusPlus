#include <iostream>
#include "Vec3f.h"
#include "test11.h"

using namespace std;

int main() {

    {
        using namespace my;

        Vec3f a = Vec3f(1, 2, 3);

        Vec3f b = Vec3f(1, 2, 3);

        Vec3f c = a += b;

        cout << a[0] << endl;
    }

    test_Vec3f();

    return 0;
}
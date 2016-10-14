#include <iostream>
#include "x.h"
#include "y.h"

using namespace std;

int main() {

    X MyX;
    Y MyY;

    cout << MyX.info() << endl;

    cout << MyY.info() << endl;

    float num;

    cout << sizeof(num) << endl;

    return 0;
}
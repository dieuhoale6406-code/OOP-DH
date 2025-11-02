#include "Number.h"
#include <iostream>

using namespace std;

int main() {
    int x = 1; double y = 2;
    Number n1(2.2);
    x = int(y);
    x = int(n1);
    y = double(n1);
    cout << x << ", " << y;
    return 0;
}
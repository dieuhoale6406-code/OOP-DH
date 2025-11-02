#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    Point p1(1,2), p2(2,3);
    Point p11 = p1++;
    Point p22 = ++p2;
    cout << p1 << p11;
    cout << p2 << p22;
    return 0;
}
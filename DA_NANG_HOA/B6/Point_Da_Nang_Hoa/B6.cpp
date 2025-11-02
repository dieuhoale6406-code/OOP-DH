#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    Point p1(1,2), p2(2,3);
    Point p3 = p1 + p2;
    Point p4 = 1 + p1;
    Point p5 = p1 + 2;
    cout << p4 << p5;
    return 0;
}
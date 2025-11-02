#include <iostream>
#include "Test.cpp"
// #include "Vector.h"
// #include "Point.h"

// template class Vector<int>;
// template class Vector<double>;
// template class Vector<Point>;
using namespace std;


int main() {
    Vector<int, 3> v1(5);
    Vector<double, 2> v2(2.1);
    Vector<Point, 2> v3(Point(2, 3));
    v1.Show();
    v2.Show();
    v3.Show();
}
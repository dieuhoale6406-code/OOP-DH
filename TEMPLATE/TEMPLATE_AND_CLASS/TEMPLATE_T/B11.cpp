#include <iostream>
#include "Test.cpp"
// #include "Vector.h"
// #include "Point.h"

// template class Vector<int>;
// template class Vector<double>;
// template class Vector<Point>;
using namespace std;


int main() {
    Vector<int> v1(5, 3);
    Vector<double> v2(1.1, 2);
    Vector<Point> v3(Point(2, 3), 2);
    v1.Show();
    v2.Show();
    v3.Show();
}
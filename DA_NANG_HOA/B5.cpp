#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    // Point p1(1,2), p2(2,3);
    // Point p3 = p1 + p2;
    // Point p4 = operator+(p1,p2);
    // Point p5 = p2 - p1; //p2.operator-(p1)
    // Point p6 = p1 - p2; //p1.operator-(p2)
    // p3.Show();
    // p4.Show();
    // p5.Show();
    // p5.Show();
    // system("pause");

    Point p1,p2(2,3);
    cout << p1 << p2;
    p1 << cout << p2;
    return 0;
}
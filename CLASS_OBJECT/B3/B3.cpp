#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point p1;
    Point p2(2,3);
    Point p3(p2);
    p1.show();
    p2.show();
    p3.show();
    cin.get();

    p1.xVal = p3.xVal;
    // Point *p = new Point(4,5);
    // p->show();
    // delete p;
    p1.show();
    
    cout << Point::n << endl;
    Point p1(1,2);
    Point p2(p1);
    // Point::m++; -> không được vì không thể thay đổi giá trị trong Point
    cout << p1.m << ", " << p2.m << ", " << Point::m << endl;

    cout << p1.n << ", " << p2.n << ", " << Point::n << endl;
    Point* p = new Point(2,3);
    cout << p->n << endl;
    delete p;
    cout << Point::n << endl;
}
//Định nghĩa lớp
#include <iostream>
#include "Point.h"
using namespace std;

void Point::Show(){
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}

Point::Point(const int& xVal, const int& y) 
    : xVal(xVal), yVal(y) {}

Point ::~ Point() {
    cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
}
//Định nghĩa lớp

/*void TT(int x) -> không dùng vì khai báo biến toàn cục.
Mục đích: khai báo biến trong class Point -> dùng Point::TT(int x), thư viện Point.h
*/
#include <iostream>
#include "Point.h"

int Point::n = 0;

using namespace std;

void Point::TT(int x) {
    this->xVal += x;
    this->yVal += x;
}

void Point::show() {
    cout << this->xVal << " , " << this->yVal << endl;
    cout << this->z << endl; cout << Point::m << endl;
}

// Point::Point() {
//     this->xVal = 1; this->yVal = 1;
// }

Point::Point(const Point& p) : z(1) {
    this->xVal = p.xVal; this->yVal = p.yVal;
    Point::n++;
}

Point::Point(const int& x, const int& y) : z(2) {
    this->xVal = x;
    this->yVal = y;
}

Point::~Point() {
    // cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
    Point::n--;
}

int Point::Get_xVal() {
    return this->xVal;
}

int Point::Get_yVal() {
    return this->yVal;
}

void Point::Set_xVal(const int& new_value) {
    this->xVal = new_value;
}

void Point::Shown() {
    cout << Point::n << endl;
}
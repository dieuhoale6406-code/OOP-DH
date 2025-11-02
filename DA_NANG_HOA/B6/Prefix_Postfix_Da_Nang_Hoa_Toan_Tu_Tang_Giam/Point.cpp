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
    // cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
}

Point operator+(const Point& p1, const Point& p2) {
    // Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal); //gây tốn bộ nhớ
    // return p;
    return Point(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
}

Point operator+(const Point& p1, const int& x) {
    return Point(p1.xVal + x, p1.yVal + x);
}

Point operator+(const int& x, const Point& p1) {
    return Point(p1.xVal + x, p1.yVal + x);
}

Point Point::operator-(const Point& pp) {
    Point p(this->xVal - pp.xVal, this->yVal - pp.yVal);
    return p;
}

ostream& operator<<(ostream& o, const Point& p) {
    o << "Point(" << p.xVal << ", " << p.yVal << ")" <<endl;
    return o;
}

ostream& operator<<(const Point& p, ostream& o) {
    o << "Point(" << p.xVal << ", " << p.yVal << ")" <<endl;
    return o;
}

istream& operator>>(istream& in, Point& p) {
    cout << "xVal =";
    in >> p.xVal;
    cout << "yVal = ";
    in >> p.yVal;
    return in;
}

Point& Point::operator++() { //perfix
    this->xVal++;
    this->yVal++;
    return (*this);
}

const Point Point::operator++(int) { //postfix
    Point bef = (*this);
    this->xVal++;
    this->yVal++;
    return bef;
}
//Định nghĩa lớp
#include <iostream>
#include "Point.h"
using namespace std;
void Point :: TT(int x){
    this->xVal += x;
    this->yVal += x;
}

void Point::Show(){
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point () {
    this->xVal = 1; this->yVal = 1;
}

Point :: Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}

Point :: Point(const int& xVal, const int& y) {
    this->xVal = xVal;
    this->yVal = y;
}

Point ::~ Point() {
    // cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
}

int Point :: Get_xVal(){
    return this->xVal;
}
void Point :: Set_xVal(const int& new_value) {
    this->xVal = new_value;
}
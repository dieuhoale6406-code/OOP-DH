#include "Point3D.h"

Point3D::Point3D(const int& x, const int& y, const int& z)
    : Point(x,y) {
        this->xVal = x; this->yVal = y;
        this->zVal = z;
}

Point3D::~Point3D() {
    cout << "Huy Point3D(" << this->xVal << ", " << this->yVal
    << ", " << this->zVal << ")" << endl;
}

void Point3D::Show3D() {
    cout << "Point3D(" << this->xVal << ", " << this->yVal
    << ", " << this->zVal << ")" << endl;
}
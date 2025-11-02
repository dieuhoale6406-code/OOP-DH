#include "Point4D.h"

Point4D::Point4D(const int& x, const int& y, const int& z, const int& t)
    : Point3D(x,y,z) {
        this->tVal = t;
}

Point4D::~Point4D() {
    cout << "Huy Point4D" << endl;
}

void Point4D::Show4D() {
    this->Show3D();
    cout << this->tVal << endl;
}

void Point4D::Show() {
    cout << "Point4D(" << this->xVal << ", " << this->yVal
    << ", " << this->zVal << ", " << this->tVal << ")" << endl;
}
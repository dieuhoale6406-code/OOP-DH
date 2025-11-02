#include "C.h"
#include <iostream>

using namespace std;
C::C(const int& a, const int& b, const int& c)
    : A(a), B(b) {
    this->C1 = c;
}

C::~C() {}

void C::C11() {
    cout << "C - C11" << endl;
}

void C::AB() {
    cout << "C - AB" << endl;
}
#include "A.h"
#include <iostream>
using namespace std;

A::A(const int& a)
    : A1(a) {}

A::~A() {
    cout << "Huy A" << endl;
}

void A::A11() {
    cout << "A - A11" << endl;
}

void A::AB() {
    cout << "A - AB" << endl;
}
#include "B.h"
#include <iostream>

using namespace std;

B::B(const int& b)
    : B1(b) {}

B::~B() {
    cout << "Huy B" << endl;
}

void B::B11() {
    cout << "B - B11" << endl;
}

void B::AB() {
    cout << "B - AB" << endl;
}
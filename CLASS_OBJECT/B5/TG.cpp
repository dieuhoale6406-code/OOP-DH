#include "TG.h"
#include <iostream>

using namespace std;

TG::TG(const Point& a, const Point& b, const Point& c)
    : A(a), B(b) {
    this->C = c;
}

TG::TG(const int& a1, const int& a2, const int& b1, const int& b2, const int& c1, const int& c2)
: A(a1,a2), B(b1, b2), C(c1, c2) {}

TG::~TG() {
    cout << "Huy TG" << endl;
}

void TG::ShowTG() {
    (this->A).Show();
    (this->B).Show();
    (this->C).Show();
}
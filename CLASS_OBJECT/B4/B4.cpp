#include <iostream>
//#include "IntSet.h"
#include "RealSet.h"
using namespace std;

int main() {
    IntSet i1(4);
    RealSet r1(5);
    i1.SetToReal(r1);
    r1.ShowRealSet();

    return 0;
}
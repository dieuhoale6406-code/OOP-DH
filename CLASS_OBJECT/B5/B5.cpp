#include <iostream>
#include "TG.h"
#include "IntSet.h"

using namespace std;

int main() {
    // TG t1(Point(1,2), Point(2,3), Point(3,4));
    // TG t2(9,8,7,6,5,4);
    // t1.ShowTG();
    // t2.ShowTG();
    // return 0;

    int* p = new int[3];
    Point* pp = new Point[3];
    for(int i = 0; i < 3; i++)
        (pp + i) ->Show();
    IntSet *p1 = new IntSet[3] {IntSet(2), IntSet(4), IntSet(3)};

}
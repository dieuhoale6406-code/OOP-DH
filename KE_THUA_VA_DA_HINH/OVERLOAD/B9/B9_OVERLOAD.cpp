#include "Point3D.h"

int main () {
    Point p1(1,2);
    Point3D p2(3,4,5);
    Point *p; Point3D* pp;

    // p = &p1;
    // pp = &p2;
    // p->Show();
    // pp->Show();

    //upcast
    p = &p2;
    //downcast
    pp = static_cast<Point3D*>(&p1);
    p->Show();
    pp->Show();
    //slicing
    Point p3(p1);
    Point p4(p2);

    return 0;
}
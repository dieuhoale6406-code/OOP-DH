#include "Point.h"

class Point3D : public Point {
    protected:
        // vVal, yVal
        int zVal;
    public:
        Point3D(const int& = 2, const int& = 2, const int& = 2);
        ~Point3D();
        // A(), A(int)
        void A();
        void Show(); // add this func -> tái định nghĩa
        void Show3D();
};
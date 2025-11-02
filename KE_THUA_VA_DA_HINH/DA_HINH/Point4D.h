#include "Point3D.h"

class Point4D : public Point3D {
    private:
        // xVal, yVal, zVal
        int tVal;
    public:
    Point4D(const int&  = 3, const int&  = 3, const int& = 3, const int&  = 3);
    ~Point4D();
    // Show(), Show3D();
    void Show();
    void Show4D();
};
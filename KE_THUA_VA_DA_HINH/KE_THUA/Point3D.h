#include "Point.h"

class Point3D : public Point {
    private:
        // vVal, yVal
        int zVal;
    public:
        Point3D(const int& = 2, const int& = 2, const int& = 2);
        // nếu không có hàm này, khi gọi Point3D p2 sẽ gọi Point mặc định ở lớp cha
        ~Point3D();
        // Show
        void Show3D();
};
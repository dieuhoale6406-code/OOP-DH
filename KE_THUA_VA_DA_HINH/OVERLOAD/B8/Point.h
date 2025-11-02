#include <iostream>

using namespace std;

class Point {
    protected:
        int xVal;
        int yVal;
    public:
        Point(const int& = 1, const int& = 1);
        // Point(const int, const int&); nếu không có tham số mặc định -> báo lỗi khi gọi Point3D
        Point(const Point&);
        ~Point();
        void Show();
        //overload
        void A();
        void A(int);
};
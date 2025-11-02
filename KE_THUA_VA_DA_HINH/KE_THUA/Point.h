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
};

void Point::Show(){
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}

Point::Point(const int& xVal, const int& y) 
    : xVal(xVal), yVal(y) {}

Point ::~ Point() {
    cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
}
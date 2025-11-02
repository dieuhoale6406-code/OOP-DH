#include <iostream>

using namespace std;

class Point {
    //public, private, protected
    //tập tên thuộc tinh
    public:
        int xVal;
        int yVal;
    //tap hợp nguyen mau ham thanh vien
    public:
        Point(const Point&);
        Point(const int& = 1, const int& = 1);
        ~Point();
        void Show();
        friend Point operator+(const Point&, const Point&);
        Point operator-(const Point&);
        friend ostream& operator<<(ostream&, const Point&);
        friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);
};
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
        friend Point operator+(const Point&, const Point&); //fixed this func
        friend Point operator+(const Point&, const int&); //Point + int
        friend Point operator+(const int&, const Point&); // int + Point
        Point operator-(const Point&);
        friend ostream& operator<<(ostream&, const Point&);
        friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);

        Point& operator++(); //++p1 -> prefix
        const Point operator++(int); // p1 ++ -> postfix
};
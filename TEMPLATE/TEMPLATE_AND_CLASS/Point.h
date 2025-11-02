#include <iostream>

using namespace std;

class Point {
    protected:
        int xVal;
        int yVal;
    public:
        Point(const int& = 1, const int& = 1);
        Point(const Point&);
        ~Point();
        virtual void Show();
        //overload
        void A();
        void A(int);

        friend Point operator+(const Point&, const Point&); //fixed this func
        friend Point operator+(const Point&, const int&); //Point + int
        friend Point operator+(const int&, const Point&); // int + Point
        Point operator-(const Point&);
        friend ostream& operator<<(ostream&, const Point&);
        friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);
};
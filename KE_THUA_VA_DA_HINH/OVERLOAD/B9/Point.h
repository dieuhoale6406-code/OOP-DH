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
};
#include <iostream>

using namespace std;

class Vector {
    private:
        int* p;
        int n;
    public:
        Vector(const int& = 2);
        Vector(const Vector&);
        ~Vector();
        friend ostream& operator<<(ostream&, const Vector&);
        friend istream& operator>>(istream&, Vector&);
        int& operator[](const int&);
        
        const Vector& operator=(const Vector&); // v1 = v2 ; a = b = c; (a = b) = c
};
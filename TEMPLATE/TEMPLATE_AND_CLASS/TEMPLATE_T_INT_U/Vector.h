#include <iostream>
using namespace std;

template <typename T, int U>
//Vector<T, U>, Vector<T, U>
class Vector
{
private:
    T *p;
    int n;

public:
    Vector(const T&);
    // Vector(const Vector<T, U> &);
    ~Vector();
    void Show();
    // friend ostream &operator<<(ostream &, const Vector<T, U> &);
};

template <typename T, int U>
Vector<T, U>::Vector(const T &t)
    : n(U)
{
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        *(this->p + i) = t;
    }
}

template <typename T, int U>
Vector<T, U>::~Vector()
{
    delete[] this->p;
}

template <typename T, int U>
// ostream &operator<<(ostream &o, const Vector<T, U> &v)
void Vector<T, U>::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";
    }
    cout << endl;
    // return o;
}
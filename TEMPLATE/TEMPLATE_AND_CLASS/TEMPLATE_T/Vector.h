#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
    T *p;
    int n;

public:
    Vector(const T &x, const int &a = 2);
    // Vector(const Vector<T> &);
    ~Vector();
    void Show();
    // friend ostream &operator<<(ostream &, const Vector<T> &);
};
template <typename T>
Vector<T>::Vector(const T &t, const int &n)
    : n(n)
{
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        *(this->p + i) = t;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->p;
}

template <typename T>
// ostream &operator<<(ostream &o, const Vector<T> &v)
void Vector<T>::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";
    }
    cout << endl;
    // return o;
}
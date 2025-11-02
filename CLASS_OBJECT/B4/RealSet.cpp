#include "RealSet.h"
#include <iostream>
using namespace std;
RealSet :: RealSet(const int& n) : n(n)
{
    this->p = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        cout << "p[" << i << "] = ";
        cin >> *(this->p + i);
    }

}
RealSet ::~ RealSet() {
    delete[] this->p;
}
void RealSet :: ShowRealSet(){
    for (int i = 0; i < this->n; i++)
        cout << *(this->p + i) << " ";
    cout << endl;
}

void IntSet :: SetToReal(RealSet& r){
    delete[] r.p;
    r.n = this->n;
    r.p = new double[r.n];
    for (int i = 0; i < this->n; i++)
        *(r.p + i) = *(this->p + i);
}
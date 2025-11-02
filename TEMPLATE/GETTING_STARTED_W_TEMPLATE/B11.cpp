#include <iostream>
#include "Point.h"

using namespace std;
template<typename T> // chỉ có tác dụng với một hàm sau dòng này
//template<class T> --> sẽ khác với typename T
void HV(T& a, T& b) {
    cout << "Template" << endl;
    T t = a;
    a = b;
    b = t;
}

void HV(int& a, int& b) {
    cout << "HV " << a << ", " << b << endl;
    int t = a;
    a = b;
    b = t;
}

template<typename T, typename U>
void A(T a, U b) {
    cout << a << ", " << b << endl;
}

int main() {
    int a = 2, b = 3;
    HV<int>(a,b); // sẽ ưu tiên tìm nguyên mẫu hàm, ép kiểu (hàm tường minh)
    HV(a,b); // sẽ ưu tiên tìm tất cả các hàm có tên HV
    A<int,double>(1,2.4);
    A<int,int>(2,4);
    A<int,Point>(2, Point(3,4));
    return 0;
}
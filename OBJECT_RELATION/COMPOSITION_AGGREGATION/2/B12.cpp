#include "Dep.h"
#include <iostream>

using namespace std;

int main() {
    Teacher *t1 = new Teacher("NVA", 31);
    Teacher *t2 = new Teacher("NVB", 35);
    Teacher *t3 = new Teacher("NVA", 40);
    {
        Dep d("CNTT");
        d.AddTeacher(t1);
        d.AddTeacher(t2);
        d.AddTeacher(t3);
        cout << d;
    }
    cout << *t1 << *t2 << *t3;
    return 0;
}
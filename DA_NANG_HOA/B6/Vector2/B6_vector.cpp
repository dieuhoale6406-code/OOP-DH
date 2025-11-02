#include "Vector.h"

int main() {
    Vector v1(4); // 2 2 2 2
    Vector v2(5); // 2 2 2 2 2
    Vector v3(v2);
    Vector v4 = v2;
    v2 = v1;
    cout << v2;
}
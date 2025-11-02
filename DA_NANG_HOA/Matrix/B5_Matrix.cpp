#include "Matrix.h"

int main() {
    Matrix m1(2,3);
    m1(1,2) = 9;
    cout << m1;
    return 0;
}
#include "C.h"

int main() {
    C cc(5,6,7);
    cc.A11();
    cc.B11();
    cc.C11();
    cc.AB(); // đã định nghĩa hàm, có thể gọi bình thường
    cc.A::AB(); // gọi hàm AB() trong phạm vi lớp A
    cc.B::AB(); // gọi hàm AB() trong phạm vi lớp B

    return 0;
}
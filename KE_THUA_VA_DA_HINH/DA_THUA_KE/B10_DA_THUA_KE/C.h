#include "A.h"
#include "B.h"

class C : public A, public B {
    private:
        // A1 -> A
        // B1 -> B
        int C1;
    public:
        // A11(), AB() -> A
        // B11(), AB() -> B
        C(const int& = 3, const int& = 3, const int& = 3);
        ~C();
        void C11();
        void AB(); //nếu không có hàm này, khi gọi cc.AB() ở main thì sẽ báo lỗi do không biết gọi hàm AB() của lớp nào -> hiện tượng mơ hồ
};
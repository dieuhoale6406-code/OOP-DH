#include "MyExp.h"
#include <iostream>

using namespace std;

int main() {
    int a, b;
    do {
        try {
            cin >> a;
            cin >> b;
            if(b == 0)
                // throw 1; // catch int sẽ bắt
                // throw 5.4; // catch double sẽ bắt
                // throw string("Bo day"); // catch(...) sẽ bắt
                throw MyExp("Ngu vua vua", 2);
            else
                cout << a / b << endl;
        }
        catch (const int& e) {
            cout << "int: " << e << endl;
        }
        catch (const double& e) {
            cout << "double: " << e << endl;
        }
        catch (const MyExp& e) { // phải đặt catch của lớp con trước lớp cha
            cout << "MyExp: " << e << endl;
        }
        catch (const Exp& e) { // nếu đặt catch lớp cha trước thì sẽ lớp con -> lớp cha -> không thực hiện catch lớp con
            cout << "Exp: " << e << endl;
        }
        catch(...) { // phải đặt ở sau cùng, nếu không -> lỗi
            cout << "Bat duoc roi" << endl;
        }
    } while(b);
}
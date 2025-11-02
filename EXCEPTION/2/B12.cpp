#include "MyExp.h"
#include <iostream>

using namespace std;

int B(const int& a, const int& b) {
    try {
        if(b == 0)
            throw Exp("Dot lam");
    }
    catch(const MyExp& e) {
        cout << "B: " << e;
        throw;
    }
    catch(const Exp& e) {
        cout << "B: " << e;
        throw e;
    }
    return a / b;
}

void A(const int& a, const int& b) {
    // cout << B(a,b) << endl;
    try {
        cout << B(a,b) << endl;
    }
    catch(const MyExp& e) {
        cout << "A: " << e;
        throw;
    }
    catch (const Exp& e) {
        cout << "A: " << e;
        throw;
    }
}

int main() {
    int a = 3, b = 0;
    try {
        A(a,b);
    }
    catch(const MyExp& e) {
        cout << "Main: " << e;
    }
    catch(const Exp& e) {
        cout << "Main: " << e;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int x = 1, y = 2;
    //int *p = &x;
    //const int x = 1;
    //int const y = 2;
    const int* p1 = &x; // p1 is a constant pointer to an int
    cout << *p1 << endl;
    //(*p1)++;
    p1 = &y;
    cout << *p1 << endl;

    int* const p2 = &y; // p2 is a pointer to a constant int
    cout << *p2 << endl;
    // p2 = &x;
    (*p2)++;
    cout << *p2 << endl;
    return 0;
}
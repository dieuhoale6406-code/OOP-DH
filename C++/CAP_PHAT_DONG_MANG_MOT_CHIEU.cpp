#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Cấp phát tĩnh
    // int A[] = {1,2,3,4}; int *p = A;
    // Cấp phát động
    int *A = new int[n];
    for(int i = 0; i < n; i++)
        cin >> *(A + i);
    for(int i = 0; i < n; i++)
        cout << "VALUE: " << *(A + i) << "\t\tADDRESS: " << A + i << endl;
}
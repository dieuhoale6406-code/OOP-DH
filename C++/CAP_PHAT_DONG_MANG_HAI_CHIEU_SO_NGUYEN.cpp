#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int **p = new int*[r];
    for(int i = 0; i < r; i++) {
        *(p + i) = new int[c];
        for(int j = 0; j < c; j++) {
            cout << "p[" << i << "][" << j << "] = ";
            cin >> *(*(p  + i) + j);
        }
    }
    for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++)
        cout << *(*(p + i) + j) << "\t";
    cout << endl;
    }
    return 0;
}
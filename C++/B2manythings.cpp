#include <iostream>
using namespace std;

//------------------CÁCH DÙNG CONSTANT_CAST
// void Show(char *str) {
//     cout << str;
// }

// int main() {
//     const char *str = "DUT";
//     // Show(str);
//     Show(const_cast<char*>(str));
//     return 0;
// }

//--------------CÁC ĐỊA CHỈ CỦA MẢNG
// int main () {
//     int A[4] = {1, 4, 6, 8};
//     int *p = A;
//     cout << "ĐỊA CHỈ CỦA MẢNG 1 CHIỀU" << endl;
//     cout << "p = " << p << ", A = " << A << ", &A[0] = " << &A[0] << endl;
//     cout << "p + 1 = " << p + 1 << ", A + 1 = " << A + 1 << ", &A[1] = " << &A[1] << endl;
//     cout << "*(p + 1) = " << *(p + 1) << ", *(A + 1) = " << *(A + 1) << ", A[1] = " << A[1] << endl;
//     return 0;
// }

// int main() {
//     int A[2][3] = {1,3,5,2,4,6};
//     cout << "ĐỊA CHỈ CỦA MẢNG 2 CHIỀU" << endl;
//     cout << "ĐỊA CHỈ CỦA Ô A[0][0]: " << endl;
//     cout << "A = " << A << ", &A[0][0] = " << &A[0][0] << endl;
//     cout << "ĐỊA CHỈ CỦA HÀNG A[1]:" << endl;
//     cout << "*(A + 1) = "<< *(A + 1) << ", &A[1] = " << &A[1][0] << endl;
//     cout << "ĐỊA CHỈ CỦA Ô A[1][1]:" << endl;
//     cout << "*(A + 1) + 1 = "<< *(A + 1) + 1 << ", &A[1][1] = " << &A[1][1] << endl;
//     cout << "GIÁ TRỊ CỦA Ô A[1][1]: " << endl;
//     cout << "*(*(A + 1) + 1) = "<< *(*(A + 1) + 1) << ", A[1][1] = " << A[1][1] << endl;
// }

//CON TRỎ TỚI HÀM NHẬN INT(*P)(INT, INT)
bool TD(int a, int b) {
    return a > b;
}
bool GD(int a, int b) {
    return a < b;
}

int sum(int x, int y) {
    return x + y;
}

//SẮP XẾP TĂNG DẦN
void sx(int *p, int n, bool (*cmp)(int, int)) {
    cout << "MANG BAN DAU: ";
    for(int i = 0; i < n; i++)
        cout << *(p + i) << " ";
    cout << endl;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(cmp(*(p + i), *(p + j))) {
                int t = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = t;
            }
        }
    cout << "MANG DA SAP XEP: ";
    for(int i = 0; i < n; i++)
        cout << *(p + i) << " ";
}

int main() {
    int (*p)(int, int);
    // int *p(int, int);
    p = sum;
    cout << sum(1,2) << ", " << p(1,2) << endl;
    int A[4];
    cout << "NHAP 4 SO NGUYEN: ";
    for(int i = 0; i < 4; i++) {
        cin >> A[i];
    }
    char choice;
    cout << "SAP XEP TANG DAN (T) HAY GIAM DAN (G): ";
    cin >> choice;
    sx(A,4,choice == 'T' ? TD : GD);
    return 0;
}
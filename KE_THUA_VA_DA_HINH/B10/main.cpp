#include <iostream>
#include <limits>
#include "ClassSH.h"
#include "Lecturer.h"
#include "SinhVien.h"

using namespace std;

int main() {
    ClassSH* myClass = nullptr;
    int choice;

    do {
        cout << endl << "----- MENU -----" << endl;
        cout << "1. Tao lop moi" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Tim sinh vien" << endl;
        cout << "5. Xem thong tin lop" << endl;
        cout << "6. Cap nhat sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "----------------" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore(1000,'\n');

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai, vui long nhap lai" << endl;
            continue;
        }


        if (choice == 0) {
            cout << "Ket thuc chuong trinh" << endl;
        } else if (choice == 1) {
            if (myClass) {
                cout << "Xoa lop cu? (co - 1, khong - 0): ";
                int del;
                cin >> del;
                if (!del) continue;
                delete myClass;
                myClass = nullptr;
            } 
            String tenlop;
            Lecturer gv;
            cout << "Nhap ten lop: ";
            cin >> tenlop;
            cout << "Nhap thong tin giang vien:" << endl;
            cin >> gv;
            myClass = new ClassSH(tenlop, gv);
            cout << "Tao thanh cong lop moi" << endl;
        } else if (choice == 2) {
            if (!myClass) {
                cout << "Chua co lop, hay tao lop" << endl;
                continue;
            }
            SinhVien sv;
            cout << "Nhap thong tin sinh vien:" << endl;
            cin >> sv;
            if (myClass->add(sv))
                cout << "Them sinh vien thanh cong" << endl;
            else
                cout << "MSSV da ton tai" << endl;
        } else if (choice == 3) {
            if (!myClass) {
                cout << "Chua co lop" << endl;
                continue;
            }
            String id;
            cout << "Nhap MSSV can xoa: ";
            cin >> id;
            if (myClass->remove(id))
                cout << "Da xoa MSSV " << id << " khoi lop" << endl;
            else
                cout << "Khong tim thay MSSV de xoa" << endl;
        } else if (choice == 4) {
            if (!myClass) {
                cout << "Chua co lop" << endl;
                continue;
            }
            String id;
            cout << "Nhap MSSV: ";
            cin >> id;
            SinhVien* svien = myClass->find(id);
            if (svien)
                cout << "Thong tin sinh vien:" << endl << *svien << endl;
            else cout << "Khong tim thay MSSV" << endl;
        } else if (choice == 5) {
            if (!myClass) {
                cout << "Chua co lop." << endl;
                continue;
            }
            cout << *myClass << endl;
        } else if (choice == 6) {
            if (!myClass) {
                cout << "Chua co lop." << endl;
                continue;
            }
            String id;
            cout << "Nhap MSSV can cap nhat: ";
            cin >> id;
            SinhVien* svien = myClass->find(id);
            if (!svien) {
                cout << "Khong tim thay MSSV." << endl;
                continue;
            }
            double newGpa;
            cout << "Nhap GPA moi: ";
            cin >> newGpa;
            svien->setGPA(newGpa);
            cout << "Da cap nhat GPA." << endl;
        } 
        else cout << "Lua chon khong hop le." << endl;
    } while(choice);

    delete myClass;
    return 0;
}

#include <iostream>
#include <limits> // Dùng cho numeric_limits
#include "ClassSH.h"
#include "Lecturer.h"
#include "SinhVien.h"

using namespace std;

void showMenu() {
    cout << "=========== QUAN LY LOP SINH HOAT ===========" << endl;;
    cout << "1. Tao lop sinh hoat moi" << endl;;
    cout << "2. Them sinh vien vao lop" << endl;;
    cout << "3. Xoa sinh vien khoi lop" << endl;;
    cout << "4. Tim kiem sinh vien (theo MSSV)" << endl;;
    cout << "5. Xuat thong tin lop sinh hoat" << endl;;
    cout << "6. Cap nhat thong tin sinh vien" << endl;;
    cout << "0. Thoat chuong trinh" << endl;;
    cout << "=============================================" << endl;;
    cout << "Lua chon cua ban: ";
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void updateStudent(SinhVien* sv) {
    if (!sv) return;
    int choice;
    cout << endl << "--- Cap nhat thong tin cho SV: " << sv->getName() << " (" << sv->getId() << ") ---" << endl;;
    cout << "1. Cap nhat ten" << endl;;
    cout << "2. Cap nhat tuoi" << endl;;
    cout << "3. Cap nhat dia chi" << endl;;
    cout << "4. Cap nhat GPA" << endl;;
    cout << "0. Quay lai" << endl;;
    cout << "Lua chon: ";
    cin >> choice;
    clearInputBuffer();

    switch(choice) {
        case 1: {
            String newName;
            cout << "Nhap ten moi: ";
            cin >> newName;
            sv->setName(newName);
            cout << "Cap nhat ten thanh cong!" << endl;;
            break;
        }
        case 2: {
            int newAge;
            cout << "Nhap tuoi moi: ";
            cin >> newAge;
            sv->setAge(newAge);
            cout << "Cap nhat tuoi thanh cong!" << endl;;
            break;
        }
        case 3: {
            String newAddress;
            cout << "Nhap dia chi moi: ";
            cin >> newAddress;
            sv->setAddress(newAddress);
            cout << "Cap nhat dia chi thanh cong!" << endl;;
            break;
        }
        case 4: {
            double newGPA;
            cout << "Nhap GPA moi: ";
            cin >> newGPA;
            sv->setGPA(newGPA);
            cout << "Cap nhat GPA thanh cong!" << endl;;
            break;
        }
        default:
            break;
    }
}

int main() {
    ClassSH* pClass = nullptr;
    int choice;

    do {
        showMenu();
        cin >> choice;

        // Xử lý trường hợp nhập không phải là số
        if (cin.fail()) {
            cout << "Lua chon khong hop le. Vui long nhap so." << endl;;
            cin.clear();
            clearInputBuffer();
            choice = -1; // Đặt giá trị không hợp lệ để tiếp tục lặp
            continue;
        }

        clearInputBuffer(); // Xóa bộ đệm sau khi đọc lựa chọn

        switch (choice) {
            case 1: {
                cout << "\n--- TAO LOP SINH HOAT MOI ---" << endl;;
                if (pClass != nullptr) {
                    cout << "Lop da ton tai. Xoa lop cu de tao lop moi." << endl;;
                    delete pClass;
                }
                String className;
                cout << "Nhap ten lop: ";
                cin >> className;

                Lecturer gv;
                cout << "\nNhap thong tin giang vien chu nhiem:" << endl;;
                cin >> gv;

                pClass = new ClassSH(className, gv);
                cout << "\n=> Da tao lop '" << pClass->getClassName() << "' thanh cong!" << endl;;
                break;
            }
            case 2: {
                if (pClass == nullptr) {
                    cout << "Loi: Chua co lop sinh hoat nao. Vui long tao lop truoc (chon 1)." << endl;;
                    break;
                }
                cout << "\n--- THEM SINH VIEN MOI ---" << endl;;
                SinhVien sv;
                cin >> sv;
                if (pClass->add(sv)) {
                    cout << "\n=> Them sinh vien thanh cong!" << endl;;
                } else {
                    cout << "\n=> Them that bai! Sinh vien co MSSV " << sv.getId() << " da ton tai." << endl;;
                }
                break;
            }
            case 3: {
                if (pClass == nullptr) {
                    cout << "Loi: Chua co lop sinh hoat nao." << endl;;
                    break;
                }
                cout << "\n--- XOA SINH VIEN ---" << endl;;
                String mssv;
                cout << "Nhap MSSV cua sinh vien can xoa: ";
                cin >> mssv;
                if (pClass->remove(mssv)) {
                    cout << "\n=> Da xoa sinh vien co MSSV " << mssv << "." << endl;;
                } else {
                    cout << "\n=> Khong tim thay sinh vien co MSSV " << mssv << "." << endl;;
                }
                break;
            }
            case 4: {
                 if (pClass == nullptr) {
                    cout << "Loi: Chua co lop sinh hoat nao." << endl;;
                    break;
                }
                cout << "\n--- TIM KIEM SINH VIEN ---" << endl;;
                String mssv;
                cout << "Nhap MSSV can tim: ";
                cin >> mssv;
                SinhVien* sv = pClass->find(mssv);
                if (sv != nullptr) {
                    cout << "\n=> Tim thay sinh vien:" << endl;;
                    cout << "---------------------" << endl;;
                    cout << *sv;
                    cout << "---------------------" << endl;;
                } else {
                    cout << "\n=> Khong tim thay sinh vien co MSSV " << mssv << "." << endl;;
                }
                break;
            }
            case 5: {
                if (pClass == nullptr) {
                    cout << "Loi: Chua co lop sinh hoat nao." << endl;;
                    break;
                }
                cout << "\n\n--- THONG TIN LOP SINH HOAT ---" << endl;;
                cout << *pClass;
                break;
            }
             case 6: {
                if (pClass == nullptr) {
                    cout << "Loi: Chua co lop sinh hoat nao." << endl;;
                    break;
                }
                cout << "\n--- CAP NHAT THONG TIN SINH VIEN ---" << endl;;
                String mssv;
                cout << "Nhap MSSV cua sinh vien can cap nhat: ";
                cin >> mssv;
                SinhVien* sv = pClass->find(mssv);
                if (sv != nullptr) {
                    updateStudent(sv);
                } else {
                    cout << "\n=> Khong tim thay sinh vien co MSSV " << mssv << "." << endl;;
                }
                break;
            }
            case 0: {
                cout << "Ket thuc chuong trinh. Tam biet!" << endl;;
                break;
            }
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;;
                break;
        }
    } while (choice != 0);

    // Dọn dẹp bộ nhớ trước khi thoát
    delete pClass;
    pClass = nullptr;

    return 0;
}
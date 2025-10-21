#include "SinhVien.h"
#include <iostream>

using namespace std;

static bool is_digit(char c) {
    return c>='0' && c<='9';
}

static bool mssvHopLe(const String& s){
    if(s.getSize() != 10 || s[0] == 0) return false;
    for(unsigned int i = 0; i < 10; i++) if(!is_digit(s[i])) return false;
    return true;
}
static double gpaHopLe(double x){
    if(x < 0.0) return 0.0;
    if(x > 4.0) return 4.0;
    return x;
}

SinhVien::SinhVien() : Person(), Class(nullptr) {}

SinhVien::SinhVien(const String& name, int age, const String& address, bool gender, const String& id, double gpa)
    : Person(name,age,address,gender), Class(0) {
    setId(id);
    setGPA(gpa);
}
SinhVien::~SinhVien() {}

const String& SinhVien::getId() const {
    return mssv;
}
double SinhVien::getGPA() const {
    return gpa;
}

void SinhVien::setId(const String& id) {
    if(!mssvHopLe(id)) throw invalid_argument("MSSV phai 10 chu so va khong bat dau bang 0");
    mssv = id;
}

void SinhVien::setGPA(double x){ gpa = gpaHopLe(x); }

void SinhVien::setClass(ClassSH* Class){ this->Class = Class; }

void SinhVien::show() const{
    cout << "SV " << name << " (" << mssv << "), GPA = " << gpa << endl;
}

ostream& operator<<(ostream& os, const SinhVien& sv) {
    os << static_cast<const Person&>(sv);
    os << "MSSV: " << sv.mssv << endl;
    os << "GPA: " << sv.gpa << endl;
    return os;
}

istream& operator>>(istream& is, SinhVien& sv) {
    is >> static_cast<Person&>(sv);
    
    String temp_mssv;
    while(true) {
        cout << "Nhap MSSV (10 chu so, khong bat dau bang 0): ";
        is >> temp_mssv;
        try {
            sv.setId(temp_mssv);
            break; // Nếu hợp lệ thì thoát vòng lặp
        } catch (const invalid_argument& e) {
            cout << "Loi: " << e.what() << ". Vui long nhap lai.\n";
        }
    }
    
    double temp_gpa;
    cout << "Nhap diem GPA (0.0 -> 4.0): ";
    is >> temp_gpa;
    sv.setGPA(temp_gpa);
    
    return is;
}
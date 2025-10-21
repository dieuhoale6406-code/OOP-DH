#include "ClassSH.h"
#include "SinhVien.h" // Giả định file header của SinhVien
#include <iostream>

using namespace std;

void ClassSH::ensure(int required) {
    if (capacity >= required) {
        return;
    }
    int newCapacity = (capacity == 0) ? 15 : capacity * 2;
    if (newCapacity < required) {
        newCapacity = required;
    }

    SinhVien* newSinhVien = new SinhVien[newCapacity];

    for (int i = 0; i < SiSo; ++i) {
        newSinhVien[i] = sinhvien[i];
    }

    delete[] sinhvien;

    sinhvien = newSinhVien;
    capacity = newCapacity;
}

ClassSH::ClassSH() : classname(""), MainLecturer() {}

ClassSH::ClassSH(const String& name, const Lecturer& gv)
    : classname(name), MainLecturer(gv), SiSo(0), capacity(15) {
    sinhvien = new SinhVien[capacity];
}

ClassSH::ClassSH(const ClassSH& other)
    : classname(other.classname), MainLecturer(other.MainLecturer), SiSo(other.SiSo), capacity(other.capacity) {
    sinhvien = new SinhVien[capacity];
    for (int i = 0; i < SiSo; ++i) {
        sinhvien[i] = other.sinhvien[i];
    }
}

ClassSH::~ClassSH() {
    delete[] sinhvien;
}


const String& ClassSH::getClassName() const {
    return classname;
}

const Lecturer& ClassSH::getLecturer() const {
    return MainLecturer;
}

int ClassSH::getSiSo() const {
    return SiSo;
}


void ClassSH::setClassName(const String& name) {
    classname = name;
}

void ClassSH::setLecturer(const Lecturer& gv) {
    MainLecturer = gv;
}

bool ClassSH::add(SinhVien& sv) {
    if (find(sv.getId()) != nullptr) {
        return false;
    }
    ensure(SiSo + 1);

    sinhvien[SiSo++] = sv;
    return true;
}

bool ClassSH::remove(const String& sinhVienID) {
    int pos = -1;
    for (int i = 0; i < SiSo; ++i) {
        if (sinhvien[i].getId() == sinhVienID) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    for (int i = pos; i < --SiSo; ++i) {
        sinhvien[i] = sinhvien[i + 1];
    }

    return true;
}

SinhVien* ClassSH::find(const String& sinhVienID) {
    for (int i = 0; i < SiSo; ++i) {
        if (sinhvien[i].getId() == sinhVienID) {
            return &sinhvien[i];
        }
    }
    return nullptr;
}

const SinhVien* ClassSH::find(const String& sinhVienID) const {
    for (int i = 0; i < SiSo; ++i) {
        if (sinhvien[i].getId() == sinhVienID) {
            return &sinhvien[i];
        }
    }
    return nullptr;
}

SinhVien& ClassSH::operator[](int idx) {
    return sinhvien[idx];
}

const SinhVien& ClassSH::operator[](int idx) const {
    return sinhvien[idx];
}

ClassSH& ClassSH::operator=(const ClassSH& other) {
    if (this == &other) {
        return *this;
    }

    delete[] sinhvien;

    classname = other.classname;
    MainLecturer = other.MainLecturer;
    SiSo = other.SiSo;
    capacity = other.capacity;

    sinhvien = new SinhVien[capacity];
    for (int i = 0; i < SiSo; ++i) sinhvien[i] = other.sinhvien[i];
    return *this;
}

ostream& operator<<(ostream& os, const ClassSH& L) {
    os << "Ten lop: " << L.classname << endl;
    os << "Giang vien phu trach: " << L.MainLecturer.getName() << endl;
    os << "Si so: " << L.SiSo << endl;
    os << "Danh sach sinh vien:" << endl;
    for (int i = 0; i < L.SiSo; ++i) {
        os << i + 1 << ". " << L.sinhvien[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, ClassSH& L) {
    cout << "Nhap ten lop: ";
    is >> L.classname;
    cout << "Nhap thong tin giang vien phu trach:\n";
    is >> L.MainLecturer;

    // Xóa danh sách sinh viên cũ trước khi nhập mới
    L.SiSo = 0; 
    
    int n;
    cout << "Nhap so luong sinh vien: ";
    is >> n;
    
    // Đảm bảo có đủ chỗ
    L.ensure(n);

    cout << "Nhap danh sach sinh vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        SinhVien sv_temp;
        is >> sv_temp;
        L.add(sv_temp);
    }
    
    return is;
}
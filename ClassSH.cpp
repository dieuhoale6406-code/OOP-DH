#include "ClassSH.h"
#include "SinhVien.h"
#include <iostream>

using namespace std;

void ClassSH::ensure(int req) {
    if (capacity >= req) {
        return;
    }
    int newCapacity = (capacity == 0) ? 15 : capacity * 2;
    if (newCapacity < req) newCapacity = req;

    SinhVien* newSinhVien = new SinhVien[newCapacity];

    for (int i = 0; i < SiSo; ++i) {
        newSinhVien[i] = sinhvien[i];
    }

    delete[] sinhvien;

    sinhvien = newSinhVien;
    capacity = newCapacity;
}

ClassSH::ClassSH(): classname(""), MainLecturer(), sinhvien(nullptr), SiSo(0), capacity(0) {}

ClassSH::ClassSH(const String& name, const Lecturer& lecturer)
    : classname(name), MainLecturer(lecturer), sinhvien(nullptr), SiSo(0), capacity(15) {
    sinhvien = new SinhVien[capacity];
}

ClassSH::ClassSH(const ClassSH& Class)
    : classname(Class.classname), MainLecturer(Class.MainLecturer), sinhvien(nullptr), SiSo(Class.SiSo), capacity(Class.capacity) {
    sinhvien = new SinhVien[capacity];
    for (int i = 0; i < SiSo; ++i)
        sinhvien[i] = Class.sinhvien[i];
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

void ClassSH::setLecturer(const Lecturer& lecturer) {
    MainLecturer = lecturer;
}

bool ClassSH::add(const SinhVien& sv) {
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

    for (int i = pos + 1; i < SiSo; ++i) sinhvien[i - 1] = sinhvien[i];
    SiSo--;
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

SinhVien& ClassSH::operator[](int pos) {
    return sinhvien[pos];
}

const SinhVien& ClassSH::operator[](int pos) const {
    return sinhvien[pos];
}

ClassSH& ClassSH::operator=(const ClassSH& Class) {
    if (this == &Class) return *this;

    delete[] sinhvien;
    classname = Class.classname;
    MainLecturer = Class.MainLecturer;
    SiSo = Class.SiSo;
    capacity = Class.capacity;

    sinhvien = new SinhVien[capacity];
    for (int i = 0; i < SiSo; ++i) sinhvien[i] = Class.sinhvien[i];
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ClassSH& L) {
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
    cout << "Nhap thong tin giang vien phu trach: " << endl;
    is >> L.MainLecturer;

    L.SiSo = 0;

    int n;
    cout << "Nhap so luong sinh vien: ";
    is >> n;

    L.ensure(n);

    cout << "Nhap danh sach sinh vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
        SinhVien sv_temp;
        is >> sv_temp;
        L.add(sv_temp);
    }
    return is;
}

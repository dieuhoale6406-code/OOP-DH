#pragma once
#include "String.h"
#include "Lecturer.h"

using namespace std;

class SinhVien;

class ClassSH {
        String classname;
        Lecturer MainLecturer;
        SinhVien* sinhvien;
        unsigned int SiSo;
        int capacity;
        void ensure(int);
    public:
        ClassSH();
        ClassSH(const String&, const Lecturer&);
        ClassSH(const ClassSH&);
        ~ClassSH();

        const String& getClassName() const;
        const Lecturer& getLecturer() const;
        int getSiSo() const;

        void setClassName(const String&);
        void setLecturer(const Lecturer&);

        bool add(const SinhVien&);
        bool remove(const String&);
        SinhVien* find(const String&);
        const SinhVien* find(const String&) const;

        SinhVien& operator[](int idx);
        const SinhVien& operator[](int idx) const;

        ClassSH& operator=(const ClassSH&);

        friend ostream& operator<<(ostream& os, const ClassSH& L);
        friend istream& operator>>(istream& is, ClassSH& L);
};
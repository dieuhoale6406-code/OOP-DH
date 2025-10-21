#pragma once

#include "Person.h"
#include "ClassSH.h"

class ClassSH;

class SinhVien : public Person {
        String mssv;
        double gpa;
        ClassSH* Class;
    public:
        SinhVien();
        SinhVien(const String&, int, const String&, bool, const String& = "1000000000", double = 0.0);
        ~SinhVien();
        
        const String& getId() const;
        double getGPA() const;
        
        void setId(const String&);
        void setGPA(double);
        void setClass(ClassSH*);

        void show() const override;

        friend std::ostream& operator<<(std::ostream&, const SinhVien&);
        friend std::istream& operator>>(std::istream&, SinhVien&);
};
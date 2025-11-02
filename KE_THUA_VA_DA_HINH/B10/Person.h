#pragma once
#include "String.h"

using namespace std;

class Person {
    protected:
        String name;
        int age;
        String address;
        bool gender;
    public:
        Person(const String& = "",int = 0,const String& = "", bool = true);
        ~Person();

        const String& getName() const;
        int getAge() const;
        const String& getAddress() const;
        bool getGender() const;

        void setName(const String&);
        void setAge(int);
        void setAddress(const String&);
        void setGender(bool);

        virtual void show() const;

        friend ostream& operator<<(ostream&, const Person&);
        friend istream& operator>>(istream&, Person&);
};
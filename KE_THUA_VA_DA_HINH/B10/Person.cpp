#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(const String& name, int age, const String& address, bool gender)
    : name(name), age(age), address(address), gender(gender) {}

Person::~Person() {}

const String& Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

const String& Person::getAddress() const {
    return address;
}

bool Person::getGender() const {
    return gender;
}

void Person::setName(const String& name){
    this->name = name;
}

void Person::setAge(int age){
    this->age = age;
}
void Person::setAddress(const String& address){
    this->address = address;
}
void Person::setGender(bool gender){
    this->gender = gender;
}

void Person::show() const{
    cout << "Person: " << (gender ? "Mr. " : "Ms. ") << name << ", " << age << ", " << address << endl;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << "Ho ten: " << p.name << endl;
    os << "Tuoi: " << p.age << endl;
    os << "Dia chi: " << p.address << endl;
    os << "Gioi tinh: " << (p.gender ? "Nam" : "Nu") << endl;
    return os;
}

istream& operator>>(istream& is, Person& p) {
    cout << "Nhap ho ten: ";    
    is >> p.name;
    cout << "Nhap tuoi: ";
    is >> p.age;
    cout << "Nhap dia chi: ";
    is >> p.address;
    cout << "Nhap gioi tinh (Nu: 0, Nam: 1): ";
    is >> p.gender;
    is.ignore(1000,'\n');
    return is;
}
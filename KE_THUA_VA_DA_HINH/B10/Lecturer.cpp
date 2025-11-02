#include "Lecturer.h"
#include <iostream>

using namespace std;

bool Lecturer::is_space(char c) {
    return c == ' ' || c == '\t';
}

static char lowercase(char c) { 
    return (c >= 'A' && c <= 'Z') ? char(c - 'A' + 'a') : c;
}

Lecturer::Lecturer() : Person(), LecturerID("102"), rank("") {}

Lecturer::Lecturer(const String& fullname, int age, const String& address, bool gender,const String& rank)
: Person(fullname, age, address, gender), LecturerID("102"), rank(rank) {
    setId();
}

Lecturer::~Lecturer() {}

const String& Lecturer::getId() const {
    return LecturerID;
}
const String& Lecturer::getRank() const {
    return rank;
}
void Lecturer::setRank(const String& r) {
    rank = r;
}

void Lecturer::setName(const String& newName) {
    Person::setName(newName);
    setId();
}

void Lecturer::setId() {
    const char* fullName = name.getData();
    
    if (!fullName || fullName[0] == '\0') {
        LecturerID = String("102");
        return;
    }
    
    char lowerCaseName[256];
    unsigned int nameLength = 0;
    for (unsigned int i = 0; fullName[i] && nameLength < 255; ++i)
        lowerCaseName[nameLength++] = lowercase(fullName[i]);
    lowerCaseName[nameLength] = '\0';
    
    // Kiểm tra sau khi lowercase
    if (nameLength == 0) {
        LecturerID = String("102");
        return;
    }
    
    char lastName[128] = "";
    char initials[128] = "";

    // vị trí kí tự đầu tiên của tên
    int lastPos = -1;
    for (int i = (int)nameLength - 1; i >= 0; --i) {
        if (is_space(lowerCaseName[i])) {
            lastPos = i + 1;
            break;
        }
    }
    //chữ cái đầu họ & tên đệm
    if (lastPos == -1) lastPos = 0;

    bool isNewWord = true;
    unsigned int initialsPos = 0;
    for (int i = 0; i < lastPos; i++) {
        char curChar = lowerCaseName[i];
        if (!is_space(curChar) && isNewWord) {
            if (initialsPos < 127) initials[initialsPos++] = curChar;
            isNewWord = false; // next vì không phải kí tự đầu
        } else if (is_space(curChar)) isNewWord = true; // bắt đầu kí tự đầu lại
    }
    initials[initialsPos] = '\0';

    // Tên
    unsigned int lastNameLength = 0;
    for (int i = lastPos; i < (int)nameLength && !is_space(lowerCaseName[i]); i++) {
        if (lastNameLength < 127) lastName[lastNameLength++] = lowerCaseName[i];
    }
    lastName[lastNameLength] = '\0';

    LecturerID = String("102");

    if (lastNameLength == 0 && initialsPos == 0) {
        return;
    }
    LecturerID += String(initials) + String(lastName);
}

void Lecturer::show() const {
    cout << "Lecturer " << name << " - " << LecturerID << " (" << rank << ")" << endl;
}

ostream& operator<<(ostream& os, const Lecturer& l) {
    os << static_cast<const Person&>(l);
    os << "Ma so giang vien: " << l.LecturerID << endl;
    os << "Cap bac: " << l.rank << endl;
    return os;
}

istream& operator>>(istream& is, Lecturer& l) {
    is >> static_cast<Person&>(l);
    cout << "Nhap cap bac: ";
    is >> l.rank;
    l.setId();
    return is;
}
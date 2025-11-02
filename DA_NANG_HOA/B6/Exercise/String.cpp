#include "String.h"
#include <cstring>

using namespace std;

String::String() : data(new char[1]{'\0'}), len(0) {}

String::String(const String& str)
    : data(new char[str.len + 1]), len(str.len) {
        strcpy(this->data, str.data);
}

String::String(const char* str)
    : data(new char[len + 1]), len(strlen(str)) {
        strcpy(this->data, str);
}

String::~String() {
    delete[] this->data;
}

String& String::operator=(const String& str) {
    if (this != &str) {
        delete[] this->data;
        this->len = str.len;
        this->data = new char[len + 1];
        strcpy(this->data, str.data);
    }
    return *this;
}

String& String::operator+=(const String& str) {
    char* newstr = new char[this->len + str.len + 1];
    strcpy(newstr, this->data);
    strcat(newstr, str.data);
    delete[] this->data;
    this->data = newstr;
    this->len += str.len;
    return *this;
}

char& String::operator[](unsigned int i) {
    return *(this->data + i);
}

const char& String::operator[](unsigned int i) const {
    return *(this->data + i);
}

bool String::operator==(const String& str) const {
    return strcmp(this->data, str.data) == 0;
}

bool String::operator!=(const String& str) const {
    return !(*this == str);
}

bool String::operator<(const String& str) const {
    return strcmp(this->data, str.data) < 0;
}

bool String::operator>(const String& str) const {
    return strcmp(this->data, str.data) > 0;
}

bool String::operator<=(const String& str) const {
    return !(*this > str);
}

bool String::operator>=(const String& str) const {
    return !(*this < str);
}

ostream& operator<<(std::ostream& o, const String& str) {
    o << str.data;
    return o;
}

istream& operator>>(std::istream& in, String& str) {
    char buffer[1000];
    in.getline(buffer,1000);
    str = String(buffer);
    return in;
}
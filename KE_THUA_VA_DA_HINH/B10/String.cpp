#include "String.h"

using namespace std;

unsigned int String::strlen(const char* str) {
    unsigned int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void String::strcpy(char* s, const char* s1) {
    if(!s) return;
    if(!s1) {
        s[0] = '\0';
        return;
    }
    unsigned int i = 0;
    while(s1[i] != '\0') {
        s[i] = s1[i];
        i++;
    }
    s[i] = '\0';
}

int String::strcmp(const char* s1, const char* s2) {
    if(s1 == s2) return 0;
    if(!s1) return -1;
    if(!s2) return 1;
    unsigned int i = 0;
    while (s1[i] && s2[i]){
        if (s1[i] != s2[i]) return (unsigned char)s1[i] < (unsigned char)s2[i] ? -1 : 1;
        i++;
    }
    if (s1[i] == s2[i]) return 0;
    return s1[i] ? 1 : -1;
}

String::String() : data(new char[1]{'\0'}), len(0) {}

String::String(const String& str)
    : data(new char[str.len + 1]), len(str.len) {
        strcpy(this->data,str.data);
}

String::String(const char* str) : len(strlen(str)), data(new char[len + 1]) {
        strcpy(this->data, str ? str : "");
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
    for (unsigned int i = 0; i < this->len; ++i) newstr[i] = this->data[i];
    for (unsigned int i = 0; i <= str.len; ++i) newstr[this->len + i] = str.data[i];
    delete[] this->data;
    this->data = newstr;
    this->len += str.len;
    return *this;
}

String String::operator+(const String& str) const {
    String result(*this);
    result += str;
    return result;
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
    if (in.peek() == '\n') {
        in.ignore();
    }
    in.getline(buffer,1000);
    str = String(buffer);
    return in;
}

unsigned int String::getSize() const {
    return len;
}

const char* String::getData() const {
    return data;
}
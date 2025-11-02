#pragma once

#include <iostream>

using namespace std;

class String {
    private:
        char *data;
        unsigned int len;

        unsigned int strlen(const char*);
        void strcpy(char*, const char*);
        static int strcmp(const char*, const char*);
    public:
        String();
        String(const String&);
        String(const char*);
        ~String();

        String& operator=(const String&);
        String& operator+=(const String&);
        String operator+(const String&) const;
        
        char& operator[](unsigned int);
        const char& operator[](unsigned int) const;

        bool operator==(const String&) const;
        bool operator!=(const String&) const;
        bool operator<(const String&) const;
        bool operator>(const String&) const;
        bool operator<=(const String&) const;
        bool operator>=(const String&) const;

        friend ostream& operator<<(ostream&,const String&);
        friend istream& operator>>(istream&, String&);

        unsigned int getSize() const;
        const char* getData() const;
};
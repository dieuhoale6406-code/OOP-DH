#include <iostream>

using namespace std;

class String {
    private:
        char *data;
        unsigned int len;
    public:
        String();
        String(const String&);
        String(const char*);
        ~String();

        String& operator=(const String&);
        String& operator+=(const String&);
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
};
#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String s1, s2;
    cin >> s1;
    cin >> s2;

    cout << s1 << endl;
    cout << s2 << endl;

    String s3 = s1;
    cout << s3 << endl;

    s1 += s2;
    cout << "s1 += s2: " << s1 << endl;
    cout << "s2 == s3: " << (s2 == s3 ? "true" : "false") << endl;
    cout << "s2 != s3: " << (s2 != s3 ? "true" : "false") << endl;
    cout << "s2 < s3: " << (s2 < s3 ? "true" : "false") << endl;
    cout << "s2 > s3: " << (s2 > s3 ? "true" : "false") << endl;

    if (s1[0] != '\0')
        cout << "s1[0]: " << s1[0] << endl;

    return 0;
}
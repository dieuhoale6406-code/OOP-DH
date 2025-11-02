#include <iostream>

using namespace std;

class Exp {
    protected:
        string msg;
    public:
        Exp(string = "");
        ~Exp();
        friend ostream& operator<<(ostream&, const Exp&);
};

Exp::Exp(string s) : msg(s) {}

Exp::~Exp() {}

ostream& operator<<(ostream& o, const Exp& e) {
    o << e.msg << endl;
    return o;
}
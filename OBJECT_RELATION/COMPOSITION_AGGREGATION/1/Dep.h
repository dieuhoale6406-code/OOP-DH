#include "Teacher.h"
#include <vector>

using namespace std;

class Dep {
    private:
        string namep;
        // 1 - 1
        // Teacher t;   // Composition
        // Teacher* t; // Aggregation
    public:
        // Dep(const Teacher&, string = "");    // Composition
        Dep(Teacher* = nullptr, string = "");   // Aggregation
        ~Dep();
        friend ostream& operator<<(ostream&,const Dep&);
};

// Dep::Dep(const Teacher& t, string s)
//     : namep(s), t(t) {}  // Composition

Dep::Dep(Teacher* t, string s)
    : namep(s), t(t) {} // Aggregation

Dep::~Dep() {}

// ostream& operator<<(ostream& o, const Dep& d) {  // Composition
//     o << d.t << endl;
//     return o;
// }

ostream& operator<<(ostream& o, const Dep& d) { // Aggregation
    o << *(d.t) << endl;
    return o;
}
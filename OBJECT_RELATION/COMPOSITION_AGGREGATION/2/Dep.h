#include "Teacher.h"
#include <vector>

using namespace std;

class Dep {
    private:
        string namep;
        // 1 - 1
        // Teacher t;   // Composition
        // Teacher* t; // Aggregation
        // 1 - n
        // Vector<Teacher> p;
        vector<Teacher*> p;
    public:
        Dep(string = "");
        ~Dep();
        friend ostream& operator<<(ostream&,const Dep&);
        void AddTeacher(Teacher*);
};

Dep::Dep(string s)
    : namep(s) {}

Dep::~Dep() {
    this->p.clear();
}

ostream& operator<<(ostream& o, const Dep& d) {
    for(int i = 0; i < d.p.size(); i++) {
        o << *(d.p[i]) << endl;
    }
    return o;
}

void Dep::AddTeacher(Teacher* t) {
    this->p.push_back(t);
}
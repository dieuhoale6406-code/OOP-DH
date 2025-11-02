#include <iostream>
using namespace std;
template<typename L>
class List {
    private:
        //L *p;
        //int n;
    public:
        List();
        ~List();
};

template<typename L>
List<L>::List() {
    cout << "List" << endl;
}

template<typename L>
List<L>::~List() {}
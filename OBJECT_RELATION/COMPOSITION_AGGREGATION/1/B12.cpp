#include "Dep.h"
#include <iostream>

using namespace std;

int main() {
    // -- COMPOSITION --
    // -- tạo ra bản sao, khi xóa thì xóa bản sao nằm trong Dep
    // -- (tức delete Teacher trong Dep)
    // Teacher t1("NVA", 31);
    // Dep *d = new Dep(t1, "CNTT");
    // cout << *d;
    // delete d;
    // cout << t1;

    // -- AGGREGATION
    // -- tạo ra con trỏ, khi gọi Dep *d,
    // -- sẽ tạo ra con trỏ trỏ đến chung vùng nhớ với Teacher *t
    // -- khi delete d, sẽ delete con trỏ Teacher của d
    // -- (khác với bản sao)
    Teacher *t = new Teacher("NVA", 31);
    Dep *d = new Dep(t, "CNTT");
    cout << *d;
    delete d;
    cout << *t;

    return 0;
}
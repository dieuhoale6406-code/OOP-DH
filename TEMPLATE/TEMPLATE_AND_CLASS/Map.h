#include <iostream>
#include "List.h"
#include "Point.h"
#include "Vector.h"
using namespace std;
// template<typename K, typename V, template<typename U> class C>
// class Map {
//     private:
//         C<K> key;
//         C<V> value;
//     public:
//         Map();
//         ~Map();
// };

// template<typename K, typename V, template<typename U> class C>
// Map<K, V, C>::Map() {
//     cout << "Map" << endl;
// }

// template<typename K, typename V, template<typename U> class C>
// Map<K, V, C>::~Map() {}

// template class Map<int, double, List>;

template<typename K, typename V, template<typename, int> class C>
class Map {
private:
    C<K, N> key;
    C<V, N> value;
public:
    Map();
    ~Map();
};

// Định nghĩa hàm: PHẢI lặp lại đủ tham số template
template<typename K, typename V, template<typename, int> class C>
Map<K, V, C>::Map() {
    cout << "Map" << endl;
}

template<typename K, typename V, template<typename, int> class C>
Map<K, V, C>::~Map() {}

template class Map<int, Point, Vector>;
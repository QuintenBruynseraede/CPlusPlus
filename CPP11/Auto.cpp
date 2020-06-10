#include <iostream>
#include <typeinfo>
using namespace std;

//decltype support expressions
template <class T,class S>
auto test(T value1, S value2) -> decltype(value1+value2) {
    return value1+value2;
}

template <class T, class S>
auto add(T v1, S v2) -> decltype(v1+v2) {
    return v1+v2;
}

int get() {
    return 999;
}

//Trailing return type ->
auto test2() -> decltype(get()) {
    return get();
}

int main() {
    auto value = 7;

    cout << test(3,4) << endl;
    cout << test(7.2,8.4) << endl;

    cout << test2() << endl;

    cout << add(1,2) << endl;
    cout << add(0.0002,0.005) << endl;
    return 0;
}
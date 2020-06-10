#include <iostream>
#include <typeinfo> //for typeid

using namespace std;

int main() {
    string value;
    
    //Name mangling in C++
    cout << typeid(value).name() << endl;
    
    //Same type as value
    decltype(value) name = "Bob";

    cout << typeid(name).name() << endl;
    cout << name << endl;

    return 0;
}
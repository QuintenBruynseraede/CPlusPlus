#include <iostream>

using namespace std;

class Parent {
public:
    //Copy constructor erases default constructor,
    //Create it manually!
    Parent() {}
    Parent(const Parent &other) {
        cout << "Copy parent" << endl;
    }

    virtual void print() {
        cout << "parent" << endl;
    }

    virtual ~Parent() {

    }
};

class Child: public Parent {
public:
    Child() {}
    Child(const Child &other) {}

    void print() {
        cout << "child" << endl;
    }
};

int main() {
    Child c1;
    //Parent to superclass may point to subclass
    Parent &p1 = c1;
    p1.print();

    //Create child but treat it as superclass,
    //uses copy constructor Parent(const Parent &other)
    //to create Parent object
    Parent p2 = Child();
    p2.print();


}
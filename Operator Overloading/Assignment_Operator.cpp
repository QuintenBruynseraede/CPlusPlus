#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(0), name("") {

    }

    Test(int id, string name): id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }

    const Test& operator=(const Test &other) {
        id = other.id;
        name = other.name;
        cout << "Assignment" << endl;
        //Return reference!
        return *this;
    }

    Test(const Test &other) {
        id = other.id;
        name = other.name;
        cout << "Copy constructor " << endl;
    }
};

int main() {
    Test test1(10,"Mike");
    //test1.print();

    Test test2(20,"Bob");
    //Default shallow copy
    //Copies values of members
    test2 = test1;
    test2.print();

    // = returns references, no void
    Test test3;
    //test3 = test2 = test1;

    //equivalent to =
    test3.operator=(test2);
    test3.print();

    //No assignment operator used?
    //Copy initialization, uses implicit copy constructor
    Test test4 = test1;
    test4.print();

    //Rule of three: if you implement either operator=, 
    //copy constructor or destructor, 
    //you have implement all three!



    return 0;
}
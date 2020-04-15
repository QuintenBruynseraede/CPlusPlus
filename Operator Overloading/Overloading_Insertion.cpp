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
        //Return reference!
        return *this;
    }

    Test(const Test &other) {
        id = other.id;
        name = other.name;
    }



    friend ostream &operator<<(ostream& out,const Test &other){
        out << other.id << ", " << other.name;
        return out;
    }
};

int main() {
    Test test1(10,"Mike");
    Test test2(20,"Bob");

    // << is left-right associative
    //cout << test1 << endl = (cout << test1) << endl
    //Conceptually, doesn't actually work
    //cout << test1 returns ostream
    cout << test1 << " " << test2 << endl;
    
    return 0;
}
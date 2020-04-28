#include <iostream>
using namespace std;


struct Test {
    //Virtual pure function to make Test abstract
    virtual bool operator()(string &test)=0;
};
//All public by default when using struct
//This is a functor, overloads ()
struct MatchTest: public Test {
    virtual bool operator()(string &text) {
        return text=="lion";
    }
};

void check(string text,Test &test) {
    if (test(text)) {
        cout << "Text matches!" << endl;
    }
    else {
        cout << "Text does not match" << endl;
    }
}

int main() {
    MatchTest pred;
    string value = "lion";

    check("lion",pred);
}
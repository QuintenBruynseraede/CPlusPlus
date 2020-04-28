#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(int id, string name): id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }

    //comp() is allowed to access private members!
    friend bool comp(const Test &a, const Test& b);
};

//Use different sorting function in std::sort
bool comp(const Test &a, const Test& b) {
    return a.name < b.name;
}

int main() {
    vector<Test> tests;
    tests.push_back(Test(5,"Mike"));
    tests.push_back(Test(10,"Sue"));
    tests.push_back(Test(7,"Raj"));
    tests.push_back(Test(3,"Vicky"));

    for (int i=0;i<tests.size();i++) {
        tests[i].print();
    }

    //std::sort(from, to)
    //sort(tests.begin(),tests.end());

    sort(tests.begin(),tests.end(),comp);


    return 0;
}
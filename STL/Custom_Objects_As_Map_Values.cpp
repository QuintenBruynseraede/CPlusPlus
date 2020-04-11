#include <iostream>
#include <map>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age) {
        this->age = age;
        this->name = name;
    }

    Person() {
        this->age = 0;
        this->name = "";
    }

    void print() const {
        cout << name << ": " << age << endl;
    }
};

int main() {
    map<int,Person> people;
    people[30] = Person("Mike", 40);
    people[25] = Person("Vicky", 30);
    people[15] = Person("Raj", 20);
    
    for(map<int,Person>::iterator it=people.begin();it!=people.end();it++) {
        cout << it->first << ") " << flush;
        it->second.print();
        //Sorted in order of keys!
    }

    return 0;
}
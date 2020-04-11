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
        cout << name << ": " << age << flush;
    }

    bool operator<(const Person &p2) const {
        return name < p2.name;
    }
};

int main() {
    map<Person,int> people;
    people[Person("Mike", 40)] = 40;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    //Changes value of (Mike, 40) because 
    //these keys are equal!
    people[Person("Mike",50)] = 50;

    
    
    for(map<Person,int>::iterator it=people.begin();it!=people.end();it++) {
        cout << it->second << ") " << flush;
        it->first.print();
        cout << endl;
        //Sorted in order of keys!
    }

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

class Person {
public:
    Person(string name, int age): age(age), name(name) {

    }
    void print() const{
        cout << name << ", " << age << " years old." << endl;
    }

    bool operator<(const Person &p2) const {
        return name < p2.name;
    }
    bool operator==(const Person &p2) const {
        return (name == p2.name && age == p2.age);
    }

private:
    string name;
    int age;
};

int main() {
    set<int> numbers;
    set<Person> people;

    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);

    for (set<int>::iterator it=numbers.begin();it!=numbers.end();it++) {
       cout << *it << endl;
    }
    cout << endl;

    //Insert duplicate changes nothing
    numbers.insert(1);
    
    set<int>::iterator itFind = numbers.find(1);
    if (itFind != numbers.end()) {
        cout << "Found 1!" << endl;
    }

    //numbers.count(x) return 1 if present, 0 otherwise
    if (numbers.count(30)) {
        cout << "30 found" << endl;
    }

    for (set<int>::iterator it=numbers.begin();it!=numbers.end();it++) {
       cout << *it << endl;
    }
    cout << endl;

    people.insert(Person("Mike",40));
    people.insert(Person("John",80));
    people.insert(Person("Sue",20));

    for (auto it2=people.begin();it2!=people.end();it2++) {
        it2->print();
    }

    //Already present because only comparing name
    people.insert(Person("Mike",90));
   

    return 0;
}
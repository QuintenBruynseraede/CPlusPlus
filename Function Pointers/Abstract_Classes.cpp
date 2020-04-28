#include <iostream>

using namespace std;

class Animal {
public:
    //=0 means pure virtual function,
    //A class containing only pure virtual function is abstract
    virtual void speak()=0;
    virtual void run()=0;
};

class Dog: public Animal {
public:
    //In order to be able to instantiate Dog,
    //we MUST implement ALL pure virtual functions
    virtual void speak() {
        cout << "Woof" << endl;
    }
};

class Labrador: public Dog {
public:
    Labrador() {
        cout << "Constructor of labrador" << endl;
    }
    virtual void run() {
        cout << "Labrador running" << endl;
    }
};


void test(Animal &a) {
    a.run();
}

int main() {
    //Can't instantiate, has 2 pure virtual functions
    //Animal animal;

    //Can't instantiate, has 1 pure virtual functions
    //Dog dog;

    //Can instantiate, no pure virtual functions
    Labrador l;
    l.speak();
    l.run();


    //Instantiates 5 labradors,
    //so cannot create array of abstract class
    Labrador labs[5];

    //Can create array of pointers to animals!
    Animal *animals[5];
    animals[0] = &l;

    test(l);

    return 0;
}
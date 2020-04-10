#include <iostream>
#include <exception>
#include <bits/stdc++.h> 
using namespace std;

class MyException: public exception {
public:
    virtual const char* what() const throw() {
        return "Something happened\n";
    }
};

class BadNameException: public exception {
public:
    BadNameException(string name) {
        this->name = name;
    }
    virtual const char* what() {
        const char* msgGeneral = "Bad name: ";
        const char* msgSpecific = this->name.c_str();
        char* msg = new char[strlen(msgGeneral) + strlen(msgSpecific)+1];
        strcpy(msg,msgGeneral);
        strcat(msg,msgSpecific);
        return msg;
    }
private:
    string name;
};

class Name {
public:
    Name(string newName) {
        if (newName == "Jan") {
            throw BadNameException(newName);
        }
        else {
            this->name = newName;
            cout << "Successfully set name " << this->name << endl;
        }
    } 
private:
    string name;
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

int main() {
    try {
        Name n = Name("Piet");
        Name n2 = Name("Jan");
    }
    catch(BadNameException &e) {
        cout << e.what() << endl;
    }
}
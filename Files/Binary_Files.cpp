#include <iostream>
#include <fstream>

using namespace std;

//Struct to write to file
//All members are public by default!
//Structs are padded for efficiency
//#pragma pack(push,1) disables this padding
//Struct is now aligned in chunks of 1 bytes
#pragma pack(push,1)
struct Person {
    char name[50];
    int age;
    double weight;
};
//Re-enable padding as normal
#pragma pack(pop)


int main() {
    Person me = {"Quinten", 21,73.0};
    string fileName = "test.bin";

    /**
    WRITE FILE 
    **/

    ofstream output;
    output.open(fileName, ios::binary);
    if (!output.is_open()) {
        cout << "Error opening " << fileName << endl;
        return 1;
    }


    //output.write((char *)&me,sizeof(Person));
    output.write(reinterpret_cast<char *>(&me),sizeof(Person));
    output.close();

    /**
    READ FILE 
    **/

    ifstream input;
    input.open(fileName, ios::binary);
    if (!input.is_open()) {
        cout << "Error opening " << fileName << endl;
        return 1;
    }

    Person newPerson;
    input.read(reinterpret_cast<char *>(&newPerson),sizeof(Person));
    cout << newPerson.name << endl;
    cout << newPerson.age << endl;
    cout << newPerson.weight << endl;


    return 0;
}
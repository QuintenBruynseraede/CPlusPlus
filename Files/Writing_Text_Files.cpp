#include <iostream>
#include <fstream>
//File stream
using namespace std;

int main() {
    //ofstream out;
    //OR
    fstream out;

    string fileName = "output.txt";
    string lines[] = {"First line", "Second line", "Third line"};
    
    //If using ofstream, ios::out not necessary
    out.open(fileName, ios::out);
    if (out.is_open()) {
        int i = 0;
        for (i=0;i<3;i++) {
            out << lines[i] << endl;
        }
    }
    else {
        cout << "Could not create file " << fileName << endl;
    }

    return 0;
}
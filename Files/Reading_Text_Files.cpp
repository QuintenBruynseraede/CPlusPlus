#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in;
    in.open("output.txt");
    if (in.is_open()) {
        string line;
        
        //ifstream as boolean return whether eof()!
        while (in) {
            getline(in,line);
            cout << line << endl;
        }
        in.close();
    }
    else {
        cout << "Couldn't open file." << endl;
    }


    return 0;
}
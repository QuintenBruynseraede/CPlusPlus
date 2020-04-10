#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in;
    in.open("stats.txt");

    if (!in.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    while (in) {
        string line;
        getline(in,line,':');
        
        int population;
        in >> population;


        //Get \n char
        in.get();

        cout << line << " --- " << population << endl;
    }

    in.close();
    return 0;
}
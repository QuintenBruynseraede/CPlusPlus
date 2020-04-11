#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> strings;
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    cout << "Iterate manually" << endl;
    //Iterate manually
    for (int i=0;i<strings.size();i++) {
        cout << strings[i] << endl;
    }

    cout << "Iterate using iterator" << endl;
    //std::vector::Iterator
    vector<string>::iterator it = strings.begin();
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it++;
    cout << *it << endl;

    cout << "Iterate using iterator in loop" << endl;
    for(vector<string>::iterator it = strings.begin();it!=strings.end();it++) {
        cout << *it << endl;
    }

    cout << "Iterate backwards using iterator in loop" << endl;
    for(vector<string>::iterator it = strings.end();it!=strings.begin();it--) {
        cout << *(it-1) << endl;
    }

    



    return 0;
}
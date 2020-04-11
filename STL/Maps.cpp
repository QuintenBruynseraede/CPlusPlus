#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string,int> ages;
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    cout << "Age of Raj: " << ages["Raj"] << endl;
    cout << "Age of John: " << ages["John"] << endl;
    //This adds John! Not really how we'd like it

    if(ages.find("Vicky123") != ages.end()) {
        cout << "Found Vicky123" << endl;
    }
    else {
        cout << "Could not find Vicky123" << endl;
        //Didn't add Vicky123!
    }

    cout << endl;
    for(map<string,int>::iterator it=ages.begin();it!=ages.end();it++) {
        pair<string,int> age = *it;
        cout << age.first << ": " << age.second << endl;
    }

    //Can also add using pair<string,int> or make_pair()
    ages.insert(pair<string,int>("Peter",100));
    ages.insert(make_pair("Peter2",100));


    cout << endl;
    for(map<string,int>::iterator it=ages.begin();it!=ages.end();it++) {
        cout << it->first << ": " << it->second << endl;
    }


    return 0;
}
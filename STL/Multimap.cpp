#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<int,string> lookup;
    lookup.insert(make_pair(30,"Mike"));
    lookup.insert(make_pair(10,"Vicky"));
    lookup.insert(make_pair(30,"Raj"));
    lookup.insert(make_pair(20,"Bob"));
    //Mike and Raj both fall under key 30

    for (multimap<int,string>::iterator it=lookup.begin();it!=lookup.end();it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    //Find finds only the first occurrence
    for (multimap<int,string>::iterator it=lookup.find(10);it!=lookup.end();it++) {
        cout << it->first << ": " << it->second << endl; 
    }

    cout << endl;

    //equal_range returns two iterators: first and last occurrence of key
    auto its = lookup.equal_range(30);
    for (multimap<int,string>::iterator it=its.first;it!=its.second;it++) {
        cout << it->first << ": " << it->second << endl; 
    }

    return 0;
}
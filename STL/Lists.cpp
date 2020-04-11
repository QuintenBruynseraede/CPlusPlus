#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it=numbers.begin();
    cout << "Element: " << *it << endl;
    numbers.insert(it,100);
    cout << "Element: " << *(--it) << endl;
    numbers.erase(it);
    //it is now undefined! Don't use anymore
    //use it = numbers.erase(it) to do this
    
    for(list<int>::iterator it=numbers.begin();it!=numbers.end();it++) {
        cout << *it << endl;
    }

    return 0;
}
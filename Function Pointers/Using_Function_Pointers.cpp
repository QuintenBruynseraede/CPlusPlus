#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
    return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*f)(string test)) {
    int res = 0;
    for (vector<string>::iterator it=texts.begin();it!=texts.end();it++) {
        if ( f(*it)) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << count_if(texts.begin(),texts.end(),match) << endl;
    cout << countStrings(texts,match) << endl;

    return 0;
}
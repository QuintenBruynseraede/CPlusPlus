#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    //Map of lists
    map<string, vector<int>> scores;

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20);
    scores["Vicky"].push_back(15);
    scores["Vicky"].push_back(17);

    //Remember: in maps, it->first and it->second
    for (map<string, vector<int>>::iterator it=scores.begin();it!=scores.end();it++) {
        string name = it->first;
        vector<int> scoreList = it->second;

        cout << name << ": " << flush;
        for (auto it2=scoreList.begin();it2!=scoreList.end();it2++) {
            cout << *it2 << " " << flush;
        }
        cout << endl;
    }
    return 0;
}
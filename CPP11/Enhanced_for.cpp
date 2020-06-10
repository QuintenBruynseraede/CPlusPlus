#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto texts = {"One","Two","Three"};
    for (auto text : texts) {
        cout << text << endl;
    }

    //Can also iterate over vectors
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(11);
    numbers.push_back(12);
    numbers.push_back(13);
    numbers.push_back(14);
    numbers.push_back(15);
    numbers.push_back(16);


    for (auto x : numbers) {
        cout << x << endl;
    }

    //Iterate over chars in string
    //Doesn't work with auto (which creates *char[])
    string value = "STRING";
    for (auto c : value) {
        cout << c << endl;
    }

    return 0;
}
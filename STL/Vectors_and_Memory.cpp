#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> numbers;

    //Size: number of elements present
    cout << "Size: " << numbers.size() << endl;

    //Capacity: number of elements possible before resizing
    //1 2 4 8 16 32 64 ...
    // = size of internal array
    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;
    for (int i=0;i<10000;i++) {
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "New capacity: " << capacity << endl;
        }
        numbers.push_back(i);
    }

    //Clear removes elements, doesn't change capacity
    numbers.clear();
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    //Changes size
    numbers.resize(100);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    cout << numbers[2] << endl;
    cout << numbers[110] << endl; //Still exists!

    //Changes capacity!
    numbers.reserve(1000000);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    cout << numbers[2] << endl;
    cout << numbers[110] << endl; //Still exists!
   


    return 0;
}
#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[990000000000009];
        delete [] pMemory;
        value = 4;
    }
    
    int value;
    int getValue() {
        return value;
    }
};

int main() {
    try {
        CanGoWrong wrong;
    }
    catch(bad_alloc &e) {
         cout << "Caught exception: " << e.what() << endl;
         
    }
    
    return 0;
}
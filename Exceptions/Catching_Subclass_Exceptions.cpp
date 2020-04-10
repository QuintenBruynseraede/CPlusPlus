#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
    bool error1 = true;
    bool error2 = false;

    if (error1) {
        throw bad_alloc();
    }

    if (error2) {
        throw exception();
    }
}

int main() {
    try {
        goesWrong();
    }
    //Catch more specific exception first!
    catch (bad_alloc &e) {
        cout << "Bad alloc: " << e.what() << endl;
    }
    catch (exception &e) {
        cout << "Exception: " << e.what() << endl;
    }


    return 0;
}
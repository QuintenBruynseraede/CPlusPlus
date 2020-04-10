#include <iostream>
using namespace std;

void mightGoWrong() {
    bool error1 = false;
    bool error2 = false;
    bool error3 = true;

    if (error1) {
        throw "Hello";
    }
    if (error2) {
        throw 8;
    }
    if (error3) {
        throw string("Hellostring");
    }
}

void usesMightGoWrong() {
    mightGoWrong();
}

int main() {
    try {
        mightGoWrong();
    }
    catch (int e) {
        cout << "Caught int exception: " << e << endl;
    }
    catch (char const* e) {
        cout << "Caught char exception: " << e << endl;
    }
    catch(string &e) {
        cout << "Caught string exception: " << e << endl;
    }
    
    cout << "Finished" << endl;

    return 0;
}
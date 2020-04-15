#include <iostream>
#include "Complex.h"

using namespace std;
using namespace cpp;

int main() {
	Complex c1 = Complex(1,1);
	Complex c2 = Complex(1,1);
	Complex c3 = Complex(1,3);
	Complex c4 = Complex(1,0);
	cout << 1+c1+1 << endl;

	cout << c4 << endl;
	cout << *c1 << endl;
}

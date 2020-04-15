#include <iostream>

using namespace std;


//Template class
template<class T>
class Test {
private:
	T obj;
public:
	Test(T obj) {
		this->obj = obj;
	}
	void print() {
		cout << obj << endl;
	}
};

//Template Function
template<class K>
void print(K output) {
	cout << "[Template] " << output << endl;
}

//Regular function
void print(int out) {
	cout << "[Non-template] " << out << endl;
}

//Template Function
template<class K>
void show() {
	cout << "[Template] " << K() << endl;
}

int main() {
	print<int>(3);
	print(3);	//Uses non-template function
	print<>(3); //Uses template function
	print<int>(3); //Uses template function

	//Only way to call show
	//show() and show<>() don't have enough information
	//because K is derived from argument list
	show<double>();

	return 0;
}

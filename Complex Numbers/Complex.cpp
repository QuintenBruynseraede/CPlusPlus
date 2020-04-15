#include "Complex.h"
#include <iostream>
#include <ostream>

using namespace std;
namespace cpp {

	Complex::Complex(): real(0), imaginary(0) {}
	Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}
	Complex::Complex(const Complex& other) {
			real = other.real;
			imaginary = other.imaginary;
		}
	bool Complex::operator<(const Complex& other) const {
		if (real < other.real) {
			return true;
		}
		else if (real > other.real) {
			return false;
		}
		else {
			if (imaginary < other.imaginary) {
				return true;
			}
			else if (imaginary > other.imaginary) {
				return false;
			}
			else {
				return false;
			}
		}
	}
	void Complex::print() const {
		cout << real << "+" << imaginary << "i" << endl;
	}

	const Complex& Complex::operator=(const Complex& other) {
		real = other.real;
		imaginary = other.imaginary;
		return *this;
	}

	Complex operator+(const Complex &c1, const Complex &c2) {
		return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
	}


	ostream& operator<<(ostream& out,const Complex& other) {
		if (other.getImaginary() > 0)
			out << other.real << "+" << other.imaginary << "i";
		else if (other.getImaginary() < 0)
			out << other.real << "-" << -other.imaginary << "i";
		else
			out << other.real;

		return out;
	}

	Complex operator+(const Complex& c1, const double n) {
		return Complex(c1.getReal()+n,c1.getImaginary());
	}
	Complex operator+(const double n, const Complex& c1) {
		return Complex(c1.getReal()+n,c1.getImaginary());
	}

	bool operator==(const Complex& c1, const Complex& c2) {
		return (c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary());
	}

	bool operator!=(const Complex& c1, const Complex& c2) {
		return (c1.getReal() != c2.getReal() || c1.getImaginary() != c2.getImaginary());
	}

	Complex operator*(const Complex& c1) {
		return Complex(c1.getReal(),-c1.getImaginary());
	}



}

#pragma once

#include <string>

using namespace std;

class ComplexNumber {
private:
	int real;
	int imag;
public:
	ComplexNumber(int real, int imag);
	void setReal(int real);
	void setImag(int imag);
	int getReal();
	int getImag();
	string getComplex();
	friend string getComplexExp(ComplexNumber number);
protected:
};

#include <iostream>
#include <string>
#include <math.h>
#include <locale.h>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber(int real, int imag)
{
	this->real = real;
	this->imag = imag;
}

void ComplexNumber::setReal(int real)
{
	this->real = real;
}

void ComplexNumber::setImag(int imag)
{
	this->imag = imag;
}

int ComplexNumber::getReal()
{
	return this->real;
}

int ComplexNumber::getImag()
{
	return this->imag;
}

string ComplexNumber::getComplex()
{
	return "COM.NUM = " + to_string(this->real) + " + " + to_string(this->imag) + "i";
}

string getComplexExp(ComplexNumber number)
{
	return "COM.NUM.EXP = " + to_string(number.getReal()) + " e^" + to_string(number.getImag());
}

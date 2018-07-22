#include <iostream>
#include <string>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include "ComplexNumber.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	ComplexNumber num1(1, 2);
	ComplexNumber num2(2, 3);
	ComplexNumber num3(3, 4);

	cout << "COMPLEX NUMBERS:" << endl;
	cout << num1.getComplex() << endl;
	cout << num2.getComplex() << endl;
	cout << num3.getComplex() << endl;

	cout << endl;

	cout << "UPDATE COMPLEX NUMBER:" << endl;
	cout << "BEFORE :" << num1.getComplex() << endl;
	num1.setImag(num2.getImag());
	num1.setReal(num3.getReal());
	cout << "AFTER :" << num1.getComplex() << endl;

	cout << endl;

	cout << "COMPLEX NUMBERS IN EXP FORMAT" << endl;
	cout << getComplexExp(num1) << endl;
	cout << getComplexExp(num2) << endl;
	cout << getComplexExp(num3) << endl;

	cout << endl;

	system("pause");
	return 0;
}
/*
Лабараторная работа №2
Задание №2
Написать программу, котороая ждёт ввода занака арифмитической операции и,
в зависимости от введённого символа, вычисляет значение произвольного
арифметического выражения.
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	float a, b;
	cout << "Введите a и b:\n";
	cin >> a >> b;
	cout << "Введите знак арифметической операции:\n";
	char n;
	cin >> n;
	float r;

	switch(n)
	{
	case '+':
		r = a + b;
		cout << a << "+" << b << "=" << r << endl;
		break;
	case '-':
		r = a - b;
		cout << a << "-" << b << "=" << r << endl;
		break;
	case '*':
		r = a * b;
		cout << a << "*" << b << "=" << r << endl;
		break;
	case '/':
		r = a / b;
		cout << a << "/" << b << "=" << r << endl;
		break;
	default:
		cout << "Это не так работает...\n" << endl;
	}
		
	system("pause");
	return 0;
}

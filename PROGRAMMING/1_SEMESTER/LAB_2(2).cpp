/*
������������ ������ �2
������� �2
�������� ���������, �������� ��� ����� ������ �������������� �������� �,
� ����������� �� ��������� �������, ��������� �������� �������������
��������������� ���������.
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
	cout << "������� a � b:\n";
	cin >> a >> b;
	cout << "������� ���� �������������� ��������:\n";
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
		cout << "��� �� ��� ��������...\n" << endl;
	}
		
	system("pause");
	return 0;
}

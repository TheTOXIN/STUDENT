/*
������������ ������ �5
������� �1
����� �� ��������� ��������� ����������� ����� � ������������
������ ����. ��� ����������� ����� ���� ����� ������� �������.
*/

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

int summa(int a)
{
	int sum = 0;
	while (a != 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int main()
{
	setlocale(0, "RUS");

	int a = 0, b = 0, max = 0;
	do
	{
		cout << "������� ���������: " << endl;
		cin >> a >> b;
	}
	while (a > b);

	max = summa(a);
	for (; a <= b; a++)
	{
		if (max <= summa(a))
			max = summa(a);
	}
	cout <<"������������ ����� ���� ����� �� ���������: "<< max << endl;

	system("pause");
	return 0;
}


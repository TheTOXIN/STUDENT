/*
������������ ������ �3
������� �1
����� ����� ������ ������������� ����� �� ����������
�� A �� B, ������� (A � B �������� � ����������).
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int a, b, sum = 0;
	cout << "������� ���������� �� � �� � \n";
	cin >> a >> b;

	while (a <= b)
	{
		if (a % 4 == 0)
			 sum =+ a;
		a++;
	}
	cout << "�����: " << sum << endl;
	system("pause");
	return 0;
}

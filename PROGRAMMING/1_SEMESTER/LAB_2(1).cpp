/*
������������ ������ �2
������� �1
����� ������� �������������� ��� �����. ���� ��� ������ 
��������� ����� A, �� �������� ��� � �������, ����� �������.
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	float x, y, z, a;
	cout << "������� 3 �����: \n";
	cin >> x >> y >> z;
	cout << "������� ��������� ����� A: \n";
	cin >> a;
	float n = (x + y + z) / 3;

	if (n > a)
	{
		cout << "������� �������������� ��� �����\n������ ���������� ����� �...  \n ";
		n = pow(n, 2);
	}
	else
	{
		cout << "������� �������������� ��� �����\n������ ��� ����� ���������� ����� �... \n";
		n *= 2;
	}

	cout << "�����: " << n << endl;
	system("pause");
	return 0;
}

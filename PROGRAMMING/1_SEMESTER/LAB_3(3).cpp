/**************************************************
-������������ ������ 3
-�a����� � 3
-��� �������� m � x ��������� ����� ������� (1+x)m
��������������� � �� ������� ���������� � ���: ...
��� ���������� "C" ����� ������������ ������������
������� ���������.
***************************************************/

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

long double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

int main()
{
	setlocale(0, "RUS");

	int x, m, sum = 0;
	double s;

	cout << "������� x: " << endl;
	cin >> x;
	cout << "������� m: " << endl;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		s = fact(m) / fact(x)*fact(m - x)*pow(x, i);
		sum += s;
	}

	cout << "���������: " << sum << endl;

	system("pause");
	return 0;
}
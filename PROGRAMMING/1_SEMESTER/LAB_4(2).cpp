/*
������������ ������ �4
������� �2
����������, ���� �� � ������ ������� ������, ��������� ������
�� ���������, ������������� ���������� �� A �� B. 
A � B �������� � ����������.
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	const int n = 4, m = 4;
	int M[m][n];

	srand((unsigned)time(NULL));

	cout << "�������: " << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = rand() % 15;
			if (M[i][j] <= 9)
				cout << M[i][j] << "   ";
			else
				cout << M[i][j] << "  ";
		}
		cout << endl;
	}

	int A, B, sum = 0;
	cout << "������� ����������: " << endl;
	cin >> A >> B;

	for (int i = 0; i < m; i++)
	{
		sum = 0;

		for (int j = 0; j < n; j++)
		{
			if (M[i][j] >= A && M[i][j] <= B)
			{
				sum += 1;
			}
			else
				break;
		}

		if (sum == 4)
		{
			cout << "TRUE" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

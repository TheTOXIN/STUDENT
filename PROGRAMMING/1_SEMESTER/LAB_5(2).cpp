/*
������������ ������ �5
������� �2
������� ������� ������������ ��������� ����������� �������
� �������  ���������� ��������� ����� � ����������� ����������
���������� � ������� �������� ����������� � ����������� �������� �����.
��������:  2 3 2 4 5 4 7 8 9 - ����� ��������� ���, ��� 3 � 5.
*/

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Array(int n1, int A1[])
{
	for (int i = 0; i < n1; i++)
		A1[i] = rand() % 30;
}

void Func(int n1, int A1[])
{
	int sum = 0;
	cout << "��������� � ������� �������� ����������� � ����������� �������� �����: ";
	for (int i = 0; i < n1; i++)
	{
		if (A1[i] == A1[i + 2])
		{
			cout << A1[i + 1] << ' ';
			sum++;
		}
	}
	cout << endl << "����� ����� ����������: " << sum << endl;
}

int main()
{
	setlocale(0, "RUS");
	srand((unsigned)time(NULL));

	cout << "������� ������ �������: " << endl;
	int n;
	cin >> n;
	int A[100];
	Array(n, A);

	cout << "��� ������: " << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << ' ';

	cout << endl;
	Func(n, A);

	system("pause");
	return 0;
}

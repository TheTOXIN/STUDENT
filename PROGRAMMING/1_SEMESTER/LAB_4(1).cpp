/*
Лабараторная работа №4
Задание №1
Даны два целочисленных массива одинаковой размерности n, Получить третий массив той же
размерности, каждый элемент которого равен большему из соответствующих элементов
данного массива. Например, даны массивы A и B, получим массив C:
i- 0 1 2 3 4
A- 14 2 7 8 9
B- 3 6 5 12 4 
C- 14 6 7 12 9
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

	const int n = 5;
	int A[n];
	int B[n];
	int max;
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		A[i] = rand()%15;
		cout<<A[i]<<" ";
	}

	cout<<endl;

	for (int i = 0; i < n; i++)
	{
		B[i] = rand()%15;
		cout<<B[i]<<" ";
	}

	cout<<endl;

	for ( int i = 0; i < n; i++)
	{
		if (A[i]>=B[i])
		{
			max = A[i];
		cout<<max<<" ";
		}
		else
		{
			max = B[i];
		cout<<max<<" ";
		}

	}

	system("pause");
	return 0;
}

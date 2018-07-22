/*
Лабараторная работа №5
Задание №2
Описать функцию формирования элементов одномерного массива
с помощью  генератора случайных чисел и определения количсетва
эелементов у которых занчения предыдущего и последущего элемента равны.
Напримир:  2 3 2 4 5 4 7 8 9 - таких элементов два, это 3 и 5.
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
	cout << "Эелементы у которых занчения предыдущего и последущего элемента равны: ";
	for (int i = 0; i < n1; i++)
	{
		if (A1[i] == A1[i + 2])
		{
			cout << A1[i + 1] << ' ';
			sum++;
		}
	}
	cout << endl << "Всего таких эелементов: " << sum << endl;
}

int main()
{
	setlocale(0, "RUS");
	srand((unsigned)time(NULL));

	cout << "Введите рамзер массива: " << endl;
	int n;
	cin >> n;
	int A[100];
	Array(n, A);

	cout << "Ваш массив: " << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << ' ';

	cout << endl;
	Func(n, A);

	system("pause");
	return 0;
}

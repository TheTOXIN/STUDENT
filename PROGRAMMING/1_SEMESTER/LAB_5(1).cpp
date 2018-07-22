/*
Лабараторная работа №5
Задание №1
Найти из заданного диапазона наутральное число с максимальной
суммой цифр. Для определения суммы цифр числа описать функцию.
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
		cout << "Введите диапазона: " << endl;
		cin >> a >> b;
	}
	while (a > b);

	max = summa(a);
	for (; a <= b; a++)
	{
		if (max <= summa(a))
			max = summa(a);
	}
	cout <<"Максимальная сумма цифр числа из диапазона: "<< max << endl;

	system("pause");
	return 0;
}


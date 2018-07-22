/*
Лабараторная работа №3
Задание №1
Найти сумму целвых положительных чисел из промежутка
от A до B, кратных (A и B вводятся с клавиатуры).
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
	cout << "Введите промежуток от А до В \n";
	cin >> a >> b;

	while (a <= b)
	{
		if (a % 4 == 0)
			 sum =+ a;
		a++;
	}
	cout << "Вывод: " << sum << endl;
	system("pause");
	return 0;
}

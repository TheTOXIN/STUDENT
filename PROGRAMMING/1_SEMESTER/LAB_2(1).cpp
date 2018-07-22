/*
Лабараторная работа №2
Задание №1
Найти среднее арифмитическое трёх чисел. Если оно больше 
некторого числа A, то возвести его в квадрат, иначе удвоить.
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
	cout << "Введите 3 числа: \n";
	cin >> x >> y >> z;
	cout << "Введите некоторое чсило A: \n";
	cin >> a;
	float n = (x + y + z) / 3;

	if (n > a)
	{
		cout << "Среднее арифмитическое трёх чисел\nбольше некоторого числа А...  \n ";
		n = pow(n, 2);
	}
	else
	{
		cout << "Среднее арифмитическое трёх чисел\nменьше или равно некоторому числу А... \n";
		n *= 2;
	}

	cout << "Вывод: " << n << endl;
	system("pause");
	return 0;
}

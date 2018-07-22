/*
Лабараторная работа №3
Задание №2
Составить программу вычислеиня суммы членов бесконечного ряда
с погрешностью E=0.0001. Определить количество членов ряда,
сравнить полученное значение суммы со значением функции
y = arctg(x), |x|<1.
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	double y = 0, S = 0, x = 0, sum = 0, E = 0.0001;
	int n = 0;

	cout << "Введите x: " << endl;
	cin >> x;

	do
	{
		S = pow(-1, n)*(pow(x, 2 * n + 1) / (2 * n + 1));
		sum = sum + S;
		n++;
	} while (exp(S)>E);

	cout << "Функция 1 = " << sum << endl;

	if (fabs(x) < 1)
		y = atan(x);
	else
		y = 0;

	cout << "Функция 2 = " << y << endl;

	system("pause");
	return 0;
}
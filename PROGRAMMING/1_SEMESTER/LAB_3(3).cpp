/**************************************************
-Лабараторная работа 3
-Зaдание № 3
-Для заданных m и x вычислить бином Ньютона (1+x)m
непосредственно и по формуле разложения в ряд: ...
Для вычисления "C" можно использовать классическую
формулу сочетаний.
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

	cout << "Введите x: " << endl;
	cin >> x;
	cout << "Введите m: " << endl;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		s = fact(m) / fact(x)*fact(m - x)*pow(x, i);
		sum += s;
	}

	cout << "Результат: " << sum << endl;

	system("pause");
	return 0;
}
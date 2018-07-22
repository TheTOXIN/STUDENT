/*
Лабараторная работа №3
Задание №4
Вычислить уравнение с точностью e=0.01
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double s = 0, z = 0, e = 0.01;

	for (int i = 1; i <= 10; i++)
	{
		double sum = 0;
		int j = 1;

		do
		{
			s = (i*pow(j, 2) - 4.3) / pow(i*j, 3);
			sum = sum + s;
			j++;
		} 
		while (fabs(s) > e);

		z = z + sum * i;
	}

	cout << z << endl;

	system("pause");
	return 0;
}

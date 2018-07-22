#include <iostream>
#include <string>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include "Matrix.h"

using namespace std;

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Matrix a(2, 2);
	Matrix b(2, 2);

	cin >> a;
	cin >> b;

	Matrix c = a - b;
	++c;

	cout << a;
	cout << b;
	cout << c;

	system("pause");
	return 0;
}
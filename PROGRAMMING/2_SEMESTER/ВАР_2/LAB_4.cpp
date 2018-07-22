#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

int** maker(int m, int n)
{
	int** t = new int*[m];
	for (int i = 0; i < m; i++)
	{
		t[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			t[i][j] = rand() % 18 - 9;
		}
	}
	return t;
}

void printer(int m, int n, int **matr)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << matr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int m, n;
	cout << "Введите размер матриц M x N: " << endl;
	cin >> m >> n;

	cout << "Матрица А :" << endl;
	int **A = maker(m, n);
	printer(m, n, A);

	cout << "Матрица B :" << endl;
	int **B = maker(m, n);
	printer(m, n, B);

	cout << "Матрица C :" << endl;
	int** C = new int*[m*2];
	int namber = 0;
	for (int i = 0; i < m*2; i++)
	{
		C[i] = new int[n*2];
		for (int j = 0; j < n*2; j++)
		{
			if (namber % 2 == 0)
				C[i][j] = A[i/2][j/2];
			else
				C[i][j] = B[i/2][j/2];
			namber++;
		}
	}
	printer(m*2, n*2, C);
	
	for (int i = 0; i < m; i++)
		delete[] A[i];
	for (int i = 0; i < m; i++)
		delete[] B[i];
	for (int i = 0; i < m*2; i++)
		delete[] C[i];
	delete[] A;
	delete[] B;
	delete[] C;

	system("pause");
	return 0;
}
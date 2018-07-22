#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

struct Students
{
	char FIO[20];
	int age;
	char reg[20];
	char fak[20];
};

struct Region
{
	char name[20];
	int count;
};

void input(Students studArray[], int kol)
{
	for (int i = 0; i < kol; i++)
		cin >> studArray[i].FIO >> studArray[i].age >> studArray[i].reg >> studArray[i].fak;
	cout << endl;
}

void output(Students studArray[], int kol)
{
	for (int i = 0; i < kol; i++)
		cout << studArray[i].FIO << ": " << studArray[i].age << " " << studArray[i].reg << " " << studArray[i].fak << endl;
	cout << endl;
}

int main()
{
	const int kol = 3;
	Students studArray[kol];
	Region regArray[kol];

	cout << "Input: FIO, age, region, fakultet " << kol << " students:" << endl;
	input(studArray, kol);
	cout << "ArrayList Students:" << endl;
	output(studArray, kol);

	int n = 0;
	for (int i = 0; i<kol; i++)
	{
		bool b = true;
		for (int j = 0; j < n; j++)
		{
			if (!strcmp(regArray[j].name, studArray[i].reg))
			{
				b = false;
				regArray[j].count++;
			}
		}
		if (b)
		{
			strcpy_s(regArray[n].name, studArray[i].reg);
			regArray[n].count = 1;
			n++;
		}
	}

	cout << "Regions: " << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << regArray[i].name << " = " << regArray[i].count << endl;

	system("pause");
	return 0;
}
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

const int kol = 5;
typedef char String[100];

void input(String txt[kol], String s)
{	
	ofstream fout(s);
	for (int i = 0; i < kol; i++)
	{
		cin >> txt[i];
		fout << txt[i] << endl;
	}
}

void output(String txt[kol], String s)
{
	ofstream fout(s);
	for (int i = 0; i < kol; i++)
	{
		cout << txt[i] << endl;
		fout << txt[i] << endl;
	}
}

void swap(String txt_1[kol], String txt_2[kol])
{
	int max_1 = 0, min_1 = 0, max_2 = 0, min_2 = 0;

	for (int i = 0; i < kol; i++)
	{
		if (strlen(txt_1[i]) >= strlen(txt_1[max_1]))
			max_1 = i;
		if (strlen(txt_1[i]) <= strlen(txt_1[min_1]))
			min_1 = i;

		if (strlen(txt_2[i]) >= strlen(txt_2[max_2]))
			max_2 = i;
		if (strlen(txt_2[i]) <= strlen(txt_2[min_2]))
			min_2 = i;
	}

	String tmp_max_1, tmp_min_1;

	strcpy_s(tmp_max_1, txt_1[max_1]);
	strcpy_s(tmp_min_1, txt_1[min_1]);

	strcpy_s(txt_1[min_1], txt_2[max_2]);
	strcpy_s(txt_1[max_1], txt_2[min_2]);

	strcpy_s(txt_2[min_2], tmp_max_1);
	strcpy_s(txt_2[max_2], tmp_min_1);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Введите текст № 1" << endl;
	String txt_1[kol];
	input(txt_1, "text_1.txt");

	cout << "Введите текст № 2" << endl;
	String txt_2[kol];
	input(txt_2, "text_2.txt");

	cout << "Замена самой длинной и короткой строчки в текстах: " << endl;
	swap(txt_1, txt_2);

	cout << "Текст №1: " << endl;
	output(txt_1, "text_1.txt");

	cout << "Текст №2: " << endl;
	output(txt_2, "text_2.txt");

	system("pause");
	return 0;
}
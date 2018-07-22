#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

typedef char String[100];
String tickets;
String win_tickets;
const int N = 4;
int count_tickiets;
int count_tickiets_win = 0;
int A[N];

void create_list_tickets()
{
	cout << "Введите имя файла:" << endl;
	cin >> tickets;
	ofstream fout(tickets, ios::binary);

	cout << "Введите количество билетов:" << endl;
	cin >> count_tickiets;
	cout << "Введите номера билетов:" << endl;

	for (int i = 0; i < count_tickiets; i++)
	{
		cout << "Номер - " << i + 1 << endl;
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];
		}
		fout.write((char*)A, sizeof(A));
	}
	fout.close();
}

void print_list_ticket(String s, int n)
{
	ifstream fin(s, ios::binary);
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". ";
		fin.read((char*)A, sizeof(A));

		for (int j = 0; j < N; j++)
		{
			cout << A[j];
		}
		cout << endl;
	}
	fin.close();
}

void create_list_win_tickets()
{
	cout << "Введите имя файла:" << endl;
	cin >> win_tickets;
	ofstream fout(win_tickets, ios::binary);
	ifstream fin(tickets, ios::binary);
	for (int i = 0; i < count_tickiets; i++)
	{
		fin.read((char*)A, sizeof(A));
		int sum = 0;
		for (int j = 0; j < N - 1; j++)
		{
			sum += A[j];
		}
		if (sum == 8)
		{
			count_tickiets_win++;
			fout.write((char*)A, sizeof(A));
		}
	}
	fout.close();
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");

	create_list_tickets();
	cout << "Номера билетов:" << endl;
	print_list_ticket(tickets, count_tickiets);

	create_list_win_tickets();
	cout << "Номера выигрышных билетов:" << endl;
	print_list_ticket(win_tickets, count_tickiets_win);

	system("pause");
	return 0;
}
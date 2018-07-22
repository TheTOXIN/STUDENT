#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

struct Node;
typedef Node* ptrNode;
struct Node
{
	char FIO[30];
	int mark;
	ptrNode next;
};
ptrNode first1 = NULL;
ptrNode first2 = NULL;

void addFirst(ptrNode& first,char[30] tmp int mark)
{
	ptrNode p = new Node;
	p->FIO = tmp;
	p->mark = mark;
	p->next = first;
	first = p;
}

void inputList(ptrNode& first)
{
	int n, mark;
	char tmp[30];
	cout << "Введите кол-во студентов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите фамилию и среднею оценку студента: ";
		cin >> tmp;
		cin >> mark;
		addFirst(first, tmp, mark);
	}
}

void printList(ptrNode& first)
{
	ptrNode p = first;
	while (p)
	{
		cout << p->FIO << ' - ' << p->mark << endl;
		p = p->next;
	}
	cout << endl;
}

void func(ptrNode& first)
{
	ptrNode p = first;
	while (p)
	{
		
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	cout <<"Заполните список студентов" << endl;
	inputList(first1);
	cout << "Ваш список студентов" << endl;
	printList(first1);

	//func(first1);

	//cout << "Список студентов с средней оценкой < 4" << endl;
	//printList(first2);

	system("pause");
	return 0;
}
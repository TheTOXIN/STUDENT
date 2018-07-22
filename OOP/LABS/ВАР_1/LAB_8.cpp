#include <iostream>
#include <set>
#include <string.h>

using namespace std;

//�������� ������
struct student
{
	char* fio;
	int kurs;
	//����������� ������
	student(char* f, int k)
	{
		fio = f;
		kurs = k;
	}
};

//���������� �������� < ��� �������� ��������� ��������
bool operator <(const student s1, const student s2)
{
	if (strcmp(s1.fio, s2.fio)<0)
		return true;
	return false;
}

void main()
{
	//������� ������ ��������� ���������
	set<student> s;
	//������� 4 ������� ������
	student st1("Petrov", 3);
	student st2("Ivanov", 1);
	student st3("Sidorov", 2);
	student st4("Petrov", 4);

	//��������� ��������� ������� � ���������
	s.insert(st1);
	s.insert(st2);
	s.insert(st3);
	s.insert(st4);

	//�������� ���������� ��������� � ������� ���������
	set<student>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
		cout << (*it).fio << ' ' << (*it).kurs << endl;
}

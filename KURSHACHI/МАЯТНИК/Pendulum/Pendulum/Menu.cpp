#include "Menu.h"
#include "iostream"
#include "Settings.h"

using namespace std;

Menu::Menu()//����������� �� ����������� ����
{
	isExit = false;
}

void Menu::showMenu()//���������� ����
{
	system("cls");
	cout << "_Project_�������_" << endl;
	cout << "1.�������� �������" << endl;
	cout << "2.��������� �������" << endl;
	cout << "3.��������� �� ���������" << endl;
	cout << "4.��������� ��������" << endl;
	cout << "5.�����" << endl;
	cout << "CHOOSE -> ";
}

void Menu::inputChoose(Settings & s)//���������� ��������
{
	cin >> choose;
	switch (choose)
	{
		case 1: isExit = true; break;
		case 2: s.inputDate(); break;
		case 3: s.defaultSet(); break;
		case 4: s.randomSet(); break;
		case 5: exit(0); break;
		default: cout << "TRY AGAIN..."; break;
	}
}


#include "Menu.h"
#include "iostream"
#include "Settings.h"

using namespace std;

Menu::Menu()//конуструтор дл консольного меню
{
	isExit = false;
}

void Menu::showMenu()//отображаем меню
{
	system("cls");
	cout << "_Project_МАЯТНИК_" << endl;
	cout << "1.Запусить маятник" << endl;
	cout << "2.Настроить маятник" << endl;
	cout << "3.Настроить по умолчанию" << endl;
	cout << "4.Настроить случайно" << endl;
	cout << "5.Выход" << endl;
	cout << "CHOOSE -> ";
}

void Menu::inputChoose(Settings & s)//считывание значений
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


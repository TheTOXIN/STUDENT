#pragma once

#include "Settings.h"

class Menu//класс меню в консоли
{
public:
	Menu();
	int choose;//номер пункта
	bool isExit;//выход
	void showMenu();//отображние
	void inputChoose(Settings & s);//считывание
};
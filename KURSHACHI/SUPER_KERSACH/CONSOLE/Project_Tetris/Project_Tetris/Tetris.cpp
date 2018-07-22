#include "stdafx.h"
#include "Tetris.h"
#include "conio.h"
#include "iostream"
#include "windows.h"

CGame CTetris::game(10, 20);

CGame CTetris::getGame()
{
	return game;
}

void CTetris::removeBeep()
{
	for (int i = 0; i < 3; i++)
		Beep(1000, 10);
}

void CTetris::landBeep()
{
	Beep(400, 50);
}

void CTetris::clearConsole()
{
	system("cls");
}

void CTetris::waitPUSH()
{
	std::cout << "Press any button..." << std::endl;
	if (_getch())
	{
		Sleep(10);
	}
}

void CTetris::mainSleep()
{
	Sleep(100);
}

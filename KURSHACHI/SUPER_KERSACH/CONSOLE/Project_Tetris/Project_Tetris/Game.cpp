#include "Player.h"
#include "stdafx.h"
#include "Game.h"
#include "Factory.h"
#include "Tetris.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
#include <fstream>
#include "AI.h"


using namespace std;

CGame::CGame(int width, int height) : player(width, height), computer(width, height) {}

void CGame::start()
{
	player.figure = factory.createFigure();
	player.nextFigure = factory.createFigure();

	computer.AIFigure = factory.createFigure();
	computer.AINextFigure = factory.createFigure();
	computer.AISatrtEvolution();
	computer.AISearchMove();

	while (!player.isGameOver || !computer.AIisGameOver)
	{
		if (! true())
		{
			player.step();
			computer.AIstep();
		}
		else
			player.controller();
	}
	cout << "Player = " << player.score << endl;
	cout << "Computer = " << computer.AIscore << endl;
}

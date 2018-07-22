#include "Player.h"
#include "stdafx.h"
#include "Game.h"
#include "Factory.h"
#include "Tetris.h"
#include "Field.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
#include "AI.h"

using namespace std;

CPlayer::CPlayer(int width, int height) :
	figure(width / 2 - 1, 0, 4, 0, CTetris::game.factory.space),
	nextFigure(width / 2 - 1, 0, 4, 0, CTetris::game.factory.space),
	field(width, height)
{
	isGameOver = false;
}

void CPlayer::step()
{
	if (!isGameOver)
	{
		figure.down();
		if (!figure.isCurrentPos(field))
		{
			figure.up();
			figure.land(field);
			isGameOver = figure.getY() <= 0;
			score += field.remove();
			figure = nextFigure;
			nextFigure = CTetris::game.factory.createFigure();
		}
	}
	CTetris::game.printer.print(field, figure, nextFigure, 0, score);
}

void CPlayer::controller()
{
	if (!isGameOver)
	{
		switch (_getch())
		{
		case 72: figure.rotate(field); break;//ROTATE
		case 80: figure.downMax(field); break;//DOWN
		case 75: figure.left(field); break;//LEFT
		case 77: figure.right(field); break;//RIGHT
		}
	}
}

#include "Player.h"
#include "stdafx.h"
#include "Game.h"
#include "Factory.h"
#include "Tetris.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
#include "AI.h"
#include "Genetic.h"

using namespace std;

CComputer::CComputer(int width, int height) :
	AIFigure(width / 2 - 1, 0, 4, 0, CTetris::game.factory.space),
	AINextFigure(width / 2 - 1, 0, 4, 0, CTetris::game.factory.space),
	AIBestFigure(width / 2 - 1, 0, 4, 0, CTetris::game.factory.space),
	AIField(width, height),
	AIGenetic(width, height)
{
	AIisGameOver = false;
}


void CComputer::AIstep()
{
	if (!AIisGameOver)
	{
		AIController();
		AIFigure.down();
		if (!AIFigure.isCurrentPos(AIField))
		{
			AIFigure.up();
			AIFigure.land(AIField);
			AIisGameOver = AIFigure.getY() <= 0;
			AIscore += AIField.remove();
			AIFigure = AINextFigure;
			AINextFigure = CTetris::game.factory.createFigure();
			AISearchMove();
		}
	}
	CTetris::game.printer.print(AIField, AIFigure, AINextFigure, 40, AIscore);
}

void CComputer::AIController()
{
	if (AIFigure.r < AIBestFigure.r) {
		AIFigure.rotate(AIField);
	}

	if (AIFigure.x > AIBestFigure.x) {
		AIFigure.left(AIField);
	}

	if (AIFigure.x < AIBestFigure.x) {
		AIFigure.right(AIField);
	}

	if (AIFigure.x == AIBestFigure.x && AIFigure.r == AIBestFigure.r) {
		AIFigure.downMax(AIField);
	}
}

void CComputer::AISatrtEvolution()
{
	AIGenetic.evolution();
}

void CComputer::AISearchMove()
{
	AIGenetic.GFigure = AIFigure;
	AIGenetic.GField = AIField;
	AIGenetic.searchMove(AIGenetic.bestCondidate);
	AIBestFigure = AIGenetic.bestFigrue;
}



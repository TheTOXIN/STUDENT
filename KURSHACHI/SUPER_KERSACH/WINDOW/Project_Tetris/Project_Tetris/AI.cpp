#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Factory.h"
#include "Tetris.h"
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

void CComputer::initialize()
{
	AIFigure = CTetris::game.factory.createFigure(0);
	AINextFigure = CTetris::game.factory.createFigure(AIFigure.index);
	AIField.clearField();
	AIisGameOver = false;
	AIscore = 0;
	AISearchMove();
}

void CComputer::AIstep(int gameMode)
{
	if (!AIisGameOver)
	{
		if (gameMode == 3)
			AIController();
		if (gameMode == 4)
			AIFigure = AIBestFigure;
		AIFigure.down();

		if (!AIFigure.isCurrentPos(AIField))
		{
			AIFigure.up();
			AIFigure.land(AIField);
			AIisGameOver = AIFigure.getY() <= 1;
			if (AIField.countLines() != 0)
			{
				CMediaPlayer::playSoundRemove();
				AIscore += AIField.remove();
			}
			if (!AIisGameOver)
			{
				AIFigure = AINextFigure;
				AINextFigure = CTetris::game.factory.createFigure(AIFigure.index);
				AISearchMove();
			}
		}
	}
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



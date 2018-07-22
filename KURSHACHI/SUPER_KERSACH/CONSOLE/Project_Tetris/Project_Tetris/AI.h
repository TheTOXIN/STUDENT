#pragma once

#include "Field.h"
#include "Figure.h"
#include "Printer.h"
#include "Factory.h"
#include "Genetic.h"

class CComputer
{
public:
	CComputer(int width, int height);
	CField AIField;
	CFigure AIFigure;
	CFigure AINextFigure;
	CFigure AIBestFigure;
	CGenetic AIGenetic;
	bool AIisGameOver;
	int AIscore;
	void AIstep();
	void AIController();
	void AISatrtEvolution();
	void AISearchMove();
private:
};


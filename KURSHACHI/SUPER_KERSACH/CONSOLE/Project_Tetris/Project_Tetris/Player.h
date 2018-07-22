#pragma once

#include "Field.h"
#include "Figure.h"
#include "Printer.h"
#include "Factory.h"

class CPlayer
{
public:
	CPlayer(int width, int height);
	CField field;
	CFigure figure;
	CFigure nextFigure;
	bool isGameOver;
	int score;
	void step();
	void controller();
private:
};
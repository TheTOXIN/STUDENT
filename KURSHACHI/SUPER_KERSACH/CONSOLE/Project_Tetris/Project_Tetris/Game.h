#pragma once

#include "Factory.h"
#include "Field.h"
#include "Figure.h"
#include "Printer.h"
#include "AI.h"
#include "Player.h"

class CGame
{
public:
	CGame(int width, int height);
	int temp;
	CComputer computer;
	CPlayer player;
	CFactory factory;
	CPrinter printer;
	void start();
private:
};

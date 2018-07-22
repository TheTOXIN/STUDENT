#pragma once

#include "Game.h"

class CTetris
{
public:
	static CGame getGame();
	static CGame game;
	static void mainSleep();
	static void removeBeep();
	static void landBeep();
	static void clearConsole();
	static void waitPUSH();
private:
};
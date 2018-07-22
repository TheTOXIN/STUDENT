#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "Factory.h"
#include "Field.h"
#include "Figure.h"
#include "Game.h"
#include "Printer.h"
#include "stdlib.h"
#include "time.h"
#include "Tetris.h"
#include "fstream"

using namespace std;

int main()
{
	CTetris tetris;
	CGame &game = tetris.getGame();
	game.start();
		
	system("pause");
    return 0;
}


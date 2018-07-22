#pragma once

#include "iostream"
#include "string.h"
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;
using namespace std;

class Label//функция лейбла, отображает настроки в окне
{
public:
	int x;
	int y;
	int size;
	Font font;//шрифт
	Text info;//текст с информацией
	Text text1;//остальные тексты
	Text text2;
	Text text3;
	Text text4;
	Text text5;
	Text cursor;//курсор
	Label(Settings & s);//конструктор
	void updateText(Text & text, int pos, string str);//обновление текста
	void updateLabel(Settings & s);//обновление лейбла
	void drawLabel(RenderWindow & window);//рисование лейбла
};
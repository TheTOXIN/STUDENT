#include "Label.h"

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;
using namespace std;

Label::Label(Settings & s)//конструктор вызывается при создани
{
	size = 50;//ставим координаты и рамзер
	x = 400;
	y = 150;
	
	font.loadFromFile("pixels.otf");//загружаем шрифт

	updateLabel(s);//обновляем
}

void Label::updateLabel(Settings & s)//обновлние лейбла
{
	string angel = "ANGEL = " + to_string(s.TMP_ANGEL);//создаем строчки
	string rotate = "ROTATE = " + to_string(s.GEARS_ROTATE);
	string length = "LENGTH = " + to_string(s.PENDULUM_SIZE);
	string weight = "WEIGHT = " + to_string(s.WEIGHT);
	
	string state = "";//создаем нужную строчку от состония
	if (s.isStop)
	{
		state = "STOP";
		text3.setFillColor(Color::Red);
	} 
	else
	{
		state = "START";
		text3.setFillColor(Color::Green);
	}
	//обрезаем строчки
	angel = angel.substr(0, 16);
	rotate = rotate.substr(0, 16);
	length = length.substr(0, 16);
	weight = weight.substr(0, 16);
	//обновляем их
	updateText(text1, 0, angel);
	updateText(text2, 1, rotate);
	updateText(text3, 2, state);
	updateText(text4, 3, length);
	updateText(text5, 4, weight);
	//настраиваем курсор
	cursor.setPosition(x - size, (y - size) + size * s.choose);
	cursor.setFont(font);
	cursor.setCharacterSize(size);
	cursor.setFillColor(Color::Red);
	cursor.setString("-> ");
	//создаем доп.инфу
	string info_str = "info : h/c = " + to_string(s.ANGLE_FREQURANCY);
	info.setPosition(10, 570);
	info.setFont(font);
	info.setCharacterSize(20);
	info.setFillColor(Color::Yellow);
	info.setString(info_str);
}

void Label::updateText(Text & text, int pos, string str)//функция для обновления текста
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(x, y + size * pos);
	text.setString(str);
}

void Label::drawLabel(RenderWindow & window)//отрисовка лейбла
{
	for (int i = 1; i <= 3; i++)
	{
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(cursor);
		window.draw(info);
	}
}

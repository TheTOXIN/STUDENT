#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Gearbox//класс шестеренки
{
public:
	RectangleShape * gear1;//у нас их 2 штуки
	RectangleShape * gear2;

	void iniGearbox(Texture & gearTexture, Settings & s);//функция для инициализации
	void rotateGears(Settings & s);//поворот шестеренок
	void DrawGearbox(RenderWindow & window);//рисуем шестеренки
	void dispGearbox();//очистка памяти
};


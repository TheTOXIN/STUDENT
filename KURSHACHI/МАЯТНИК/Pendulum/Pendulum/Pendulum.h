#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

enum StatePendulum //перечесление сосотояний маятника
{ 
	Pendulum_Left, 
	Pendulum_Rigth 
};

class Pendulum
{
public:
	RectangleShape* line;//линия 
	ConvexShape* body;//тело (грузик)
	
	void iniPendulum(Settings & s);//инициализация значние
	void updatePendulum(Settings & s);//обновление значений
	void PendulumSetAngle(float angle);//установка угла
	void RotatePendulum(float time, StatePendulum state, Settings & s);//поворот
	void DrawPendulum(RenderWindow & window);//рисовние
	void dispPendulum();//очистка памяти
};



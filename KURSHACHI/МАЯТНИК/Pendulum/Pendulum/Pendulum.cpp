#include "Pendulum.h"
#include "Settings.h"
#include <iostream>

using namespace std;

void Pendulum::updatePendulum(Settings & s)//обновление маятника
{
	this->line->setSize((Vector2f(5, 15 * s.PENDULUM_SIZE)));//ставим рамзер
	//рисуем тело для грузика через 4 точки(четырехугольник)
	this->body->setPoint(0, Vector2f(0.5 * s.PENDULUM_SIZE, 15 * s.PENDULUM_SIZE));;
	this->body->setPoint(1, Vector2f(1 * s.PENDULUM_SIZE, 16 * s.PENDULUM_SIZE));
	this->body->setPoint(2, Vector2f(1.5 * s.PENDULUM_SIZE, 15 * s.PENDULUM_SIZE));
	this->body->setPoint(3, Vector2f(1 * s.PENDULUM_SIZE, 14 * s.PENDULUM_SIZE));
	//стаивм ему рамзер и позицю
	this->body->setOrigin(Vector2f(1 * s.PENDULUM_SIZE, 0 * s.PENDULUM_SIZE));
	this->body->setScale(s.WEIGHT, 1);
}

void Pendulum::iniPendulum(Settings & s)//инициализация маятника
{
	//тоже смое что и в обнолвнии
	this->line = new RectangleShape;
	this->line->setSize((Vector2f(5, 15 * s.PENDULUM_SIZE)));
	this->line->setOutlineColor(Color::White);
	this->line->setFillColor(Color::White);
	this->line->setOrigin(Vector2f(2.5, 0 * s.PENDULUM_SIZE));
	this->line->setPosition(s.PENDULUM_POSITION);
	
	this->body = new ConvexShape;
	this->body->setPointCount(4);
	this->body->setPoint(0, Vector2f(0.5 , 15 * s.WEIGHT));;
	this->body->setPoint(1, Vector2f(1 * s.PENDULUM_SIZE, 16 * s.PENDULUM_SIZE));
	this->body->setPoint(2, Vector2f(1.5 , 15 * s.WEIGHT));
	this->body->setPoint(3, Vector2f(1 * s.PENDULUM_SIZE, 14 * s.PENDULUM_SIZE));
	this->body->setOutlineColor(Color::White);
	this->body->setFillColor(Color::White);
	this->body->setOrigin(Vector2f(1 * s.PENDULUM_SIZE, 0 * s.PENDULUM_SIZE));
	this->body->setPosition(s.PENDULUM_POSITION);

	this->body->setScale(s.WEIGHT, 1);
}

void Pendulum::PendulumSetAngle(float angle)//установка на нужный угол
{
	this->body->setRotation(angle);
	this->line->setRotation(angle);
}

void Pendulum::RotatePendulum(float time, StatePendulum state, Settings & s)//поворот маятника
{
	if (state == Pendulum_Left)//поворачивам в зависимости от состояния
	{
		PendulumSetAngle(-s.MAX_ANGLE);
		this->body->rotate(s.ANGLE_FREQURANCY * time);
		this->line->rotate(s.ANGLE_FREQURANCY * time);
	}
	else
	{
		PendulumSetAngle(s.MAX_ANGLE);
		this->body->rotate(-s.ANGLE_FREQURANCY * time);
		this->line->rotate(-s.ANGLE_FREQURANCY * time);
	}
}

void Pendulum::DrawPendulum(RenderWindow & window)//рисуем маятник
{
	window.draw(*this->body);
	window.draw(*this->line);
}

void Pendulum::dispPendulum()//очистка памяти
{
	delete this->body;
	delete this->line;
}

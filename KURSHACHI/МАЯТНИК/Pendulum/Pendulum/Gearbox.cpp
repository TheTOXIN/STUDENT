#include "Gearbox.h"
#include "Settings.h"

void Gearbox::iniGearbox(Texture & gearTexture, Settings & s)//иницализация шестеренок
{
	this->gear1 = new RectangleShape(Vector2f(10 * s.GEAR_SIZE, 10 * s.GEAR_SIZE));//создаем их
	this->gear2 = new RectangleShape(Vector2f(10 * s.GEAR_SIZE, 10 * s.GEAR_SIZE));
	//ставим текстуры и позицю
	this->gear1->setTexture(&gearTexture);
	this->gear1->setOrigin(5 * s.GEAR_SIZE, 5 * s.GEAR_SIZE);
	this->gear1->setPosition(5 * s.GEAR_SIZE, 5 * s.GEAR_SIZE);

	this->gear2->setTexture(&gearTexture);
	this->gear2->setOrigin(5 * s.GEAR_SIZE, 5 * s.GEAR_SIZE);
	this->gear2->setPosition(11.5 * s.GEAR_SIZE, 11.5 * s.GEAR_SIZE);
}

void Gearbox::rotateGears(Settings & s)//поворот 
{
	this->gear1->rotate(s.GEARS_ROTATE);
	this->gear2->rotate(-s.GEARS_ROTATE);
}

void Gearbox::DrawGearbox(RenderWindow & window)//рисуем
{
	window.draw(*this->gear1);
	window.draw(*this->gear2);
}

void Gearbox::dispGearbox()//очитска
{
	delete this->gear1;
	delete this->gear2;
}
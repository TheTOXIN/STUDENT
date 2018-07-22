#pragma once

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

class Settings//класс настроек
{
public:
	Settings();//конструктор

	int choose;//пункт выбора
	bool isStop;//остановка

	int GEAR_SIZE;//размер шистеренок
	int PENDULUM_SIZE ;//длина маятника

	Vector2f PENDULUM_POSITION;//позиция

	float TMP_ANGEL;//угол для настройки
	float WEIGHT;//вес
	float GEARS_ROTATE;//поворот шестеренок
	float ANGLE_FREQURANCY;//частота угла
	float MAX_ANGLE;//максимальный угол
	float PENDULUM_PERIOD;//период
	float STOPPED_GEARS_TIME;//остоновка шестеренок

	void readKey(Event & event);//считывнаие клавиш
	void inputDate();//ввод дынных
	void defaultSet();//установка парметров по умолчанию
	void updateSet();//обновлние параметров
	void randomSet();//случайные парматры
	void checkStop();//проврека для остановки
};

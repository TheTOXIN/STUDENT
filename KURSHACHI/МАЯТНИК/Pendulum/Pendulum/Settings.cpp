#define _USE_MATH_DEFINES

#include "Settings.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>

using namespace sf;
using namespace std;

Settings::Settings()//����������� ��� ��������
{
	choose = 1;
	isStop = false;
	defaultSet();
}

void Settings::readKey(Event & event)//������� ��� ���������� � ��������� ������
{
	if (event.type == sf::Event::KeyPressed)//���� ���� ������ ����� ������� �� ��������� �����
	{
		if (event.key.code == Keyboard::Up)//����� ��� ������� ����� ��� ����
			choose--;//�������� ������� ������
		if (event.key.code == Keyboard::Down)
			choose++;
		//�������� ��� ����� �� ������� �� �������
		if (choose < 1)
			choose = 1;
		if (choose > 5)
			choose = 5;
		//� ����������� �� ������ �������� ������ ��������� ��� �������� ����� ��� ������
		switch (choose)
		{
		case 1: //��������� ���� ���������
			if (event.key.code == Keyboard::Right)
				TMP_ANGEL += 1;
			else if (event.key.code == Keyboard::Left)
				TMP_ANGEL -= 1;
			if (TMP_ANGEL <= 0)
				TMP_ANGEL = 0;
		break;

		case 2://������� ����������
			if (event.key.code == Keyboard::Right)
				GEARS_ROTATE += 0.1;
			else if (event.key.code == Keyboard::Left)
				GEARS_ROTATE -= 0.1;
			if (GEARS_ROTATE <= 0)
				GEARS_ROTATE = 0;
		break;
			
		case 3://��������� 
			if (event.key.code == Keyboard::Right || event.key.code == Keyboard::Left)
			{
				isStop = !isStop;
				checkStop();
			}
		break;

		case 4://������
			if (event.key.code == Keyboard::Right)
				PENDULUM_SIZE += 1;
			else if (event.key.code == Keyboard::Left)
				PENDULUM_SIZE -= 1;
			if (PENDULUM_SIZE <= 0)
				PENDULUM_SIZE = 0;
		break;

		case 5://���
			if (event.key.code == Keyboard::Right)
				WEIGHT += 0.5;
			else if (event.key.code == Keyboard::Left)
				WEIGHT -= 0.5;
			if (WEIGHT <= 0)
				WEIGHT = 0;
		break;
		}
	}
}

void Settings::inputDate()//���� ������ � ���������� ����
{
	cout << "-=������� ������-=" << endl;

	cout << "GEAR_SIZE : ";
	cin >> GEAR_SIZE;

	cout << "PENDULUM_SIZE : ";
	cin >> PENDULUM_SIZE;

	cout << "GEARS_ROTATE : ";
	cin >> GEARS_ROTATE;

	cout << "TMP_ANGEL : ";
	cin >> TMP_ANGEL;

	cout << "WEIGHT : ";
	cin >> WEIGHT;
}

void Settings::updateSet()//��������� ����������
{
	if (!isStop)
	{
		ANGLE_FREQURANCY = TMP_ANGEL * sqrt(PENDULUM_SIZE / WEIGHT);//������� �� ��������� ��� ������� 
		MAX_ANGLE = ANGLE_FREQURANCY / 2.f;//�������� ������������ ����
	}
}

void Settings::defaultSet()//���������� �� ���������
{
	GEAR_SIZE = 20;
	PENDULUM_SIZE = 35;
	WEIGHT = 1;

	PENDULUM_POSITION = Vector2f(12.425 * GEAR_SIZE, 0 * GEAR_SIZE);//������ ������

	TMP_ANGEL = 20.f;
	GEARS_ROTATE = 0.15f;
	ANGLE_FREQURANCY = TMP_ANGEL;
	MAX_ANGLE = ANGLE_FREQURANCY / 2.f;
	PENDULUM_PERIOD = 2.f / ANGLE_FREQURANCY * float(M_PI * M_PI);//������ �� ��������� ��� �������
	STOPPED_GEARS_TIME = PENDULUM_PERIOD * 0.1f;
}

void Settings::randomSet()//�������� ���������
{
	TMP_ANGEL = (float)(rand() % 100);
	GEAR_SIZE = rand() % 50;
	PENDULUM_SIZE = rand() % 50;
	WEIGHT = rand() % 10;

	PENDULUM_POSITION = Vector2f(12.425 * GEAR_SIZE, 0 * GEAR_SIZE);

	GEARS_ROTATE = (float)(rand() / double(RAND_MAX));
	ANGLE_FREQURANCY = TMP_ANGEL;

	MAX_ANGLE = ANGLE_FREQURANCY / (float)(rand() % 10);
	PENDULUM_PERIOD = (float)(rand() % 10) / ANGLE_FREQURANCY * float(M_PI * M_PI);
	STOPPED_GEARS_TIME = PENDULUM_PERIOD * (float)(rand() / double(RAND_MAX));
}

void Settings::checkStop()//�������� � ��������� ��������
{
	if (isStop)
	{
		GEARS_ROTATE = 0.f;
		ANGLE_FREQURANCY = 0.f;
		PENDULUM_PERIOD = 0.f;
		MAX_ANGLE = 0.f;
		STOPPED_GEARS_TIME = 0.f;
		
	}
	else
	{
		isStop = false;
		defaultSet();
	}
}

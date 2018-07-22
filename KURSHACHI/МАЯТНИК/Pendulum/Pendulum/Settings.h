#pragma once

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

class Settings//����� ��������
{
public:
	Settings();//�����������

	int choose;//����� ������
	bool isStop;//���������

	int GEAR_SIZE;//������ ����������
	int PENDULUM_SIZE ;//����� ��������

	Vector2f PENDULUM_POSITION;//�������

	float TMP_ANGEL;//���� ��� ���������
	float WEIGHT;//���
	float GEARS_ROTATE;//������� ����������
	float ANGLE_FREQURANCY;//������� ����
	float MAX_ANGLE;//������������ ����
	float PENDULUM_PERIOD;//������
	float STOPPED_GEARS_TIME;//��������� ����������

	void readKey(Event & event);//���������� ������
	void inputDate();//���� ������
	void defaultSet();//��������� ��������� �� ���������
	void updateSet();//��������� ����������
	void randomSet();//��������� ��������
	void checkStop();//�������� ��� ���������
};

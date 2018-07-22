#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

enum StatePendulum //������������ ���������� ��������
{ 
	Pendulum_Left, 
	Pendulum_Rigth 
};

class Pendulum
{
public:
	RectangleShape* line;//����� 
	ConvexShape* body;//���� (������)
	
	void iniPendulum(Settings & s);//������������� �������
	void updatePendulum(Settings & s);//���������� ��������
	void PendulumSetAngle(float angle);//��������� ����
	void RotatePendulum(float time, StatePendulum state, Settings & s);//�������
	void DrawPendulum(RenderWindow & window);//��������
	void dispPendulum();//������� ������
};



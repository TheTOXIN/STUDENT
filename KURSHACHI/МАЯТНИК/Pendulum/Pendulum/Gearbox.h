#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Gearbox//����� ����������
{
public:
	RectangleShape * gear1;//� ��� �� 2 �����
	RectangleShape * gear2;

	void iniGearbox(Texture & gearTexture, Settings & s);//������� ��� �������������
	void rotateGears(Settings & s);//������� ����������
	void DrawGearbox(RenderWindow & window);//������ ����������
	void dispGearbox();//������� ������
};


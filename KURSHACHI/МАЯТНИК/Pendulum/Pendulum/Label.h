#pragma once

#include "iostream"
#include "string.h"
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;
using namespace std;

class Label//������� ������, ���������� �������� � ����
{
public:
	int x;
	int y;
	int size;
	Font font;//�����
	Text info;//����� � �����������
	Text text1;//��������� ������
	Text text2;
	Text text3;
	Text text4;
	Text text5;
	Text cursor;//������
	Label(Settings & s);//�����������
	void updateText(Text & text, int pos, string str);//���������� ������
	void updateLabel(Settings & s);//���������� ������
	void drawLabel(RenderWindow & window);//��������� ������
};
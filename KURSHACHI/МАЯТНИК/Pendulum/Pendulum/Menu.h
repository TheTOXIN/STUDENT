#pragma once

#include "Settings.h"

class Menu//����� ���� � �������
{
public:
	Menu();
	int choose;//����� ������
	bool isExit;//�����
	void showMenu();//����������
	void inputChoose(Settings & s);//����������
};
#include "Pendulum.h"
#include "Gearbox.h"
#include "Settings.h"
#include "Label.h"
#include "Menu.h"
#include "time.h"
#include "locale.h"

void process(Clock & clock, StatePendulum & state, Gearbox & gearSet, Pendulum & pendulum, Settings & s)
{
	Time timer = clock.getElapsedTime();
	float time = timer.asSeconds();
	s.updateSet();

	if (state == Pendulum_Left)
	{
		pendulum.RotatePendulum(time, state, s);
		if (time < s.PENDULUM_PERIOD - s.STOPPED_GEARS_TIME)
		{
			gearSet.rotateGears(s);
		}
		if (time > s.PENDULUM_PERIOD)
		{
			pendulum.PendulumSetAngle(s.MAX_ANGLE);
			state = Pendulum_Rigth;
			clock.restart();
		}
	}
	else if (state == Pendulum_Rigth)
	{
		pendulum.RotatePendulum(time, state, s);
		if (time > s.STOPPED_GEARS_TIME && time < s.PENDULUM_PERIOD - s.STOPPED_GEARS_TIME)
		{
			gearSet.rotateGears(s);
		}
		if (time > s.PENDULUM_PERIOD)
		{
			pendulum.PendulumSetAngle(-s.MAX_ANGLE);
			state = Pendulum_Left;
			clock.restart();
		}
	}
}

int main()//��� �� ��� � ����������
{
	setlocale(0, "RUS");
	srand(time(NULL));

	Settings s;//���������
	Menu m;//����

	while (!m.isExit)//���� ���� �������
	{
		m.showMenu();//���������� �
		m.inputChoose(s);//��������� ��������
	}

	ContextSettings settings;//��������� �� ����������
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "PENDULUM", Style::Default, settings);//������� ����
	
	Texture gearTexture;//��������� ��������
	gearTexture.loadFromFile("gear.png");
	
	Gearbox gearSet;//������� ����������
	gearSet.iniGearbox(gearTexture, s);//�������������� �

	Pendulum pendulum;//������� �������
	pendulum.iniPendulum(s);//���� ��������������

	Label label(s);//������� ������
	
	Clock clock;//������� ����
	StatePendulum statePendulum = Pendulum_Left;//������ �������� ��� ��������

	Event event;
	while (window.isOpen())//���� ������� �������� ���� �������� ���� ���������
	{
		while (window.pollEvent(event))//������� �� ������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
			s.readKey(event);
		}

		process(clock, statePendulum, gearSet, pendulum, s);//�������� ������� ��������� 
		pendulum.updatePendulum(s);//��������� ��������
		label.updateLabel(s);//��������� ������

		window.clear();//������� ����

		gearSet.DrawGearbox(window);//������ � ���� ��� ���� ��������
		pendulum.DrawPendulum(window);
		label.drawLabel(window);

		window.display();//���������� ���
	}
	//������� ������
	pendulum.dispPendulum();
	gearSet.dispGearbox();

	return 0;
}
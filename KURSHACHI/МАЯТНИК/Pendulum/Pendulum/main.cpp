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

int main()//тут то все и начинается
{
	setlocale(0, "RUS");
	srand(time(NULL));

	Settings s;//настройки
	Menu m;//меню

	while (!m.isExit)//пока меню открыта
	{
		m.showMenu();//показываем её
		m.inputChoose(s);//считываем значения
	}

	ContextSettings settings;//настройки из библиотеки
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "PENDULUM", Style::Default, settings);//создаем окно
	
	Texture gearTexture;//загружаем текстуры
	gearTexture.loadFromFile("gear.png");
	
	Gearbox gearSet;//создаем шестеренку
	gearSet.iniGearbox(gearTexture, s);//инициализируем её

	Pendulum pendulum;//создаем маятник
	pendulum.iniPendulum(s);//тоже инициализируем

	Label label(s);//создаем лейбел
	
	Clock clock;//создаем часы
	StatePendulum statePendulum = Pendulum_Left;//задаем состония для матяника

	Event event;
	while (window.isOpen())//цикл который работает пока работает окно программы
	{
		while (window.pollEvent(event))//проврка на событие закрытия окна
		{
			if (event.type == Event::Closed)
				window.close();
			s.readKey(event);
		}

		process(clock, statePendulum, gearSet, pendulum, s);//вызываем функцию обработки 
		pendulum.updatePendulum(s);//обновляем моаятник
		label.updateLabel(s);//обновляем лейбел

		window.clear();//очищаем окно

		gearSet.DrawGearbox(window);//рисуем в окне все наши элементы
		pendulum.DrawPendulum(window);
		label.drawLabel(window);

		window.display();//отображаем все
	}
	//очистка памяти
	pendulum.dispPendulum();
	gearSet.dispGearbox();

	return 0;
}
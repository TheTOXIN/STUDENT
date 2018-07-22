
#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>

using namespace std;

class Country
{
public:
	string name;
	Country(string name);
};

Country::Country(string name)
{
	this->name = name;
}

class Transport
{
public:
	Country country;
	double weight;
	double power;
	double speed;
	void move();
	void print();
	Transport(Country country, double weight, double power, double speed);
};

void Transport::print()
{
	cout << "Country = " << country.name << endl;
	cout << "Power = " << power << endl;
	cout << "Speed = " << speed << endl;
	cout << "Weight = " << weight << endl;
	cout << endl;
}

Transport::Transport(Country country, double weight, double power, double speed)
	: country("DEFAULT")
{
	this->country = country;
	this->weight = weight;
	this->power = power;
	this->speed = speed;
}

void Transport::move()
{
	cout << "MOVE TRANSPORT" << endl;
}

class Car : public Transport
{
public:
	string mark;
	void move();
	Car(Country country, string mark, double weight, double power, double speed);
};

Car::Car(Country country, string mark, double weight, double power, double speed)
	: Transport(country, weight, power, speed)
{
	this->mark = mark;
}

void Car::move()
{
	cout << "MOVE CAR" << endl;
}

class Sportcar : public Car
{
public:
	void move();
	Sportcar(Country country, string mark, double weight, double power, double speed);
};

Sportcar::Sportcar(Country country, string mark, double weight, double power, double speed)
	: Car(country, mark, weight, power, speed)
{

}

void Sportcar::move()
{
	cout << "MOVE SPORTCAR" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Country rus("Russia");
	Country ger("Germany");
	Country jap("Japan");

	Transport transport(rus, 12600, 2.4, 160);
	Car *car = new Car(ger, "BMW", 2600, 3.8, 360);
	Sportcar *sportcar = new Sportcar(jap, "Ferrari", 1750, 4.6, 360);

	transport.print();
	cout << car->mark << endl;
	car->print();
	cout << sportcar->mark << endl;
	sportcar->print();


	transport.move();
	car->move();
	sportcar->move();

	cout << transport.country.name << endl;
	cout << car->country.name << endl;
	cout << sportcar->country.name << endl;

	system("pause");
	return 1;
}

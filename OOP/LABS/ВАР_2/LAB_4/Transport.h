#pragma once

#include "iostream"
#include "Country.h"

using namespace std;

class Transport {
private:
	double weight;
	double power;
	double speed;
public:
	Transport(Country country, double weight, double power, double speed);
	Country country;
	virtual void move() = 0;
	string toString();
	double getWeight();
	double getPower();
	double getSpeed();
	void setWeight(double weight);
	void setPower(double power);
	void setSpeed(double speed);
protected:
};
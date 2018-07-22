#include "Transport.h"
#include "iostream"
#include "string"

using namespace std;

Transport::Transport(Country country, double weight, double power, double speed) : country("DEFAULT") {
	this->country = country;
	this->weight = weight;
	this->power = power;
	this->speed = speed;
}

string Transport::toString() {
	return country.getName() + ": " + to_string(weight) + "t " + to_string(power) + "ls " + to_string(speed) + "km/h";
}

double Transport::getWeight() {
	return this->weight;
}

double Transport::getPower() {
	return this->power;
}

double Transport::getSpeed() {
	return this->speed;
}

void Transport::setWeight(double weight) {
	this->weight = weight;
}

void Transport::setPower(double power) {
	this->power = power;
}

void Transport::setSpeed(double speed) {
	this->speed = speed;
}

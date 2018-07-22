#include "Plane.h"

Plane::Plane(Country country, double weight, double power, double speed)
	: Transport(country, weight, power, speed) {}

void Plane::move() {
	cout << "PLANE MOVE" << endl;
}

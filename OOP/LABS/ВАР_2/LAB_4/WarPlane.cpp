#include "WarPlane.h"

WarPlane::WarPlane(Country country, double weight, double power, double speed)
	: Plane(country, weight, power, speed) {}

void WarPlane::move() {
	cout << "WARPLANE MOVE" << endl;
}

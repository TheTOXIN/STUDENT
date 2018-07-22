#pragma once

#include "Plane.h"

class WarPlane : public Plane {
public:
	WarPlane(Country country, double weight, double power, double speed);
	void move();
};
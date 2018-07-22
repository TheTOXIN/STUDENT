#pragma once

#include "Transport.h"

class Plane : public Transport {
public:
	Plane(Country country, double weight, double power, double speed);
	void move();
};
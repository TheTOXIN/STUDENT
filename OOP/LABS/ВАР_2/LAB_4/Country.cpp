#include "Country.h"

Country::Country(string name) {
	this->name = name;
}

string Country::getName() {
	return this->name;
}

void Country::setNmae(string name) {
	this->name = name;
}

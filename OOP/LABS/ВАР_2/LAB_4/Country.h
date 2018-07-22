#pragma once

#include "iostream"

using namespace std;

class Country {
private:
	string name;
public:
	Country(string name);
	string getName();
	void setNmae(string name);
protected:
};

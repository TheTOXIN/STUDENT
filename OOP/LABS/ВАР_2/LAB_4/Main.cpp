#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>

#include "Country.h"
#include "Plane.h"
#include "WarPlane.h"
#include "Transport.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Country rus("Russia");
	Country ger("Germany");
	Country jap("Japan");
	Country fra("France");

	Transport *transports[4];

	transports[0] = new Plane(jap, 200, 700, 800);
	transports[1] = new Plane(fra, 190, 750, 900);
	transports[2] = new WarPlane(rus, 50, 500, 1200);
	transports[3] = new WarPlane(ger, 60, 550, 1100);

	int size = sizeof(transports) / sizeof(transports[0]);
	for (int i = 0; i < size; i++) {
		cout << transports[i]->toString() << endl;
		transports[i]->move();
		cout << endl;
	}

	system("pause");
	return 0;
}
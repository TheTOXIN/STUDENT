#include "iostream";
#include "string"
#include "math.h"

using namespace std;

class Point
{
public:
	int x;
	int y;
	string name;

	Point(int x, int y, string name);

	void show();
	void clear();
	void move();
	int getX();
	int getY();
	static void buildLine(Point p1, Point p2); 
private:
protected:
};

Point::Point(int x, int y, string name)
{
	this->x = x;
	this->y = y;
	this->name = name;
}

void Point::show()
{
	cout << "POINT - " << name << ": X = " << getX() << " Y = " << getY();
	cout << endl << endl;
}

void Point::clear()
{
	cout << "DELETE - ";
	show();
	this->x = 0;
	this->y = 0;
	this->name = "NULL";
}

void Point::move()
{
	cout << "INPUT NEW X/Y FOR MOVE POINT" << endl;
	cin >> this->x;
	cin >> this->y;
}

int Point::getX()
{
	return this->x;
}

int Point::getY()
{
	return this->y;
}

void Point::buildLine(Point p1, Point p2)
{
	cout << "POINT 1 :";
	p1.show();
	cout << "POINT 2 :";
	p2.show();
	cout << "LINE : ";
	double line = sqrt(pow((p2.getX() - p1.getX()), 2) + pow((p2.getY() - p1.getY()), 2));  
	cout << line << endl << endl;
}

int main()
{
	Point p1(5, 5, "A");
	Point p2(3, 4, "B");
	Point p3(0, 10, "C");

	p1.show();
	p2.show();
	p3.show();

	p1.move();
	p3.clear();
	Point::buildLine(p1, p2);

	system("pause");
	return 0;
}
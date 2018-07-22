#pragma once

#include <iostream>

using namespace std;

class Point {
private:
	int w;
	int h;
public:
	int **arr;
	Point(int w, int h);
	int getW();
	int getH();
	void setW(int w);
	void setH(int h);
	friend istream& operator >> (istream &in, Point &m);
	friend ostream& operator << (ostream &out, Point &m);
	friend Point& operator - (Point m1, Point m2);
	friend Point& operator ++ (Point &m);
protected:
};

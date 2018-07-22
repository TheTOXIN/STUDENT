#include "Matrix.h"
#include <iostream>
#include <string>
#include <time.h>

Point::Point(int w, int h)
{
	this->h = h;
	this->w = w;
}

int Point::getW()
{
	return this->w;
}

int Point::getH()
{
	return this->h;
}

void Point::setW(int w)
{
	this->w = w;
}

void Point::setH(int h)
{
	this->h = h;
}

istream& operator >> (istream &in, Point &m)
{
	cout << "INPUT MATRIX:" << endl;

	m.arr = new int*[m.w];
	for (int i = 0; i < m.w; i++) {
		m.arr[i] = new int[m.h];
		for (int j = 0; j < m.h; j++) {
			int tmp;
			in >> tmp;
			m.arr[i][j] = tmp;
		}
	}

	return in;
}

ostream& operator << (ostream &out, Point &m)
{
	cout << "YOUR MATRIX:" << endl;

	for (int i = 0; i < m.w; i++) {
		for (int j = 0; j < m.h; j++) {
			out.width(4);
			cout << m.arr[i][j];
		}
		cout << endl;
	}

	return out;
}

Point& operator - (Point m1, Point m2)
{
	if (m1.h != m2.h && m1.w != m2.w)
		cout << "MATRIX HAVE DIFERENT SIZE..." << endl;

	Point m(m1.w, m2.h);

	m.arr = new int*[m.w];
	for (int i = 0; i < m.w; i++) {
		m.arr[i] = new int[m.h];
		for (int j = 0; j < m.h; j++) {
			m.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
		}
	}

	return m;
}

Point& operator ++ (Point &m)
{
	for (int i = 0; i < m.w; i++) {
		for (int j = 0; j < m.h; j++) {
			m.arr[i][j]++;
		}
	}
	return m;
}

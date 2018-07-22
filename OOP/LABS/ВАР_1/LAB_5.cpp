#include <iostream>
#include <string>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

using namespace std;

template <class T>
class Squre
{
public:
	T x;
	T y;
	T len;
	Squre(T x, T y, T len);
	void draw();
	T getLen();
	T getX();
	T getY();
	T getS();
	T getP();

	friend bool operator==(Squre s1, Squre s2)
	{
		return s1.len == s2.len;
	}
	
	friend void operator+=(Squre &s, int n)
	{
		s.len += n;
	}
};

template <class T>
Squre<T>::Squre(T x, T y, T len)
{
	this->x = x;
	this->y = y;
	this->len = len;
}

template<class T>
void Squre<T>::draw()
{
	cout << this->x << " y = " << this->y << " len = " << this->len << endl;
}

template<class T>
T Squre<T>::getLen()
{
	return this->len;
}

template<class T>
T Squre<T>::getX()
{
	return this->x;
}

template<class T>
T Squre<T>::getY()
{
	return this->y;
}

template<class T>
T Squre<T>::getS()
{
	return pow(this->len, 2);
}

template<class T>
T Squre<T>::getP()
{
	return this->len * 4;
}

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Squre<int> s1(1, 2, 3);
	Squre<int> s2(2, 3, 4);

	s1.draw();
	s2.draw();

	if (s1 == s2) {
		cout << "s1 == s2" << endl;
	}
	else {
		cout << "s1 != s2" << endl;
	}


	s1 += 1;

	if (s1 == s2) {
		cout << "s1 == s2" << endl;
	}
	else {
		cout << "s1 != s2" << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

using namespace std;

class Matrix//класс матрица
{
public://у каждой матрицы есть
	int matr[100][100];//двумерный массив
	int h;//высота
	int w;//ширина
	string name;//название
	//ОБЪЕВЛЯЕМ функции и конструктор
	Matrix(int h, int w, string name);//конструктор
	friend ostream& operator <<(ostream& out, Matrix& m)//вывод мтарицы
	friend Matrix& operator +(Matrix m1, Matrix m2);//сложение матриц
	friend void operator -(Matrix& m, int n);//присваивание матрицы от числа
	friend void operator /=(Matrix& m, int n);//деление матрицы на число
private:
	const int maxSize = 100;//максимальный размер матрицы
protected:
};

Matrix::Matrix(int h, int w, string name)//конструктор для создание матрицы
{	//присваиваем передоваемые данные
	this->h = h;
	this->w = w;
	this->name = name;
	//заполняем матрицу случаными элементами через два вложенных цикла
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < w; j++) 
		{
			this->matr[i][j] = rand() % 100;
		}
	}
}

ostream& operator <<(ostream& out, Matrix& m)//реализуем функцию вывода матрицы
{
	out << "ÌÀÒÐÈÖÀ " << m.name <<  endl;
	for (int i = 0; i < m.h; i++)
	{
		for (int j = 0; j < m.w; j++)
		{
			out.width(4);
			out << m.matr[i][j];
		}
		out << endl;
	}
	return out;
}

Matrix& operator +(Matrix m1, Matrix m2)//реализуем функцию сложения двух матриц
{
	if (m1.h != m2.h && m1.w != m2.w)
	{
		cout << "ÌÀÒÐÈÖÛ ÐÀÇÍÎÃÎ ÐÀÇÌÅÐÀ..." << endl;
	}

	Matrix m(m1.h, m2.w, ("M" + to_string(rand() % 100)));

	for (int i = 0; i < m.h; i++)
	{
		for (int j = 0; j < m.w; j++)
		{
			m.matr[i][j] = m1.matr[i][j] + m2.matr[i][j];
		}
	}

	return m;
}

void operator -(Matrix& m, int n)//функция для присваивания нового элемента матрицы
{
	for (int i = 0; i < m.h; i++)
	{
		for (int j = 0; j < m.w; j++)
		{
			m.matr[i][j] = n;
		}
	}

}

void operator /=(Matrix& m, int n)//функция для деления матрицы на число
{
	for (int i = 0; i < m.h; i++)
	{
		for (int j = 0; j < m.w; j++)
		{
			m.matr[i][j] /= n;
		}
	}
}

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//создаем 2 матрицы
	Matrix a(4, 3, "A");
	Matrix b(4, 3, "B");
	//выводим их
	cout << a;
	cout << b;
	
	a - 10; //присваиваем 10 матрице а
	b /= 2;// делим матрицу b на 2

	Matrix c = a + b;// складываем две матрицы и создаем новую
	//опять выводим все матрицы
	cout << a;
	cout << b;
	cout << c;

	system("pause");
	return 0;
}

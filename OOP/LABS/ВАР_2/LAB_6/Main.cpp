#include <iostream>
#include <math.h>
#include <time.h>
#include <float.h>

using namespace std;

//класс исключения "Арифметическое переполнение"
class OverFlowException
{
public:
	int idx;
	OverFlowException(int i)
	{
		idx = i;
	}
};
//класс исключения "деление на ноль"
class ZeroDivideException
{
public:
	int idx;
	ZeroDivideException(int i)
	{
		idx = i;
	}
};
//класс исключения "корень из отрицательного числа"
class LogException
{
public:
	int idx;
	LogException(int i)
	{
		idx = i;
	}
};
//класс исключения "выход за пределы индексов массива"
class IndexException
{
public:
	int idx;
	IndexException(int i)
	{
		idx = i;
	}
};

//функция установки очередного значения массива
void SetValueA(double x, int i, int n, double* ar)
{
	double val = pow(x, 2) - 1;
	if (val >= DBL_MAX)
	{
		throw OverFlowException(i);
	}
	if (val == 0.0) //пытаемся делить на ноль
	{
		ar[i] = 0.0;
		throw ZeroDivideException(i);
	}
	if (val<0) //пытаемся извлечь корень из отриц. числа
	{
		ar[i] = 0.0;
		throw LogException(i);
	}
	if (i >= n) //недопустимый индекс массива
		throw IndexException(i);
	ar[i] = log(val); //нормальная ситуация
}

//функция установки очередного значения массива
void SetValueB(int i, int n, double* ar)
{
	double val = rand() % 100;
	if (val >= DBL_MAX)
	{
		throw OverFlowException(i);
	}
	if (i >= n) //недопустимый индекс массива
		throw IndexException(i);
	ar[i] = val; //нормальная ситуация
}

//функция установки очередного значения массива
void SetValueC(int i, int n, double* ar, double* a, double* b)
{
	double val = b[i];
	if (val >= DBL_MAX)
	{
		throw OverFlowException(i);
	}
	if (val == 0.0) //пытаемся делить на ноль
	{
		ar[i] = 0.0;
		throw ZeroDivideException(i);
	}
	if (i >= n) //недопустимый индекс массива
		throw IndexException(i);
	ar[i] = a[i] - 1 / val; //нормальная ситуация
}

void printArray(double *ar, int n)
{
	for (int i = 0; i < n; i++) //генерация некорректного доступа
	{
		if (i >= n) //недопустимый индекс массива
			throw IndexException(i);
		cout << ar[i] << ' ';
	}
	cout << endl;
}

void fill_A(double* a, int n)
{
	double x = 0;
	for (int i = 0; x <= 4.0; i++, x += 0.2)
	{
		try
		{
			SetValueA(x, i, n, a); //пытаемся сформировать массив
		}
		catch (ZeroDivideException ex) //перехват исключений
		{
			cout << "Zero divide error in index " << ex.idx << endl;
		}
		catch (LogException ex)
		{
			cout << "Log error in index " << ex.idx << endl;
		}
		catch (IndexException ex)
		{
			cout << "Index out of range in index " << ex.idx << endl;
		}
		catch (OverFlowException ex)
		{
			cout << "Arithmetic overflow in index " << ex.idx << endl;
		}
	}
}

void fill_B(double *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		try
		{
			SetValueB(i, n, a); //пытаемся сформировать массив
		}
		catch (ZeroDivideException ex) //перехват исключений
		{
			cout << "Zero divide error in index " << ex.idx << endl;
		}
		catch (LogException ex)
		{
			cout << "log error in index " << ex.idx << endl;
		}
		catch (IndexException ex)
		{
			cout << "Index out of range in index " << ex.idx << endl;
		}
		catch (OverFlowException ex)
		{
			cout << "Arithmetic overflow in index " << ex.idx << endl;
		}
	}
}

void fill_C(double *c, double *a, double *b, int n)
{
	for (int i = 0; i < n; i++)
	{
		try
		{
			SetValueC(i, n, c, a, b); //пытаемся сформировать массив
		}
		catch (ZeroDivideException ex) //перехват исключений
		{
			cout << "Zero divide error in index " << ex.idx << endl;
		}
		catch (LogException ex)
		{
			cout << "log error in index " << ex.idx << endl;
		}
		catch (IndexException ex)
		{
			cout << "Index out of range in index " << ex.idx << endl;
		}
		catch (OverFlowException ex)
		{
			cout << "Arithmetic overflow in index " << ex.idx << endl;
		}
	}
}

void main()
{
	setlocale(0, "RUS");
	srand(time(NULL));

	int n1 = 10;
	int n2 = 8;
	int n3 = 12;

	double* a = new double[n1];
	double* b = new double[n2];
	double* c = new double[n3];

	cout << endl << "Filling array - A..." << endl;
	fill_A(a, n1);
	cout << endl << "Filling array - B..." << endl;
	fill_B(b, n2);
	cout << endl << "Filling array - C..." << endl;
	fill_C(c, a, b, n3);

	try
	{
		cout << endl << "Массив А" << endl;
		printArray(a, n1); //пытаемся распечатать массив
		cout << endl << "Массив B" << endl;
		printArray(b, n2);
		cout << endl << "Массив C" << endl;
		printArray(c, n3);
	}
	catch (IndexException ex) //перехват исключений
	{
		cout << "Index out of range in index " << ex.idx << endl;
	}

	system("pause");
}

#include <iostream>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string>
#include <windows.h>
#include <stack>  
#include <set>  
#include <iterator>

using namespace std;

class Perfomance
{
private:
	string FIO;
	int raitngs[4];
	int average;
public:
	Perfomance();
	Perfomance(string FIO);
	void setFIO(string FIO);
	string getFIO();
	int getAverage();
	void toString();
protected:
};

Perfomance::Perfomance()
{

}

Perfomance::Perfomance(string FIO)
{
	this->FIO = FIO;

	for (int i = 0; i < 4; i++)
		this->raitngs[i] = (rand() % 4) + 2;

	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += raitngs[i];
	this->average = sum / 4;
}

void Perfomance::setFIO(string FIO)
{
	this->FIO = FIO;
}

string Perfomance::getFIO()
{
	return this->FIO;
}

int Perfomance::getAverage()
{
	return this->average;
}

void Perfomance::toString()
{
	cout << this->FIO << " | ratings: ";
	for (int i = 0; i < 4; i++)
	{
		cout << this->raitngs[i] << "  ";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	stack<Perfomance> studsAll;
	set<string> studs;

	int N;
	cout << "Введите кол-во студентов :";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string FIO;
		cout << i + 1 << " ФИО Студента = ";
		cin >> FIO;
		Perfomance stud(FIO);
		studsAll.push(stud);
		stud.toString();
	}
	cout << endl;

	cout << "Студеты со сред.быллом >= 4" << endl;
	while (!studsAll.empty())
	{
		Perfomance stud = studsAll.top();
		studsAll.pop();
		if (stud.getAverage() >= 4)
		{
			stud.toString();
		}
		else
		{
			studs.insert(stud.getFIO());
		}
	}

	cout << "Остальное множество студентов: " << endl;
	copy(studs.begin(), studs.end(), ostream_iterator<string>(cout, "\n"));

	system("pause");
	return 0;
}
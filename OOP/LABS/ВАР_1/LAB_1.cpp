#include "iostream";
#include "string";

using namespace std;

const int size = 5; 

template <typename T>
void printArray(T mas[])
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << ' '; 
	}
	cout << endl << endl;
}

void sumArrays(float mas1[], float mas2[])
{
	float sumMas[size];
	for (int i = 0; i < size; i++)
	{
		sumMas[i] = mas1[i] + mas2[i];
	}
	printArray(sumMas);
}

void sumArrays(int mas1[], int mas2[])
{
	int sumMas[size];
	for (int i = 0; i < size; i++)
	{
		sumMas[i] = mas1[i] + mas2[i];
	}
	printArray(sumMas);
}

void sumArrays(char mas1[], char mas2[])
{
	string sumStr;

	for (int i = 0; i < size; i++)
		sumStr += mas1[i];

	for (int i = 0; i < size; i++)
		sumStr += mas2[i];

	cout << sumStr << endl << endl;
}

int main() {

	int arrInt[size] = {1, 2, 3, 4, 5};
	float arrFloat[size] = {0.1, 0.2, 0.3, 0.4, 0.5};
	char arrChar[size] = {'a', 'b', 'c', 'd', 'e'};

	cout << "Int:" << endl;
	sumArrays(arrInt, arrInt);
	cout << "Float:" << endl;
	sumArrays(arrFloat, arrFloat);
	cout << "Char:" << endl;
	sumArrays(arrChar, arrChar);

	system( "pause" );
	return 0;
}
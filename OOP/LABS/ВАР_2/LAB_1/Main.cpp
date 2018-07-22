#include "iostream";

using namespace std;

const int len = 5;

template <typename T>
void replaceMaxAndMin(T array[]) {
	T max = array[0], min = array[0];

	for (int i = 0; i < len; i++) {
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	cout << "MIN: " << min << endl;
	cout << "MAX: " << max << endl;

	array[0] = max;
	array[len - 1] = min;
}

template <typename T>
void printArrays(T array[]) {
	for (int i = 0; i < len; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main() {

	int arrInt[len] = {1, 2, 3, 4, 5};
	float arrFloat[len] = {0.1, 0.2, 0.3, 0.4, 0.5};
	char arrChar[len] = {'a', 'b', 'c', 'd', 'e'};

	cout << "INT" << endl;
	printArrays(arrInt);
	replaceMaxAndMin(arrInt);
	printArrays(arrInt);
	cout << endl;

	cout << "FLOAT" << endl;
	printArrays(arrFloat);
	replaceMaxAndMin(arrFloat);
	printArrays(arrFloat);
	cout << endl;

	cout << "CHAR" << endl;
	printArrays(arrChar);
	replaceMaxAndMin(arrChar);
	printArrays(arrChar);
	cout << endl;

	system( "pause" );
	return 0;
}
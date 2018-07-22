#include <iostream>
#include <math.h>
#include <locale.h>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int kol = 100;
	int count;

	string words[kol];//делаем массив строк

	cout << "Input count words: " << endl;
	cin >> count;//вводим кол.во строк

	cout << "Input words: " << endl;
	for (int i = 0; i < count; i++)//цикл для ввода массива строк
	{
		cin >> words[i];
	}
	cout << endl;

	cout << "List of words: " << endl;;//цикл для вывода массива строк
	for (int i = 0; i < count; i++)
	{
		cout << words[i] << endl;
	}
	cout << endl;

	cout << "List of correct words: " << endl;
	for (int i = 0; i < count; i++)//пробегаемся по массиву строк через цикл
	{
		int len = words[i].length();//находим длину пробегаемого слова

		for (int j = 0; j < len - 1; j++)//через цикл пробегаемся по символам в нашем слове
		{
			if (words[i][j] == 'ж' || words[i][j] == 'ш')//если символ равен ж или ш мы проверяем вторую букву
			{
				if (words[i][j + 1] == 'ы')//если вторая буква равна ы меняем на и
				{
					words[i][j + 1] = 'и';
				}
			}
			//z-ж h-ш u-ы e-и c-ч j-щ q-ю y-у i-я a-a 
			if (words[i][j] == 'ч' || words[i][j] == 'щ')//тоже самое для букв ч и щ
			{
				if (words[i][j + 1] == 'ю')
				{
					words[i][j + 1] = 'у';
				}
				if (words[i][j + 1] == 'я')
				{
					words[i][j + 1] = 'а';
				}
			}
		}
	}

	for (int i = 0; i < count; i++)//цикл для вывода массива строк
	{
		cout << words[i] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
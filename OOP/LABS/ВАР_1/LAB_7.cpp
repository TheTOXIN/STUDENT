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

	string words[kol];//������ ������ �����

	cout << "Input count words: " << endl;
	cin >> count;//������ ���.�� �����

	cout << "Input words: " << endl;
	for (int i = 0; i < count; i++)//���� ��� ����� ������� �����
	{
		cin >> words[i];
	}
	cout << endl;

	cout << "List of words: " << endl;;//���� ��� ������ ������� �����
	for (int i = 0; i < count; i++)
	{
		cout << words[i] << endl;
	}
	cout << endl;

	cout << "List of correct words: " << endl;
	for (int i = 0; i < count; i++)//����������� �� ������� ����� ����� ����
	{
		int len = words[i].length();//������� ����� ������������ �����

		for (int j = 0; j < len - 1; j++)//����� ���� ����������� �� �������� � ����� �����
		{
			if (words[i][j] == '�' || words[i][j] == '�')//���� ������ ����� � ��� � �� ��������� ������ �����
			{
				if (words[i][j + 1] == '�')//���� ������ ����� ����� � ������ �� �
				{
					words[i][j + 1] = '�';
				}
			}
			//z-� h-� u-� e-� c-� j-� q-� y-� i-� a-a 
			if (words[i][j] == '�' || words[i][j] == '�')//���� ����� ��� ���� � � �
			{
				if (words[i][j + 1] == '�')
				{
					words[i][j + 1] = '�';
				}
				if (words[i][j + 1] == '�')
				{
					words[i][j + 1] = '�';
				}
			}
		}
	}

	for (int i = 0; i < count; i++)//���� ��� ������ ������� �����
	{
		cout << words[i] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
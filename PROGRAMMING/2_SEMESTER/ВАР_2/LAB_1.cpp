#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

int main()
{
	const int n = 100, kol = 100, chars_count = 3;
	typedef char String[n];

	String surname[kol];
	String chars[chars_count] = { "va","ko","na" };

	cout << "Input surnames: " << endl;
	for (int i = 0; i < kol; i++)
	{
		cin.getline(surname[i], n);
		if (strcmp(surname[i], "enter") == 0)
			break;
	}

	cout << "List surnames: " << endl;
	for (int i = 0; strcmp(surname[i], "enter") != 0; i++)
	{
		cout << i + 1 << ". " << surname[i] << endl;
	}

	cout << "List female surnames: " << endl;
	for (int i = 0; strcmp(surname[i], "enter") != 0; i++)
	{
		for (int j = 0; j < chars_count; j++)
		{
			char* c = strstr(surname[i], chars[j]);
			if (c != 0)
			{
				int length_c = strlen(c);
				if (length_c <= 2)
				{
					cout << surname[i] << endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}
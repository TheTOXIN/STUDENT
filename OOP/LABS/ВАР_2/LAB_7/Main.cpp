#include <iostream>
#include <math.h>
#include <locale.h>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	const int kol = 100, chars_count = 3;

	string surname[kol];
	string chars[chars_count] = { "va","ko","na" };

	cout << "Input surnames: " << endl;
	for (int i = 0; i < kol; i++)
	{
		cin >> surname[i];
		if (surname[i] == "enter")
			break;
	}

	cout << "List surnames: " << endl;
	for (int i = 0; surname[i] != "enter"; i++)
	{
		cout << i + 1 << ". " << surname[i] << endl;
	}

	cout << "List female surnames: " << endl;
	for (int i = 0; surname[i] != "enter"; i++)
	{
		for (int j = 0; j < chars_count; j++)
		{
			char* sn = &surname[i][0u];;
			char* sl = &chars[j][0u];
			char* c = strstr(sn, sl);
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
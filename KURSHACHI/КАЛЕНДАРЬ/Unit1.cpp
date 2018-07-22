//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
int year;
int month;
int firstDayInCurrentMonth;
int numDays;
AnsiString calendar = "";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
	ShowMessage("�������� ������:\n����� �������\n��1602");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	year = StrToInt(Edit1->Text);
	month = StrToInt(Edit2->Text);
	firstDayInCurrentMonth = firstDayofNewYearAndMonth(year);
	numDays = numOfDaysInAMonth(month);
	printHeader(month);
	printMonth(numDays, firstDayInCurrentMonth);
	ListBox1->Items->Add("-==================-");
}
//---------------------------------------------------------------------------
int TForm1::firstDayofNewYearAndMonth(int year)
{
	int day_start;
	int x1, x2, x3;
	x1 = (year - 1) / 4;
	x2 = (year - 1) / 100;
	x3 = (year - 1) / 400;
	day_start = (year + x1 - x2 + x3) % 7;
	return day_start;
}
//---------------------------------------------------------------------------
int TForm1::numOfDaysInAMonth(int m)
{
	if (m == 1)
		return(31);
	else if (m == 2)
		return(28);
	else if (m == 3)
		return(31);
	else if (m == 4)
		return(30);
	else if (m == 5)
		return(31);
	else if (m == 6)
		return(30);
	else if (m == 7)
		return(31);
	else if (m == 8)
		return(31);
	else if (m == 9)
		return(30);
	else if (m == 10)
		return(31);
	else if (m == 11)
		return(30);
	else if (m == 12)
		return(31);
}
//---------------------------------------------------------------------------
void TForm1::printHeader(int m) {
	if (m == 1) {
		ListBox1->Items->Add("������");
		cout << "������" << endl;
	}
	else if (m == 2) {
		ListBox1->Items->Add("�������");
		cout << "�������" << endl;
	}
	else if (m == 3) {
		ListBox1->Items->Add("����");
		cout << "����" << endl;
	}
	else if (m == 4) {
		ListBox1->Items->Add("������");
		cout << "������" << endl;
	}
	else if (m == 5) {
		ListBox1->Items->Add("���");
		cout << "���" << endl;
	}
	else if (m == 6) {
		ListBox1->Items->Add("����");
		cout << "����" << endl;
	}
	else if (m == 7) {
		ListBox1->Items->Add("����");
		cout << "����" << endl;
	}
	else if (m == 8) {
		ListBox1->Items->Add("������");
		cout << "������" << endl;
	}
	else if (m == 9) {
		ListBox1->Items->Add("��������");
		cout << "��������" << endl;
	}
	else if (m == 10) {
		ListBox1->Items->Add("�������");
		cout << "�������" << endl;
	}
	else if (m == 11) {
		ListBox1->Items->Add("������");
		cout << "������" << endl;
	}
	else if (m == 12) {
		ListBox1->Items->Add("�������");
		cout << "�������" << endl;
	}
	ListBox1->Items->Add(year);
	cout << year << endl;
	ListBox1->Items->Add(" �� �� �� �� �� �� ��");
	cout << " �� �� �� �� �� �� ��" << endl;
	ListBox1->Items->Add("_____________________");
	cout << "_____________________" << endl;
}
//---------------------------------------------------------------------------
void TForm1::printMonth(int numDays, int &weekDay)
{
	calendar = "";
	int day = 1;
	skipToDay(weekDay);
	while (day <= numDays)
	{
		if (IntToStr(day).Length() == 1)
			calendar += IntToStr(day) + "    ";
		else
		    calendar += IntToStr(day) + "  ";
		cout << setw(2) << day << " ";
		if (weekDay == 6)
		{
			ListBox1->Items->Add(calendar);
			cout << endl;
			calendar = "";
			weekDay = 0;
		}
		else weekDay = weekDay + 1;
		day = day + 1;
	}
}
//---------------------------------------------------------------------------
void TForm1::skipToDay(int d)
{
	return skip(3 * d);
}
//---------------------------------------------------------------------------
void TForm1::skip(int i)
{
	while (i > 0)
	{
		calendar += " ";
		cout << " ";
		i = i - 1;
	}
}
//---------------------------------------------------------------------------

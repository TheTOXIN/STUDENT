//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "BubbleCh"
#pragma link "Series"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
const int n = 14;
int X[n] = {100, 105, 108, 113, 118, 118, 110, 115, 119, 118, 120, 124, 129, 132};
int Y[n] = {70, 79, 85, 84, 85, 85, 96, 99, 100, 98, 99, 102, 105, 112};
double sredX= 0, sredY = 0;
int xMin = 100;
int xMax = 132;
double dX, dY, sX, sY;
double R;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	setDefault();
	fillXY();
	countAverageValue();
	countDesperssion();
	countRegression();
	drawLineRegress();
	drawBubbleField();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	printInfo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Text = "";
	fillGrid();
}
//---------------------------------------------------------------------------
void TForm1::drawBubbleField()
{
	for (int i = 0; i < n; i++)
	{
        Series2->AddBubble(X[i], Y[i], 1, i, clTeeColor);
    }
}
//---------------------------------------------------------------------------
void TForm1::countAverageValue()
{
	for (int i = 0; i < n; i++) 
	{
		sredX += X[i];
		sredY += Y[i];
	}
	sredX /= n;
	sredY /= n;
}
//---------------------------------------------------------------------------
void TForm1::countDesperssion()
{
	int sumX = 0;
	int sumY = 0;
	
	for (int i = 0; i < n; i++)
	{
		sumX += pow(X[i] - sredX, 2);
		sumY += pow(Y[i] - sredY, 2);
	}

	dX = sumX / n;
	dY = sumY / n;
	sX = sqrt(dX);
	sY = sqrt(dY);
}
//---------------------------------------------------------------------------
void TForm1::countRegression()
{
	int sumXY = 0;
	for(int i = 0; i < n; i++)
		sumXY += X[i] * Y[i];
	R = (sumXY - (n * sredX * sredY)) / (n * sX * sY);
}
//---------------------------------------------------------------------------
void TForm1::drawLineRegress()
{
	float x = xMin;
	float y = 0;
	while (x < xMax)
	{
		y = R * (sX / sY) * (x - sredX) + sredY;
		Series1->AddXY(x, y, "", clTeeColor);
		x += 0.01;
	}
}
//---------------------------------------------------------------------------
void TForm1::printInfo()
{
	Memo1->Lines->Add("Среднее X = " + FloatToStr(sredX));
	Memo1->Lines->Add("Среднее Y = " + FloatToStr(sredY));
	Memo1->Lines->Add("Дисперсия X = " + FloatToStr(dX));
	Memo1->Lines->Add("Дисперсия Y = " + FloatToStr(dY));
	Memo1->Lines->Add("Отклонение X = " + FloatToStr(sX));
	Memo1->Lines->Add("Отклонение Y = " + FloatToStr(sY));
	Memo1->Lines->Add("Корреляция = " + FloatToStr(R));
	Memo1->Lines->Add("------------------------------------------");
}
//---------------------------------------------------------------------------
void TForm1::fillGrid()
{
	StringGrid1->Cells[0][0] = "X";
	StringGrid1->Cells[1][0] = "Y";
	for (int i = 0; i < n; i++)
	{
		StringGrid1->Cells[0][i+1] = X[i];
		StringGrid1->Cells[1][i+1] = Y[i];
	}
}
//---------------------------------------------------------------------------
void TForm1::fillXY()
{
	for (int i = 0; i < n; i++)
	{
		X[i] = StrToInt(StringGrid1->Cells[0][i+1]);
		Y[i] = StrToInt(StringGrid1->Cells[1][i+1]);
	}
}
//---------------------------------------------------------------------------
void TForm1::setDefault()
{
	sredX= 0;
	sredY = 0;
	dX = 0;
	dY = 0;
	sX = 0;
	sY = 0;
	R = 0;
}
//---------------------------------------------------------------------------


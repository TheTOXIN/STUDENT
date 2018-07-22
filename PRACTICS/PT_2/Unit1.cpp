//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
const int n = 6;
const int m = 5;
float maxF = 0;
float max[m];
float F[n];
float H[m] = {0.32, 0.23, 0.15, 0.20, 0.10};
float A[n][m] = {{30.0, 40.0, 20.0,	0.2, 300},
				{25.0, 20.0, 30.0, 0.3, 200},
				{40.0, 45.0, 54.0, 0.1, 250},
				{28.0, 30.0, 35.0, 0.4, 160},
				{15.0, 12.0, 20.0, 0.25, 280},
				{50.0, 30.0, 40.0, 0.21, 120}};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->Visible = true;

	StringGrid1->Cells[0][0] = "№ Предприятия";
	StringGrid1->Cells[1][0] = "Прибыль";
	StringGrid1->Cells[2][0] = "Себестоимость";
	StringGrid1->Cells[3][0] = "Доходы";
	StringGrid1->Cells[4][0] = "Фондотдача";
	StringGrid1->Cells[5][0] = "Производительность";
	StringGrid1->Cells[0][7] = "Коэффициенты";

	for (int i = 1; i <= n; i++)
		StringGrid1->Cells[0][i] = IntToStr(i);

	for (int i = 0; i < n; i++)
		StringGrid1->ColWidths[i] = StringGrid1->Cells[i][0].Length()*8;

	Memo1->Text = "";
	fillGrid();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	fillMatrix();
	find();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	printInfo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	normolize();
	fillGrid();
}
//---------------------------------------------------------------------------
void TForm1::fillGrid()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			StringGrid1->Cells[j+1][i+1] = FloatToStr(A[i][j]).SubString(0, 4);
		}
		StringGrid1->Cells[i+1][7] = FloatToStr(H[i]).SubString(0, 4);
	}
}
//---------------------------------------------------------------------------
void TForm1::fillMatrix()
{
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = StrToFloat(StringGrid1->Cells[j+1][i+1]);
		}
		H[i] = StrToFloat(StringGrid1->Cells[i+1][7]);
	}
}
//---------------------------------------------------------------------------
void TForm1::normolize()
{
	float sred = 0;
    for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[j][i] > max[i])
			{
				max[i] = A[j][i];
            }
		}
		sred += max[i];
		Memo1->Lines->Add("MAX." + IntToStr(i) + " = " + FloatToStr(max[i]));
	}
	sred /= m;
	Memo1->Lines->Add("SRED = " + FloatToStr(sred));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(max[i] >= sred)
			{
				A[j][i] =  A[j][i] / max[i];
			}
			else
			{
				A[j][i] = 1 - (A[j][i] / max[i]);
            }
		}
	}
}
//---------------------------------------------------------------------------
void TForm1::printInfo()
{
	for (int i = 0; i < n; i++)
	{
        Memo1->Lines->Add("F" + IntToStr(i + 1) + " = " + FloatToStr(F[i]));
    }
}
//---------------------------------------------------------------------------
void TForm1::find()
{	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			F[i] += H[j] * A[i][j];
        }
	}
    int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (F[i] > maxF) 
		{
			maxF = F[i];
			index = i + 1;
		}	
	}

	Label1->Caption = "Предприятие № " + IntToStr(index) + " :" + FloatToStr(maxF).SubString(0, 5);
}
//---------------------------------------------------------------------------



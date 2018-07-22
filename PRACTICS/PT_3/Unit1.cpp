//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;

const int R = 4;
const int S = 3;

float a = 0.1;
float p = 0.25;
float res;
float minV;
float maxV;

int index;
int max[R];
int min[R];
int V[R][S] = {{20, 25, 15},
			   {25, 24, 10},
			   {15, 28, 12},
			   {9, 30, 20}};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->Visible = true;
	StringGrid1->Cells[0][0] = "Проекты / Состояния";
	StringGrid1->ColWidths[0] = 120;
	for (int i = 1; i <= R; i++)
		StringGrid1->Cells[0][i] = "R" + IntToStr(i);
	for (int i = 1; i <= S; i++)
		StringGrid1->Cells[i][0] = "S" + IntToStr(i);
	Memo1->Text = "";
	fillGrid();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	fillMatrix();
	float W[R];
	float minW;

	printIfno(Button1->Caption + ":");
	for (int i = 0; i < R; i++)
	{
		W[i] = 0;
		for (int j = 0; j < S; j++)
		{
            W[i] += V[i][j];
		}
		W[i] = W[i] * p;
		if (W[i] < minW || i == 0)
		{
			minW = W[i];
			index = i + 1;
		}
		printIfno("W{R" + IntToStr(i + 1) + "} = " + FloatToStr(W[i]));
	}

	printIfno("Min W = " + FloatToStr(minW));
	printIfno("--------------------");
	res = minW;
	Label1->Caption = "R" + IntToStr(index) + " = " + FloatToStr(res);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	fillMatrix();
	findMaxAndMinR();

	printIfno(Button2->Caption + ":");
	int minR = 9999;
	for (int i = 0; i < R; i++)
	{
		if (max[i] < minR || i == 0)
		{
			minR = max[i];
			index = i + 1;
		}
	}

	res = minR;
	printIfno("Min R = " + FloatToStr(minR));
	printIfno("--------------------");
	Label2->Caption = "R" + IntToStr(index) + " = " + FloatToStr(res);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	fillMatrix();
	findMaxAndMinV();
	findMaxAndMinR();
	float r[R][S];

	printIfno(Button3->Caption + ":");
	printIfno("Matrix r :");
	for (int i = 0; i < R; i++)
	{
		AnsiString str = "";
		for (int j = 0; j < S; j++)
		{
			r[i][j] = V[i][j] - minV;
			str += FloatToStr(r[i][j]) + " ";
		}
		printIfno(str);
	}
	printIfno("--------------------");


	for (int i = 0; i < R; i++)
	{
		int rMax = max[i] - minV;
		printIfno("r" + IntToStr(i + 1) + " max = " + IntToStr(rMax));
	}
	printIfno("--------------------");

	float minR = 9999;
	for (int i = 0; i < R; i++)
	{
		if ((max[i]-minV) < minR || i == 0)
		{
			minR = max[i]-minV;
			index = i + 1;
        }
	}
	res = minR;
	Label3->Caption = "R" + IntToStr(index) + " = " + FloatToStr(res);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	fillMatrix();
	findMaxAndMinR();

	printIfno(Button4->Caption + ":");
	float minW = 9999;
	for (int i = 0; i < R; i++)
	{
		float W = (a * min[i]) + ((1 - a) * max[i]);
		if (W < minW)
		{
			minW = W;
            index = i;
        }
		printIfno("W" + IntToStr(i + 1) + " = " + FloatToStr(W));
	}
	res = minW;
	printIfno("W min = " + FloatToStr(minW));
	Label4->Caption = "R" + IntToStr(index) + " = " + FloatToStr(res);
}
//---------------------------------------------------------------------------
void TForm1::printIfno(AnsiString str)
{
	Memo1->Lines->Add(str);
}
//---------------------------------------------------------------------------
void TForm1::fillGrid()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
            StringGrid1->Cells[j+1][i+1] = V[i][j];
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::fillMatrix()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
			V[i][j] = StrToInt(StringGrid1->Cells[j+1][i+1]);
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::findMaxAndMinR()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (V[i][j] > max[i])
			{
				max[i] = V[i][j];
			}
			if (V[i][j] < min[i] || j == 0)
			{
                min[i] = V[i][j];
            }
		}
		printIfno("R" + IntToStr(i + 1) + " max = " + IntToStr(max[i]));
		printIfno("R" + IntToStr(i + 1) + " min = " + IntToStr(min[i]));
	}
	printIfno("--------------------");
}
//---------------------------------------------------------------------------
void TForm1::findMaxAndMinV()
{
	minV = 9999;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (V[i][j] > maxV)
				maxV = V[i][j];
			if (V[i][j] < minV)
				minV = V[i][j];
		}
	}

	printIfno("maxV = " + FloatToStr(maxV));
	printIfno("minV = " + FloatToStr(minV));
	printIfno("--------------------");
}
//---------------------------------------------------------------------------

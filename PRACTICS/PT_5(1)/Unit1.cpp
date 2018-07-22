//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const int n = 5;
const int m = 7;
int row, col;
int TC = 0, FC = 1, VC = 2, MC = 3, ATC = 4, AVC = 5, AFC = 6;
float M[n][m];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	row = StringGrid1->RowCount;
	col = StringGrid1->ColCount;

	StringGrid1->Visible = true;
	StringGrid1->Cells[0][0] = "Q";
	StringGrid1->Cells[1][0] = "TC";
	StringGrid1->Cells[2][0] = "FC";
	StringGrid1->Cells[3][0] = "VC";
	StringGrid1->Cells[4][0] = "MC";
	StringGrid1->Cells[5][0] = "ATC";
	StringGrid1->Cells[6][0] = "AVC";
	StringGrid1->Cells[7][0] = "AFC";

	M[0][TC] = 60;
	M[1][TC] = 130;
	M[2][TC] = 180;
	M[3][TC] = 230;
	M[4][TC] = 300;

	for (int i = 1; i <= row; i++)
		StringGrid1->Cells[0][i] = IntToStr(i - 1);

	for (int i = 0; i < col; i++)
		StringGrid1->ColWidths[i] = StringGrid1->Cells[i][0].Length()*20;

	fillGrid();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	fillMatrix();

	for (int i = 0; i < n; i++)
	{
		M[i][FC] = M[0][TC];
		M[i][VC] = M[i][TC] - M[i][FC];
		M[i+1][MC] = M[i+1][TC] - M[i][TC];
		if(i != 0)
		{
			M[i][ATC] = M[i][TC] / (i);
			M[i][AVC] = M[i][VC] / (i);
			M[i][AFC] = M[i][FC] / (i);
		}
	}
	
	fillGrid();
}
//---------------------------------------------------------------------------
void TForm1::fillGrid()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			StringGrid1->Cells[j+1][i+1] = FloatToStr(M[i][j]).SubString(0, 4);
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::fillMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M[i][j] = StrToInt(StringGrid1->Cells[j+1][i+1]);   
        }
    }
}
//---------------------------------------------------------------------------


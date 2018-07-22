//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const int n = 6;
const int m = 7;
int row, col;
int Q;
int TC = 0, VC = 1, FC = 2, AC = 3, AVC = 4, AFC = 5, MC = 6;
float M[n][m];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Q = StrToInt(Edit1->Text);
	row = StringGrid1->RowCount;
	col = StringGrid1->ColCount;

	StringGrid1->Visible = true;
	StringGrid1->Cells[0][0] = "Q";
	StringGrid1->Cells[1][0] = "TC";
	StringGrid1->Cells[2][0] = "VC";
	StringGrid1->Cells[3][0] = "FC";
	StringGrid1->Cells[4][0] = "AC";
	StringGrid1->Cells[5][0] = "AVC";
	StringGrid1->Cells[6][0] = "AFC";
	StringGrid1->Cells[7][0] = "MC";

	updateCells();

	for (int i = 1; i < row; i++)
		StringGrid1->Cells[0][i] = IntToStr(i);
	StringGrid1->Cells[0][6] = IntToStr(Q);

	for (int i = 0; i < col; i++)
		StringGrid1->ColWidths[i] = StringGrid1->Cells[i][0].Length()*20;

	fillGrid();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Q = StrToInt(Edit1->Text);
	StringGrid1->Cells[0][6] = IntToStr(Q);
	
	fillMatrix();
	findFC();

	for (int i = 0; i < n; i++)
	{
		int index = StrToInt(StringGrid1->Cells[0][i + 1]);
		
		if (M[i][TC] != 0 || M[i][VC] != 0)
		{
			if(M[i][TC] != 0)
				M[i][VC] = M[i][TC] - M[i][FC];

			if(M[i][VC] != 0)
				M[i][TC] = M[i][VC] + M[i][FC];

			M[i][AC] = M[i][TC] / (index);
			M[i][AVC] = M[i][VC] / (index);
		}

		if (M[i][AC] != 0 || M[i][AVC] != 0)
		{
			if (M[i][AC] != 0 && M[i][AVC] == 0)
				M[i][AVC] = (M[i][AC] * (index) - M[i][FC]) / (index);

			if (M[i][AVC] != 0 && M[i][AC] == 0)
				M[i][AC] = (M[i][AVC] * (index) + M[i][FC]) / (index);

			M[i][TC] = M[i][AC] * (index);
			M[i][VC] = M[i][AVC] * (index);
		}

		if (M[i][MC] != 0)
		{
			if (M[i][TC] == 0)
				M[i][TC] = M[i][MC] + M[i - 1][TC];

			if (M[i][VC] == 0)
				M[i][VC] = M[i][MC] + M[i - 1][VC];

			M[i][AC] = M[i][TC] / (index);
			M[i][AVC] = M[i][VC] / (index);
		}

		M[i][MC] = M[i][TC] - M[i - 1][TC];
		M[i][AFC] = M[i][FC] / (index);
	}
	M[5][MC] = (M[5][TC] - M[4][TC]) / (Q - 5);

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
			M[i][j] = StrToFloat(StringGrid1->Cells[j+1][i+1]);
		}
	}
}
//---------------------------------------------------------------------------
void TForm1::findFC()
{
	for (int i = 0; i < n; i++)
	{
		if (M[i][AFC] != 0)
		{
			for (int j = 0; j < n; j++)
			{
				M[j][FC] = M[i][AFC] * StrToInt(StringGrid1->Cells[0][i+1]); 
            }
		}
	}
}
//---------------------------------------------------------------------------
void TForm1::updateCells()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M[i][j] = 0;
        }
	}

	M[0][TC] = 30;
	M[1][VC] = 18;
	M[2][AC] = 15;
	M[3][AVC] = 7;
	M[4][AFC] = 4;
	M[5][AVC] = 3.5;
	M[4][MC] = 2;
	M[5][MC] = 1;

	fillGrid();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	updateCells();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
float D, m, n, I;
int row, col;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text = "120000";
	Edit2->Text = "12";
	Edit3->Text = "1";
	Edit4->Text = "13,5";

	readOfEdits();
	updateCells();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	readOfEdits();
	updateCells();

	float monthSum = D / (n * m);
	for (int i = 1; i <= m; i++)
	{
		float pay = (D - (i - 1) * monthSum) * (I / 100) / m;
		StringGrid1->Cells[1][i] = FloatToStr(D - (i * monthSum));
		StringGrid1->Cells[2][i] = FloatToStr(pay);
		StringGrid1->Cells[3][i] = FloatToStr(monthSum);
		StringGrid1->Cells[4][i] = FloatToStr(pay + StrToFloat(StringGrid1->Cells[3][i]));
	}

	float tmp;
	for (int i = 2; i <= 4; i++)
	{
		tmp = 0;
		for (int j = 1; j <= m; j++)
		{
			tmp += StrToFloat(StringGrid1->Cells[i][j]);
		}
		StringGrid1->Cells[i][m+1] = FloatToStr(tmp);
	}
}
//---------------------------------------------------------------------------
void TForm1::readOfEdits()
{
	D = StrToFloat(Edit1->Text);
	m = StrToFloat(Edit2->Text);
	n = StrToFloat(Edit3->Text);
	I = StrToFloat(Edit4->Text);

	m = m * n;
}
//---------------------------------------------------------------------------
void TForm1::updateCells()
{
	StringGrid1->RowCount = m + 2;
	row = StringGrid1->RowCount;
	col = StringGrid1->ColCount;

	StringGrid1->Visible = true;
	StringGrid1->Cells[0][0] = "Месяц";
	StringGrid1->Cells[1][0] = "Непогашенный долг";
	StringGrid1->Cells[2][0] = "Процентные платежи";
	StringGrid1->Cells[3][0] = "Выплота долга";
	StringGrid1->Cells[4][0] = "Сумма взноса";
	StringGrid1->Cells[0][m+1] = "ИТОГО";

	for (int i = 1; i < row - 1; i++)
		StringGrid1->Cells[0][i] = IntToStr(i);

	for (int i = 0; i < col; i++)
		StringGrid1->ColWidths[i] = StringGrid1->Cells[i][0].Length()*7;
}
//---------------------------------------------------------------------------

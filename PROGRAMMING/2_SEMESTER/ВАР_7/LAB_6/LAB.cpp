//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "LAB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int A[100][100];
int N;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	N = 3;
	StringGrid2->ColCount=N+1;
	StringGrid2->RowCount=N+1;
	StringGrid2->Cells[0][0] = 'A';
	for(int i = 1; i <= N; i++)
	{
		StringGrid2->Cells[i][0] = IntToStr(i);
	}
	for(int i = 1; i <= N; i++)
	{
		StringGrid2->Cells[0][i] = IntToStr(i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	bool semmetrichna = true;

	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			A[i][j]=StrToFloat(StringGrid2->Cells[j][i]);

	for (int i=1; i<=N-1; i++)
	{
		for (int j=1; j<=N-i; j++)
		{
			if (A[i][j] != A[N-j+1][N-i+1]) 
			{	
				semmetrichna = false;
			}
        }
	}

	if (semmetrichna)
	{
		Label2->Caption = "������� ����������� - true";
	} 
	else 
	{
        Label2->Caption = "������� ����������� - false";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	N = StrToInt(Edit1->Text);

	StringGrid2->ColCount=N+1;
	StringGrid2->RowCount=N+1;

	for(int i = 1; i <= N; i++)
	{
		StringGrid2->Cells[i][0] = IntToStr(i);
	}

	for(int i = 1; i <= N; i++)
	{
		StringGrid2->Cells[0][i] = IntToStr(i);
	}
}
//---------------------------------------------------------------------------






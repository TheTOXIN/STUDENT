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
int N, M;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	N = 3;
	M = 3;
	StringGrid2->ColCount=M+1;
	StringGrid2->RowCount=N+1;
	StringGrid2->Cells[0][0] = 'A';
	for(int i = 1; i <= M; i++)
		StringGrid2->Cells[i][0] = IntToStr(i);
	for(int i = 1; i <= N; i++)
		StringGrid2->Cells[0][i] = IntToStr(i);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int count = 0;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			A[i][j]=StrToFloat(StringGrid2->Cells[j][i]);
			
	int sum;
	for(int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++) 
		{
			sum = 0;
			for (int k = 1; k <= N; k++) 
			{
				if (j != k) 
				{
					sum += A[k][i];
				}
			}
			if (A[j][i] > sum) 
			{
				count++;
			}
		}
	}
	Label2->Caption = IntToStr(count);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	N = StrToInt(Edit1->Text);
	M = StrToInt(Edit2->Text);

	StringGrid2->ColCount=M+1;
	StringGrid2->RowCount=N+1;

	for(int i = 1; i <= M; i++)
		StringGrid2->Cells[i][0] = IntToStr(i);
	for(int i = 1; i <= N; i++)
		StringGrid2->Cells[0][i] = IntToStr(i);
}
//---------------------------------------------------------------------------


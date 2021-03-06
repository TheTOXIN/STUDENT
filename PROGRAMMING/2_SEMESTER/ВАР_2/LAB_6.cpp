//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LAB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int A[100][100];
int B[100];
int N, M;

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	N = 3;
	M = 3;
	StringGrid2->ColCount=M+1;
	StringGrid2->RowCount=N+1;
	StringGrid1->RowCount=N+1;
	StringGrid2->Cells[0][0] = 'A';
	StringGrid1->Cells[0][0] = 'B';
	for(int i = 1; i <= M; i++)
		StringGrid2->Cells[i][0] = IntToStr(i);
	for(int i = 1; i <= N; i++)
		StringGrid2->Cells[0][i] = IntToStr(i);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			A[i][j]=StrToFloat(StringGrid2->Cells[j][i]);

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M - 1; j++)
		{
			if(A[i][j] < A[i][j+1])
			{
				B[i] = 1;
                break;
			}
			else
			{
                B[i] = 0;
			}
		}
        StringGrid1->Cells[0][i] = B[i];
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	N = StrToInt(Edit1->Text);
	M = StrToInt(Edit2->Text);

	StringGrid2->ColCount=M+1;
	StringGrid2->RowCount=N+1;
	StringGrid1->RowCount=N+1;

	for(int i = 1; i <= M; i++)
		StringGrid2->Cells[i][0] = IntToStr(i);
	for(int i = 1; i <= N; i++)
		StringGrid2->Cells[0][i] = IntToStr(i);
}
//---------------------------------------------------------------------------


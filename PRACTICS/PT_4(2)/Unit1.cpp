//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double P, Q, AVC, FC;
double var, stat, vol;
double P1, P2, P3;
double res;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	P = 12000;
	Q = 70000;
	AVC = 7000;
	FC = 25000;
	vol = 1.07;
	var = 1.09;
	stat = 1.1;

	Edit1->Text = "12000";
	Edit2->Text = "70000";
	Edit3->Text = "7000";
	Edit4->Text = "25000";
	Edit5->Text = "7";
	Edit6->Text = "9";
	Edit7->Text = "10";
}
//---------------------------------------------------------------------------
void TForm1::readOfEdits()
{
	P = StrToFloat(Edit1->Text);
	Q = StrToFloat(Edit2->Text);
	AVC = StrToFloat(Edit3->Text);
	FC = StrToFloat(Edit4->Text);
	vol = StrToFloat(Edit5->Text) / 100 + 1;
	var = StrToFloat(Edit6->Text) / 100 + 1;
	stat = StrToFloat(Edit7->Text) / 100 + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	readOfEdits();

	P1 = P * Q - (AVC * Q + FC);
	P2 = P1 * stat;
	P3 = P * Q * vol - (AVC * Q * var + FC * stat);
	res = (P2 - P3) / (Q * vol);

	Label9->Caption = FloatToStr(res).SubString(0, 6) + " руб";
}
//---------------------------------------------------------------------------



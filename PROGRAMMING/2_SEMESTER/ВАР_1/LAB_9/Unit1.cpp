//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
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
float Xmin, Xmax, Y, Z, Hx, H;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Xmin = 14;
	Xmax = 28;
	Y = -1.22;
	Z = 3.5 * pow(10, -2);
	Hx = 2;
	H = 0.1;

	Edit1->Text = FloatToStr(Xmin);
	Edit2->Text = FloatToStr(Xmax);
	Edit3->Text = FloatToStr(Y);
	Edit4->Text = FloatToStr(Z);
	Edit5->Text = FloatToStr(Hx);
	Edit7->Text = FloatToStr(H);

	Chart1->BottomAxis->Automatic = false;
	Chart1->BottomAxis->Minimum = Xmin;
	Chart1->BottomAxis->Maximum = Xmax;
	Chart1->BottomAxis->Increment = Hx;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Xmin = StrToFloat(Edit1->Text);
	Xmax = StrToFloat(Edit2->Text);
	Y = StrToFloat(Edit3->Text);
	Z = StrToFloat(Edit4->Text);
	Hx = StrToFloat(Edit5->Text);

	Chart1->BottomAxis->Minimum = Xmin;
	Chart1->BottomAxis->Maximum = Xmax;
	Chart1->BottomAxis->Increment=Hx;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	float X, t;
	Series1->Clear();
	Xmin = StrToFloat(Edit1->Text);
	Xmax = StrToFloat(Edit2->Text);
	H = StrToFloat(Edit7->Text);
	X = Xmin;
	while(X <= Xmax)
	{
		float t1 = (2 * cos(X - 3.14/6)) / (0.5 + pow(sin(Y),2));
		float t2 = 1 + (pow(Z,2)/(3-pow(Z,2)/5));
		t = t1 * t2;
		Series1->AddXY(X,t,"",clTeeColor);
		X += H;
	}
}
//---------------------------------------------------------------------------



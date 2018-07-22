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
float Xmin, Xmax, Y, Z, Hx, H, A;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Xmin = 0;
	Xmax = 39.81 * pow(10, -2);
	Y = -1.625 * pow(10,3);
	Z = 0.512;
	Hx = 1;
	H = 0.1;
	A = 1.26185;

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
	float X, a;
	Series1->Clear();
	Xmin = StrToFloat(Edit1->Text);
	Xmax = StrToFloat(Edit2->Text);
	H = StrToFloat(Edit7->Text);
	X = Xmin;
	while(X <= Xmax)
	{
		float a1 = pow(2,-X) * sqrt(X + pow(fabs(Y), 1/4));
		float a2 = pow(pow(2.7, X - 1/sin(Z)),1/3);
		a = a1 * a2;
		Series1->AddXY(X,a,"",clTeeColor);
		X += H;
	}
}
//---------------------------------------------------------------------------



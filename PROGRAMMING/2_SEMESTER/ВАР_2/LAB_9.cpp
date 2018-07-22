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
	Xmin = -4;
	Xmax = 8;
	Y = 0.75 * pow(10.0, -4);
	Z = 0.845 * pow(10.0, 2);
	Hx = 0.5;
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
	float X, u;
	Series1->Clear();
	Xmin = StrToFloat(Edit1->Text);
	Xmax = StrToFloat(Edit2->Text);
	H = StrToFloat(Edit7->Text);
	X=Xmin;
	while(X <= Xmax)
	{
		float u1 = pow((8+pow(abs(X-Y),2) + 1), 1/3) / (pow(X,2) + pow(Y, 2) + 2);
		float u2 = exp(abs(X-Y)) * pow(pow(tan(Z),2) +1,X);
		u = u1 - u2;
		Series1->AddXY(X,u,"",clTeeColor);
		X += H;
	}
}
//---------------------------------------------------------------------------



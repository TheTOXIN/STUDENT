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
float Xmin, Xmax, Y, Z, Hx, H, G;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Xmin = 0;
	Xmax = 12.3 * pow(10, -1);
	Y = 15.4;
	Z = 0.252*pow(10, 3);
	Hx = 1;
	H = 0.1;
	G = 82.8257;

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
	float X, g;
	Series1->Clear();
	Xmin = StrToFloat(Edit1->Text);
	Xmax = StrToFloat(Edit2->Text);
	H = StrToFloat(Edit7->Text);
	X = Xmin;
	while(X <= Xmax)
	{
		float g1 = (pow(Y, X + 1))/pow(fabs(Y-2),1/3)+3;
		float g2 = (X + Y / 2) / (2 * fabs(X + Y)) * pow(X + 1, -1 / sin(Z));
		g = g1 + g2;
		Series1->AddXY(X,g,"",clTeeColor);
		X += H;
	}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
#include <vcl.h>
#include <dstring.h>
#include <string>
#pragma hdrstop
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

void __fastcall TForm1::FormActivate(TObject *Sender)
{
	ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int ind = ListBox1->ItemIndex;
	int count = 0;

	AnsiString str = ListBox1->Items->Strings[ind];
	AnsiString tmpStr;
	AnsiString res = "";

	int i = 1;
	while (i <= str.Length())
	{
		if (str[i] != ' ')
		   tmpStr += str[i];
		else
		{
			if (tmpStr.Length() % 2 == 0)
				res += tmpStr + " ";
			tmpStr = "";
		}
		i++;
	}
	if (tmpStr.Length() % 2 == 0)
				res += tmpStr + " ";
    Label1->Caption = "вермше цпсоош = " + res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1KeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key==13)
	{
		ListBox1->Items->Add(ComboBox1->Text);
		ComboBox1->Items->Add(ComboBox1->Text);
		ComboBox1->Text="";
	}
}
//---------------------------------------------------------------------------


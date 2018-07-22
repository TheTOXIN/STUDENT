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
	AnsiString string = ListBox1->Items->Strings[ind];
	AnsiString label = "";
	AnsiString number = "";

	int i = 1;
	while (i <= string.Length())
	{
		if (string[i] != ' ')
		{
		   number += string[i];
        	}
		else
		{
			if (StrToInt(number) % 2 == 0)
			{
				label = label + number + " ";
			}
			number = "";
		}
		if (i == string.Length())
		{
           if (StrToInt(number) % 2 == 0)
			{
				label = label + number + " ";
			}
		}
		i++;
	}
    Label1->Caption = "Четные числа : " + label;
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


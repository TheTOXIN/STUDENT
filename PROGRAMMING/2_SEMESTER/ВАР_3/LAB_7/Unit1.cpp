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
	AnsiString str = ListBox1->Items->Strings[ind];
	AnsiString maxStr = "";
	AnsiString tmpStr = "";

	int len = 1;
	int max = 0;
	char tmp = 0;

	int i;
	for (i = 1; i <= str.Length(); i++)
	{
		if (i != str.Length())
		{
			if (str[i] == str[i+1])
			{
				len++;
				tmpStr += str[i];
				continue;
			}
		}
		if (len > max)
		{
			max = len;
			maxStr = tmpStr;
			tmpStr = "";
		}
		len = 1;
	}

	Label1->Caption = "Самая длинная группа - " + maxStr;
	Label2->Caption = "Длина - " + IntToStr(max);
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


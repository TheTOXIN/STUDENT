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
void __fastcall TForm1::ComboBox1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key==13)
	{
		ListBox1->Items->Add(ComboBox1->Text);
		ComboBox1->Items->Add(ComboBox1->Text);
		ComboBox1->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int ind = ComboBox1->ItemIndex;
	AnsiString str = ListBox1->Items->Strings[ind];

	int n = 1;
	int min = 1000;
	char tmp = 0;

	int i;
	for (i = 1; i <= str.Length()-1; i++)
	{
		if (str[i] == str[i+1])
		{
			n++;
            continue;
		}
		if (n < min)
		{
			min = n;
            tmp = str[i];
        }
		n = 1;
	}
	if (n < min)
	{
		min = n;
		tmp = str[i];
	}

	String strMin = "";
	for(int i = 0; i < min; i++)
	{
		strMin = strMin + tmp;
	}

	Label1->Caption = "Самая коротка строка из группы: " + strMin + '\n' + "Длина группы = " + min;
}
//---------------------------------------------------------------------------

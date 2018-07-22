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
	int k = StrToInt(Edit1->Text);
	int ind = ListBox1->ItemIndex;
	int index1;
	int index2;
	AnsiString s = ListBox1->Items->Strings[ind];
	AnsiString word = "";
	AnsiString word_k = "";
	AnsiString label = "";

	int i = 1;
	while (i <= s.Length())
	{
		index1 = i;
		while(s[i] != ' ')
		{
			word += s[i];
			i++;
			if (i > s.Length())
				break;
		}
		index2 = i;
		if (k >= index1 && k <= index2)
			word_k = word;
		word = "";
		i++;
	}

	label = "ÂÀØÅ ÑËÎÂÎ - " + word_k;
	Label1->Caption = label;
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

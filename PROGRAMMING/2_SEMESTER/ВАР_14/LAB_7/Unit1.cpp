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
	int pos = 0;
	int index = 0;
	int count_word = 1;
	AnsiString s = ListBox1->Items->Strings[ind];
	AnsiString word = "";
	AnsiString max_word = "";
	AnsiString label = "";

	int i = 1;
	while (i <= s.Length())
	{
		while(s[i] != ' ' && i != s.Length())
		{
			word += s[i];
			i++;
		}

		if (word.Length() > max_word.Length())
		{
			max_word = word;
			pos = i - max_word.Length();
			index = count_word;
		}

		word = "";
		i++;
		count_word++;
	}

	label = "Cлово - " + max_word + ", Индекс - " + index + ", Позиция - " + pos;
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


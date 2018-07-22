//---------------------------------------------------------------------------

#include <vcl.h>
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    //ADOTable1->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ADOTable1->First();
	while(ADOTable1->Eof!=true)
	{
		if (ADOTable1SURNAME->Value == Edit1->Text)
		{
			ListBox1->Items->Add("Пары для - " + ADOTable1NAME->Value + " " + ADOTable1SURNAME->Value + ":");
			AnsiString sex = ADOTable1SEX->Value;
			AnsiString call = ADOTable1CALL->Value;

			ADOTable1->First();
			while(ADOTable1->Eof!=true)
			{
				if (sex != ADOTable1SEX->Value && call == ADOTable1INFO->Value)
				{
					AnsiString messege = ADOTable1NAME->Value + " " + ADOTable1SURNAME->Value;
					ListBox1->Items->Add(messege);
				}
				ADOTable1->Next();
			}
		}
		ADOTable1->Next();
	}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <ADODB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TDBNavigator *DBNavigator1;
	TListBox *ListBox1;
	TButton *Button1;
	TEdit *Edit1;
	TADOTable *ADOTable1;
	TWideStringField *ADOTable1NAME;
	TWideStringField *ADOTable1SURNAME;
	TWideStringField *ADOTable1SEX;
	TIntegerField *ADOTable1REG;
	TDateTimeField *ADOTable1DATE;
	TWideStringField *ADOTable1INFO;
	TWideStringField *ADOTable1CALL;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

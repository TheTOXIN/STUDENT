//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TButton *Button1;
	TEdit *Edit2;
	TListBox *ListBox1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	int firstDayofNewYearAndMonth(int);
	int numOfDaysInAMonth(int);
	void printHeader(int);
	void printMonth(int, int&);
	void skipToDay(int);
	void skip(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

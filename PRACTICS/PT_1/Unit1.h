//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
#include "BubbleCh.hpp"
#include "Series.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TChart *Chart1;
	TLineSeries *Series1;
	TButton *Button1;
	TBubbleSeries *Series2;
	TButton *Button2;
	TStringGrid *StringGrid1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void drawBubbleField();
	void countAverageValue();
	void countDesperssion();
	void countRegression();
	void drawLineRegress();
	void printInfo();
	void fillGrid();
	void fillXY();
	void setDefault();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

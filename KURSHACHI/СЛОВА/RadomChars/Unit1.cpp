//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "fstream"
#include "iostream"
#include "time.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace std;

TForm1 *Form1;
Graphics::TBitmap *back = new Graphics::TBitmap();

AnsiString words[10000];
AnsiString randomWord;
AnsiString rigthWord;
AnsiString currectWord = "";

int countMove;
int score = 0;
int posX1, posY1, posX2, posY2;
int countWords = 0;
int sizeFont = 70;
int podskazka = 3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(NULL));
	back->LoadFromFile("back.bmp");
	loadWords();
}
//---------------------------------------------------------------------------
void TForm1::loadWords()
{
	AnsiString text = "";
	TFileStream *file = new TFileStream("words.txt",fmOpenReadWrite);
	file->Seek(0,0);
	char *buffer;
	if ((buffer = (char *) malloc(file->Size)) == NULL)
		return;
	file->Read(buffer,file->Size);
	text = buffer;
	text.SetLength(file->Size);

	AnsiString word = "";
	int i = 1;
	while (i <= text.Length() && text[i] != '#')
	{
		while(text[i] != '\n' && i != text.Length())
		{
			word += text[i];
			i++;
		}
		word.Delete(word.Length(),1);
		words[countWords] = word;
		word = "";
		i++;
		countWords++;
	}
}
//---------------------------------------------------------------------------
AnsiString TForm1::randomChars(AnsiString str)
{
	rigthWord = str;
	for (int i = 1; i <= str.Length(); i++)
	{
		int index1 = rand() % str.Length() + 1;
		int index2 = rand() % str.Length() + 1;
		char tmp = str[index1];
		str[index1] = str[index2];
		str[index2] = tmp;
	}
	return str;
}
//---------------------------------------------------------------------------
void TForm1::drawWord()
{
	Canvas->Font->Color = clBlue;
	Canvas->Font->Size = sizeFont;
	Canvas->Pen->Width = 5;
	Canvas->Brush->Color=clGray;
	Canvas->RoundRect(posX1 - 500, posY1 - 10, posX2+500, posY2+10, 10, 10);
	Canvas->Brush->Color=clWhite;
	Canvas->RoundRect(posX1 - 10, posY1 - 10, posX2+5, posY2+10, 10, 10);

	int i;
	for (i = 0; i < randomWord.Length(); i++)
	{
		int recX = i * sizeFont + posX1;
		int recY = posY1;
		Canvas->Rectangle(recX + (i * 10), recY, recX + sizeFont + (i * 10), recY + sizeFont);
		AnsiString charStr = randomWord[i+1];
		Canvas->Brush->Style = bsClear;
		Canvas->TextOutA(recX + (i * 10) + 10, recY - 30, charStr);
	}	
}
//---------------------------------------------------------------------------
void TForm1::newWord()
{
	randomWord = randomChars(words[rand() % countWords]);
	currectWord = "";
	countMove = randomWord.Length();

	posX1 = Form1->Width / 2 - (randomWord.Length() * (sizeFont + 10) / 2);
	posY1 = Form1->Height / 2 - sizeFont;
	posX2 = posX1 + randomWord.Length() * (sizeFont + 10);
	posY2 = posY1 + sizeFont;

	drawWord();
}
//---------------------------------------------------------------------------
void TForm1::newGame()
{
	newWord();
	
	score = 0;
	countMove = randomWord.Length();
	podskazka = 3;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (podskazka > 0)
	{
		ShowMessage("�����: " + rigthWord);
		if (podskazka > 0)
			podskazka--;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	drawWord();

	Canvas->Draw(0,0, back);
	Canvas->Brush->Color=clWhite;
	Canvas->Rectangle(10,10,330,80);
	
	Label1->Caption = "����: " + IntToStr(countMove);
	Label2->Caption = "����: " + IntToStr(score);
	Button1->Caption = "��������� (" + IntToStr(podskazka) + ")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbLeft)
		if (X >= posX1 && Y >= posY1 && X <= posX2 && Y <= posY2)
		{
			int kletka = (X - posX1 - 10) / (sizeFont + 8) + 1;
			if (countMove > 0 && kletka != 0 && !(kletka > randomWord.Length()))
			{
				currectWord += randomWord[kletka];
				countMove--;
			}
		}
	if(Button == mbRight)
	{
		currectWord.Delete(currectWord.Length(),1);
		if (countMove < randomWord.Length())
			countMove++;		
	}
	Label3->Caption = currectWord;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (currectWord == rigthWord) 
	{
		ShowMessage("=) +" + IntToStr(rigthWord.Length()) + " �����");
		score += rigthWord.Length(); 
	}
	else
	{	
		ShowMessage("=( -" + IntToStr(rigthWord.Length()) + " �����");
		score -= rigthWord.Length();
	}
	newWord();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	newGame();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
	newGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	ShowMessage("�������� ������\n��1602\n�������� ĸ����");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	ShowMessage("��� - ��������� ����� \n ��� - ������ �����");
}
//---------------------------------------------------------------------------


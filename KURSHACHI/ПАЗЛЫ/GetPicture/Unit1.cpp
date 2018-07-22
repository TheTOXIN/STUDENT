//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "math.hpp"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#define W 4
#define H 4
//---------------------------------------------------------------------------
TForm1 *Form1;
byte wc, hc;
byte pole[H][W];
int ex, ey;
bool GameOver;
AnsiString fn;
TSearchRec SearchRec;
Graphics::TBitmap *pic;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	pic = new Graphics::TBitmap();
}
//---------------------------------------------------------------------------
void TForm1::NewGame()
{
    if (OpenDialog1->Execute())
	{
		fn = OpenDialog1->FileName;
	}

	try
	{
        pic->LoadFromFile(fn);
	}
	catch (EFOpenError &e)
	{
		MessageDlg("������ ��� �������� �����",
			mtWarning, TMsgDlgButtons()<<mbOK<<mbHelp,0);
		return;
	}

	wc = pic->Width / W;
	hc = pic->Height / H;
	ClientWidth = wc * W;
	ClientHeight = hc * H;

	int k = 1;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			pole[i][j] = k++;

	GameOver = false;
	Mixer();
	ShowPole();
}
//---------------------------------------------------------------------------
void TForm1::Mixer()
{
	int x1, y1;
	int x2, y2;
	int d;

	Randomize();

	x1 = 3, y1 = 3;
	
	for (int i = 0; i < 150; i++) 
	{
		do
		{
			x2 = x1;
			y2 = y1;
			d = RandomRange(1,5);
			switch(d)
			{
				case 1: x2--; break;
				case 2: x2++; break;
				case 3: y2--; break;
				case 4: y2++; break;
            }
		} while ((x2 < 0) || (x2 >= W) || (y2 < 0 || (y2 >= H)));

		pole[y1][x1] = pole[y2][x2];
		pole[y2][x2] = 16;
		x1 = x2;
		y1= y2;
	}
	
	ex = x1;
	ey = y1;
}
//---------------------------------------------------------------------------
void TForm1::ShowPole()
{
	TRect src, dst;

	int sx, sy;

	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			sx = ((pole[i][j]-1) % W) * wc;
			sy = ((pole[i][j]-1) / H) * hc;

			src = Bounds(sx, sy, wc, hc);
			dst = Bounds(j*wc, i*hc, wc, hc);

			if ((pole[i][j]) != 16 || GameOver)
				Canvas->CopyRect(dst, pic->Canvas, src);
			else
			{
				Canvas->Brush->Style = bsSolid;
				Canvas->Brush->Color = clBtnFace;
				Canvas->Rectangle(dst);
            }
		}
	}

	if (N4->Checked) 
	{
		Canvas->Brush->Style = bsClear;
		Canvas->Font->Size = 20;
		Canvas->Font->Color = clWhite;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				Canvas->TextOutA(wc*j, hc*i, IntToStr(pole[i][j]));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	int cx, cy;
	cx = X / wc;
	cy = Y / hc;
	Move(cx, cy);
}
//---------------------------------------------------------------------------
void TForm1::Move(int cx, int cy)
{
	if ((abs(cx - ex) == 1) && (cy - ey == 0) ||
		(abs(cy - ey) == 1) && (cx - ex == 0))
	{
		pole[ey][ex] = pole[cy][cx];
		pole[cy][cx] = 16;
		ex = cx;
		ey = cy;
		ShowPole();
		if (Finish()) 
		{
			GameOver = true;
			ShowPole();
			int r = MessageDlg("���� ����������! ��� ���?", mtInformation,
								TMsgDlgButtons() << mbYes << mbNo, 0);
			if (r = mrNo)
				Form1->Close();
			else
			{
				NewGame();
				ShowPole();
            }
		}
	}
}
//---------------------------------------------------------------------------
bool TForm1::Finish()
{
	bool result;
	int row, col;
	int k = 1;

	result = true;
	for (row = 0; row < H; row++)
	{
		for (col = 0; col < W; col++) 
		{
			if (pole[row][col] == k)
				k++;
			else
			{    
				result = false;
				break;
            }
		}
		if(!result)
			break;
	}
	return result;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	ShowPole();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
	NewGame();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	ShowMessage("�����: ���� �������� ��1602");	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
	N4->Checked = !N4->Checked;
	ShowPole();	
}
//---------------------------------------------------------------------------



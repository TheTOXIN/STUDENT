//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
int Game[3][3]; //������� ����
bool EndOfGame; //��������� ���� ������, true - ���� ���� ��������� ����� false
bool isBotON; //��� ��������� � ��������� ����
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)//������� ���������� ��� ������� ���������
{
	for(int j=0;j<3;j++)//����������� ����� ��� �����
		for(int i=0;i<3;i++)
			Game[i][j]=0;//� ����������� ��������� ������� 0

	Krestik = new Graphics::TBitmap();//���������� �������� (�������� � Unit1.h)
	Krestik->LoadFromFile("Krestik.bmp");//��������� ��������
	Krestik->Transparent=true;//������ �������� �� �������������

	Nolik = new Graphics::TBitmap();//���� ����� ������ ��� �������� ������
	Nolik->LoadFromFile("Nolik.bmp");
	Nolik->Transparent=true;

	Canvas->Pen->Width=10;//����� ����� Canvas � ������ � ��� ����� Pen ������ 5 ��� ��������� �����
	ViktoryLine1=Point(-1,-1);//����������� ���������� ViktoryLine1(�������� � Unit1.h) ����������
	ViktoryLine2=Point(-1,-1);//���� ����� ��� ViktoryLine2
	EndOfGame = false;//������ false, ������ ���� �� ���������
	isBotON = true;
}
//---------------------------------------------------------------------------
TForm1::DrawKresikAndNolik()//������� ���������
{
	Canvas->Brush->Color = clWhite;//������ �� ����� ����
	Canvas->Rectangle(-10,-10,500,500);//����������� ���

	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(100,10);//�������� ������� ����� � ������
	Canvas->LineTo(100,290);//� ������ ����� �� ������ ����� �� ���� ���������
	Canvas->MoveTo(200,10) ;//������ ��������� ��� ���� �����
	Canvas->LineTo(200,290);//����� ������� ������ 4 �����
	Canvas->MoveTo(10,100) ;
	Canvas->LineTo(290,100);
	Canvas->MoveTo(10,200) ;
	Canvas->LineTo(290,200);

	for(int j=0;j<3;j++)//����������� �� ������� ����
		for(int i=0;i<3;i++)
			if(Game[i][j]==1)//���� ������� ����� 1 ������ ������ �� ������ � ������������ �� j � i
				Canvas->Draw(i*100+10,j*100+10,Krestik);
			else if(Game[i][j]==2)//���� 2 �� �����
				Canvas->Draw(i*100+10,j*100+10,Nolik);

	if(ViktoryLine1.x != -1)//������ ���� ������������� ������� ���� ��� �����
	{
		Canvas->Pen->Color=clGreen;//����� ������� ����
		Canvas->MoveTo(ViktoryLine1.x*100+50,ViktoryLine1.y*100+50);//������ ������
		Canvas->LineTo(ViktoryLine2.x*100+50,ViktoryLine2.y*100+50);//� ���������� �� ViktoryLine1 � 2
		Canvas->Pen->Color=clBlack;
	}
 	return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)//������� �������� ������� ��������� DrawKresikAndNolik
{
	DrawKresikAndNolik();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{//������� ���������� ��� ������� �� ������ ����
	if(!EndOfGame)//���� ���� �� ���������
	{
		int KletkaX = X / (100);//����������� ���������� �� �������
		int KletkaY = Y / (100);//����� ���������� ����� � ����� �� 100
		if((Game[KletkaX][KletkaY]!=2)&&(Game[KletkaX][KletkaY]!=1))//���� �  ���� ������ ���� �������
		{
			if(Button==mbLeft)Game[KletkaX][KletkaY]=1;//������ � ������� 1 ���� ����� ������ ����
			if(Button==mbRight)Game[KletkaX][KletkaY]=2;//������ 2 ���� ������
			int viktory=TestForVictory();//�������� ������ �������� ������
			Repaint();//������������� �����
			//������������ �� ���� ������ ���������� ����
			if(viktory==1){ShowMessage("���� ������");EndOfGame=true;}else
			if(viktory==3){ShowMessage("�����");EndOfGame=true;}else
			if(viktory==2){ShowMessage("������ ����������");EndOfGame=true;
			}
			else//����� ��� ������ �� �������
			{
				Sleep(300);
				if (isBotON)
					HodComputera();//�������� ������� � ������� ����� ���������
				viktory=TestForVictory();//� ��� ���� �����
				Repaint();
				if(viktory==1){ShowMessage("���� ������");EndOfGame=true;}else
				if(viktory==3){ShowMessage("�����");EndOfGame=true;}else
				if(viktory==2){ShowMessage("������ ����������");EndOfGame=true;}
			}
		}
	}
}
//---------------------------------------------------------------------------
TForm1::HodComputera()//������� ���� ���������� ���
{
	//����� ��������, ����� ���� ��� ����� �� �������� ������ (0 0)
	for(int i=0;i<3;i++)
	{
		if((Game[0][i]==2)&&(Game[1][i]==2)&&(Game[2][i]==0)){Game[2][i]=2;return 0;} //110
		else if((Game[1][i]==2)&&(Game[2][i]==2)&&(Game[0][i]==0)){Game[0][i]=2;return 0;} //011
		else if((Game[0][i]==2)&&(Game[2][i]==2)&&(Game[1][i]==0)){Game[1][i]=2;return 0;} //101
		else if((Game[i][0]==2)&&(Game[i][1]==2)&&(Game[i][2]==0)){Game[i][2]=2;return 0;} //110
		else if((Game[i][1]==2)&&(Game[i][2]==2)&&(Game[i][0]==0)){Game[i][0]=2;return 0;} //011
		else if((Game[i][0]==2)&&(Game[i][2]==2)&&(Game[i][1]==0)){Game[i][1]=2;return 0;} //101
	}

	//��������� ����� �������
	if((Game[0][0]==2)&&(Game[1][1]==2)&&(Game[2][2]==0)){Game[2][2]=2;return 0;} //110
	else if((Game[1][1]==2)&&(Game[2][2]==2)&&(Game[0][0]==0)){Game[0][0]=2;return 0;} //011
	else if((Game[0][0]==2)&&(Game[2][2]==2)&&(Game[1][1]==0)){Game[1][1]=2;return 0;} //101
	else if((Game[2][0]==2)&&(Game[1][1]==2)&&(Game[0][2]==0)){Game[0][2]=2;return 0;} //110
	else if((Game[1][1]==2)&&(Game[0][2]==2)&&(Game[2][0]==0)){Game[2][0]=2;return 0;} //011
	else if((Game[2][0]==2)&&(Game[0][2]==2)&&(Game[1][1]==0)){Game[1][1]=2;return 0;} //101

	//����� ������� ��������  ���� XX
	for(int i=0;i<3;i++)
	{
		if((Game[0][i]==1)&&(Game[1][i]==1)&&(Game[2][i]==0)){Game[2][i]=2;return 0;} //110
		else if((Game[1][i]==1)&&(Game[2][i]==1)&&(Game[0][i]==0)){Game[0][i]=2;return 0;} //011
		else if((Game[0][i]==1)&&(Game[2][i]==1)&&(Game[1][i]==0)){Game[1][i]=2;return 0;} //101
		else if((Game[i][0]==1)&&(Game[i][1]==1)&&(Game[i][2]==0)){Game[i][2]=2;return 0;} //110
		else if((Game[i][1]==1)&&(Game[i][2]==1)&&(Game[i][0]==0)){Game[i][0]=2;return 0;} //011
		else if((Game[i][0]==1)&&(Game[i][2]==1)&&(Game[i][1]==0)){Game[i][1]=2;return 0;} //101
	}

	//��������� ����� �������
	if((Game[0][0]==1)&&(Game[1][1]==1)&&(Game[2][2]==0)){Game[2][2]=2;return 0;} //110
	else if((Game[1][1]==1)&&(Game[2][2]==1)&&(Game[0][0]==0)){Game[0][0]=2;return 0;} //011
	else if((Game[0][0]==1)&&(Game[2][2]==1)&&(Game[1][1]==0)){Game[1][1]=2;return 0;} //101
	else

	//��������� ������ �� ����
	if((Game[2][0]==1)&&(Game[1][1]==1)&&(Game[0][2]==0)){Game[0][2]=2;return 0;} //110
	else if((Game[1][1]==1)&&(Game[0][2]==1)&&(Game[2][0]==0)){Game[2][0]=2;return 0;} //011
	else if((Game[2][0]==1)&&(Game[0][2]==1)&&(Game[1][1]==0)){Game[1][1]=2;return 0;} //101

 	if(Game[1][1]==0){Game[1][1]=2;return 0;}
	for(int j=0;j<3;j++)
		for(int i=0;i<3;i++)
			if(Game[i][j]==0){Game[i][j]=2;return 0;}
return 0;
}
//---------------------------------------------------------------------------
int TForm1::TestForVictory()//������� �������� ������
//������� ������� 1 ���� ������ ��������, 2 - ���������, 3 - �����
{
	//������ ���������� ��� ��������� �������� ������
	//� ������ ���������� ����� ������������ � ����������� �� ������
	for(int i=0;i<3;i++)
	{
		if((Game[i][0]==1)&&(Game[i][1]==1)&&(Game[i][2]==1))
			{ViktoryLine1=Point(i,0);ViktoryLine2=Point(i,2);return 1;}
		if((Game[0][i]==1)&&(Game[1][i]==1)&&(Game[2][i]==1))
			{ViktoryLine1=Point(0,i);ViktoryLine2=Point(2,i);return 1;}
		if((Game[i][0]==2)&&(Game[i][1]==2)&&(Game[i][2]==2))
			{ViktoryLine1=Point(i,0);ViktoryLine2=Point(i,2);return 2;}
		if((Game[0][i]==2)&&(Game[1][i]==2)&&(Game[2][i]==2))
			{ViktoryLine1=Point(0,i);ViktoryLine2=Point(2,i);return 2;}
	}
	//�������� ��� ����������
	if((Game[0][0]==1)&&(Game[1][1]==1)&&(Game[2][2]==1))
		{ViktoryLine1=Point(0,0);ViktoryLine2=Point(2,2);return 1;}
	if((Game[2][0]==1)&&(Game[1][1]==1)&&(Game[0][2]==1))
		{ViktoryLine1=Point(2,0);ViktoryLine2=Point(0,2);return 1;}
	if((Game[0][0]==2)&&(Game[1][1]==2)&&(Game[2][2]==2))
		{ViktoryLine1=Point(0,0);ViktoryLine2=Point(2,2);return 2;}
	if((Game[2][0]==2)&&(Game[1][1]==2)&&(Game[0][2]==2))
		{ViktoryLine1=Point(2,0);ViktoryLine2=Point(0,2);return 2;}

	if(!EndOfGame)//���� ���� �� ���������
	{
		bool err=false;//��������� ���� �� ����� ������ � err

		for(int j=0;j<3;j++)
			for(int i=0;i<3;i++)
				if(Game[i][j]==0)
					err=true;

		if(err==false)
			return 3;
	}
	return 0;
}
//---------------------------------------------------------------------------
void TForm1::NewGame()//������� ����� ����
{
	for(int j=0;j<3;j++)//����������� ���� ������ ����
		for(int i=0;i<3;i++)
			Game[i][j]=0;

	ViktoryLine1=Point(-1,-1);//����������� ���������� ������ ������������
	ViktoryLine2=Point(-1,-1);
	EndOfGame=false;//���� ��������� = false
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)//���������� ��� ����� �� ��������� ����
{
	NewGame();//������� ����� ����
	Repaint();//�������������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	ShowMessage("�����: ���� ���������� ��1602");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	ShowMessage("�����: ���� ���������� ��1602");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	isBotON = !isBotON;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	NewGame();//������� ����� ����
	Repaint();//�������������
}
//---------------------------------------------------------------------------


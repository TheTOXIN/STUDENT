//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "time.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)//NEW
{
	StringGrid1->Visible=true;
	StringGrid1->RowCount=1;
	StringGrid1->ColWidths[0]=30;
	StringGrid1->ColWidths[1]=150;
	StringGrid1->ColWidths[2]=100;
	StringGrid1->ColWidths[3]=100;
	StringGrid1->ColWidths[4]=100;
	StringGrid1->Cells[0][0]="�";
	StringGrid1->Cells[1][0]="�����";
	StringGrid1->Cells[2][0]="����������";
	StringGrid1->Cells[3][0]="����";
	StringGrid1->Cells[4][0]="����";
	Button5Click(Sender);
    StringGrid1->FixedRows=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)//ADD
{
	StringGrid1->RowCount++;
	StringGrid1->Cells[0][StringGrid1->RowCount-1]=IntToStr(StringGrid1->RowCount-1);
	for (int i=1; i<=4; i++)
		StringGrid1->Cells[i][StringGrid1->RowCount-1]="...";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)//DEL
{
	int k=StringGrid1->Row;
	if (k>0)
	{
		for (int i=k+1; i<StringGrid1->RowCount; i++)
			for (int j=0; j<StringGrid1->ColCount; j++)
				if (j==0)
					StringGrid1->Cells[0][i]=IntToStr(i);
				else
					StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
	StringGrid1->RowCount--;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)//OPEN
{
	// ������ �� �����
	int myfile, row, col, lenStr;
	char *pszBuffer;
	if (OpenDialog1->Execute())
	{
		myfile = FileOpen(OpenDialog1->FileName, fmOpenRead);
		Form1->Button1Click(Sender);
		// ������ �� ����� ���������� ������� � ����� �������
		FileRead(myfile,&col,sizeof(StringGrid1->ColCount));
		FileRead(myfile,&row,sizeof(StringGrid1->RowCount));
		StringGrid1->ColCount=col;
		StringGrid1->RowCount=row;
		// ������ ���������� �������
		for (int i=0; i<col; i++)
		{
			for (int j=0; j<row; j++)
			{
				// ������ ����� ���������� ������
				FileRead(myfile, &lenStr, sizeof(lenStr));
				//������ ����� ��� ������
				pszBuffer = new char[lenStr+1];
				// ������ ���� ������
				FileRead(myfile,pszBuffer, lenStr);
				StringGrid1->Cells[i][j]=AnsiString(pszBuffer,lenStr);
				// ������� ����� ��� ������
				delete[] pszBuffer;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)//SAVE
{
	// ������ � ����
	if (SaveDialog1->Execute())
	{
		int iLength;
		int myfile=FileCreate(SaveDialog1->FileName);
		// ���������� � �������� ���� ���������� ������� � ����� �������
		FileWrite(myfile, (char*)&(StringGrid1->ColCount), sizeof(StringGrid1->ColCount));
		FileWrite(myfile, (char*)&(StringGrid1->RowCount), sizeof(StringGrid1->RowCount));
		// ������ ���������� �������
		for (int i=0;i<StringGrid1->ColCount;i++)
		{
			for (int j=0;j<StringGrid1->RowCount;j++)
			{
				// ���������� ����� ������
				iLength = StringGrid1->Cells[i][j].Length();
				FileWrite(myfile, (char*)&iLength, sizeof(iLength));
				//�������� ����� ������ �� ��������� ����������
				AnsiString temp = StringGrid1->Cells[i][j];
				FileWrite(myfile,temp.c_str(), StringGrid1->Cells[i][j].Length());
			}
		}
		FileClose(myfile);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)//SORT
{
	//������ ����� �� ������� ����
	const time_t timer = time(NULL);
	//���������� ������� ������� � ��������� tm
	struct tm *u;
	u = localtime(&timer);
	//�������������� ������� ���� � 3 ����������
	int now_year = 1900 + u->tm_year;
	int now_month = u->tm_mon + 1;
	int now_day = u->tm_mday;
	//����������� ���-�� ����
	int now_days = now_year * 365 + now_day + now_month * 31;

	//���� ���-�� �����/���������
	int col = StringGrid1->ColCount;
	int row = StringGrid1->RowCount;
	//�������������� ������ ��� ������� str_cells
	const int str_cells_row = 5;
	const int str_cells_col = 8;
	//str_cells ����� ������� StringGrid1
	AnsiString str_cells[str_cells_row][str_cells_col];
	
	//����� ���� �������������� str_cells ��� ������� ������
	for(int i = 1; i < row; i++)
	{
		//�������� ������ ����� � ��������� �������
		AnsiString str_data = StringGrid1->Cells[4][i];
		AnsiString str_price = StringGrid1->Cells[3][i];
		AnsiString str_count = StringGrid1->Cells[2][i];
		AnsiString str_name = StringGrid1->Cells[1][i];
		//��������� ������� str_data � 4 ����������
		int year = str_data.SubString(7,4).ToInt();
		int month = str_data.SubString(4,2).ToInt();
		int day = str_data.SubString(1,2).ToInt();
		int days = year * 365 + day + month * 31;
		//��������� ���-�� ��������� ����
		int raz = now_days - days;
		//���� ����������� ������� �� ������� � ������ �����
		if(StrToInt(raz) > 31 && StrToInt(str_price) > 1000000)
		{
			str_cells[1][i] = str_name;
			str_cells[2][i] = str_count;
			str_cells[3][i] = str_price;
			str_cells[4][i] = str_data;
		}
	}

	//���������� ������� str_cells �� �������� 
	for(int i = 1; i < str_cells_col; i++)
	{
		for(int j = i+1; j < str_cells_col; j++)
		{
			if(str_cells[1][i] > str_cells[1][j])
			{
				//��������� ������ �����(4)
				AnsiString tmp;

				tmp = str_cells[1][j];
				str_cells[1][j] = str_cells[1][i];
				str_cells[1][i] = tmp;

				tmp = str_cells[2][j];
				str_cells[2][j] = str_cells[2][i];
				str_cells[2][i] = tmp;

				tmp = str_cells[3][j];
				str_cells[3][j] = str_cells[3][i];
				str_cells[3][i] = tmp;

				tmp = str_cells[4][j];
				str_cells[4][j] = str_cells[4][i];
				str_cells[4][i] = tmp;
            }
        }
    }

	//������� ����� ���� � ������� ������ �������
	Form1->Button1Click(Sender);
	Form1->Button4Click(Sender);

	//������� ������������� str_cells � StringGrid1
	for (int i=1; i<row; i++)
	{
		//��������� �������
		Form1->Button5Click(Sender);
		//���� ��� ������ �� ������ �� ��������� ���
		if(str_cells[1][i] != "")
		{
			for (int j=1; j<col; j++)
			{
				StringGrid1->Cells[j][i]=str_cells[j][i];
			}
        }
	}

	//������� ���-�� ������ �����
	int count_delete = 0;
	for (int i=1; i < StringGrid1->RowCount; i++)
	{
		if(StringGrid1->Cells[1][i] == "...")
		{
			count_delete++;
		}
	}

	//������� ������ ����� ���� ��� ����
	while(count_delete != 0)
	{
        for (int h=1; h < StringGrid1->RowCount; h++)
		{
			if(StringGrid1->Cells[1][h] == "...")
			{
				int k=h;
				if (k>0)
				{
					//��� �� ������� ��������
					//***
					for (int i=k+1; i<StringGrid1->RowCount; i++)
						for (int j=0; j<StringGrid1->ColCount; j++)
							if (j==0)
								StringGrid1->Cells[0][i]=IntToStr(i);
							else
							StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
					StringGrid1->RowCount--;
                    //***
                    count_delete--;
				}
			}
		}
    }
}
//---------------------------------------------------------------------------


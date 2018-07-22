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
	StringGrid1->Visible = true;
	StringGrid1->RowCount=1;
	StringGrid1->ColWidths[0]=30;
	StringGrid1->ColWidths[1]=150;
	StringGrid1->ColWidths[2]=100;
	StringGrid1->ColWidths[3]=100;
	StringGrid1->ColWidths[4]=100;
	StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Ф.И.О";
	StringGrid1->Cells[2][0]="Информатика";
	StringGrid1->Cells[3][0]="Философия";
	StringGrid1->Cells[4][0]="ПРограммирование";
	Button5Click(Sender);
	StringGrid1->FixedRows = 1;
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
	// Чтение из файла
	int myfile, row, col, lenStr;
	char *pszBuffer;
	if (OpenDialog1->Execute())
	{
		myfile = FileOpen(OpenDialog1->FileName, fmOpenRead);
		Form1->Button1Click(Sender);
		// Читаем из файла количество колонок и строк таблицы
		FileRead(myfile,&col,sizeof(StringGrid1->ColCount));
		FileRead(myfile,&row,sizeof(StringGrid1->RowCount));
		StringGrid1->ColCount=col;
		StringGrid1->RowCount=row;
		// теперь содержимое таблицы
		for (int i=0; i<col; i++)
		{
			for (int j=0; j<row; j++)
			{
				// Читаем длину записанной чтроки
				FileRead(myfile, &lenStr, sizeof(lenStr));
				//содаем буфер для чтения
				pszBuffer = new char[lenStr+1];
				// читаем саму строку
				FileRead(myfile,pszBuffer, lenStr);
				StringGrid1->Cells[i][j]=AnsiString(pszBuffer,lenStr);
				// удаляем буфер для чтения
				delete[] pszBuffer;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)//SAVE
{
	// Запись в файл
	if (SaveDialog1->Execute())
	{
		int iLength;
		int myfile=FileCreate(SaveDialog1->FileName);
		// Записываем в выходной файл количество колонок и строк таблицы
		FileWrite(myfile, (char*)&(StringGrid1->ColCount), sizeof(StringGrid1->ColCount));
		FileWrite(myfile, (char*)&(StringGrid1->RowCount), sizeof(StringGrid1->RowCount));
		// теперь содержимое таблицы
		for (int i=0;i<StringGrid1->ColCount;i++)
		{
			for (int j=0;j<StringGrid1->RowCount;j++)
			{
				// Записываем длину строки
				iLength = StringGrid1->Cells[i][j].Length();
				FileWrite(myfile, (char*)&iLength, sizeof(iLength));
				//Копируем текст ячейки во временную переменную
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
	int countStudents = 0;
	int sredRate = 0;
	//берём кол-во строк/столбоцов
	int col = StringGrid1->ColCount;
	int row = StringGrid1->RowCount;
	//инициализируем размер для матрицы str_cells
	const int str_cells_row = 5;
	const int str_cells_col = 8;
	//str_cells бдует хранить StringGrid1
	AnsiString str_cells[str_cells_row][str_cells_col];
	//Находим средний балл
	for (int i = 1; i < row; i++)
	{
		if(StringGrid1->Cells[1][i] != "")
		{
			int sred = 0;
      		sred += StrToInt(StringGrid1->Cells[2][i]);
      		sred += StrToInt(StringGrid1->Cells[3][i]);
      		sred += StrToInt(StringGrid1->Cells[4][i]);
      		sred /= 3;
      		sredRate += sred;
        }
	}
	sredRate /= row - 1;
	Label1->Caption = "Средняя оценка = " + IntToStr(sredRate);
	//Через цикл инициализируем str_cells
	for(int i = 1; i < row; i++)
	{
		if(StringGrid1->Cells[1][i] != "")
		{
      		int sred = 0;
      		sred += StrToInt(StringGrid1->Cells[2][i]);
      		sred += StrToInt(StringGrid1->Cells[3][i]);
      		sred += StrToInt(StringGrid1->Cells[4][i]);
      		sred /= 3;

      		if (sred >= sredRate)
      		{
      			countStudents++;
      			str_cells[1][countStudents] = StringGrid1->Cells[1][i];
      			str_cells[2][countStudents] = StringGrid1->Cells[2][i];
      			str_cells[3][countStudents] = StringGrid1->Cells[3][i];
      			str_cells[4][countStudents] = StringGrid1->Cells[4][i];
			}
		}
	}
	//сортируем
	for (int i = 1; i <= countStudents - 1; i++)
	{
		for (int j = i + 1; j <= countStudents; j++)
		{
			if(StringGrid1->Cells[1][i] != "")
			{
	      		int sred1 = 0;
	      		sred1 += StrToInt(StringGrid1->Cells[2][i]);
	      		sred1 += StrToInt(StringGrid1->Cells[3][i]);
	      		sred1 += StrToInt(StringGrid1->Cells[4][i]);
	      		sred1 /= 3;

	      		int sred2 = 0;
	      		sred2 += StrToInt(StringGrid1->Cells[2][j]);
	      		sred2 += StrToInt(StringGrid1->Cells[3][j]);
	      		sred2 += StrToInt(StringGrid1->Cells[4][j]);
	      		sred2 /= 3;

	      		if (sred1 < sred2)
	      		{
	      			for(int k = 1; k <= 4; k++)
	      			{
	      				AnsiString tmp = str_cells[k][i];
	      				str_cells[k][i] = str_cells[k][j];
	      				str_cells[k][j] = tmp;
	      			}
	      		}
			}
		}
	}
	//чистим
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			StringGrid1->Cells[j][i] = "";
	//выводим
	for (int i = 1; i <= countStudents; i++)
	{
		StringGrid1->Cells[1][i] = str_cells[1][i];
		StringGrid1->Cells[2][i] = str_cells[2][i];
		StringGrid1->Cells[3][i] = str_cells[3][i];
		StringGrid1->Cells[4][i] = str_cells[4][i];
	}
}
//--------------------------------------------------



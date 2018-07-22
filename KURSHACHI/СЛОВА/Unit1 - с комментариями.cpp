//---------------------------------------------------------------------------
//подключаем билиотеки
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "fstream"
#include "iostream"
#include "time.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace std;//подключаем имя пространств

TForm1 *Form1;//переменная нашего окна
Graphics::TBitmap *back = new Graphics::TBitmap();//изображения для фона

AnsiString words[10000];//массив слов 
AnsiString randomWord;//случайное слово с случайной перестановкой букв
AnsiString rigthWord;//правильное слово
AnsiString currectWord = "";//слово которое набирает пользователь

int countMove;//количество ходов
int score = 0;//очки
int posX1, posY1, posX2, posY2;//позиция отрисовки квадрата
int countWords = 0;//кол-во слов
int sizeFont = 70;//размер шрифта
int podskazka = 3;//кол-во подсказок
//---------------------------------------------------------------------------
//функция вызывается при открытии окна
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(NULL));//оптимизируем функцию  случайности
	back->LoadFromFile("back.bmp");//загружаем изображение фона
	loadWords();//вызываем функцию чтения слов с файла
}
//---------------------------------------------------------------------------
//функция для загрузка слов с файла в массив слов
void TForm1::loadWords()
{
	AnsiString text = "";//сюда загружаем текст с файла
	TFileStream *file = new TFileStream("words.txt",fmOpenReadWrite);//открываем поток чтения данных
	file->Seek(0,0);//ставим указатель в начало файла
	char *buffer;//создаем буффер
	if ((buffer = (char *) malloc(file->Size)) == NULL)//проверяем данные
		return;
	file->Read(buffer,file->Size);//считываем и помещаем буффер
	text = buffer;//помещаем буффер в текст
	text.SetLength(file->Size);//ставим размер текста
	//теперь будет разделять слова по отдельности и заносить в массив
	AnsiString word = "";//заносим слова
	int i = 1;//итератор для цикла
	while (i <= text.Length() && text[i] != '#')//пробегаемся по тексту пока не встреим символ # (конец текста)
	{
		while(text[i] != '\n' && i != text.Length())//пока символ не равен отступу
		{
			word += text[i];//добовяем этот символ в word
			i++;
		}
		word.Delete(word.Length(),1);//удаляем последний символ
		words[countWords] = word;//помещаем слово в массив
		word = "";//обнуляем 
		i++;
		countWords++;
	}
}
//---------------------------------------------------------------------------
//функция для случайной расстановки букв в слове
AnsiString TForm1::randomChars(AnsiString str)
{
	rigthWord = str;//копируем строчку в правильное слово
	for (int i = 1; i <= str.Length(); i++)
	{
		int index1 = rand() % str.Length() + 1;//берем 2 номера случайно
		int index2 = rand() % str.Length() + 1;
		char tmp = str[index1];//заменяем буквы местами мо номерам
		str[index1] = str[index2];
		str[index2] = tmp;
		//делаем так несколько раз
	}
	return str;//возращаем переделанное слово
}
//---------------------------------------------------------------------------
//функция для отрисовки панели с случайным словом randomWord
void TForm1::drawWord()
{
	Canvas->Font->Color = clBlue;//ставим синий цвет шрифту
	Canvas->Font->Size = sizeFont;//задаем размер шрифту
	Canvas->Pen->Width = 5;//ставим ширину ручки для отросвки квадратиков
	Canvas->Brush->Color=clGray;//делаем серый цвет для кисти
	Canvas->RoundRect(posX1 - 500, posY1 - 10, posX2+500, posY2+10, 10, 10);//рисуем задний серый фон
	Canvas->Brush->Color=clWhite;//ставим белый цвет
	Canvas->RoundRect(posX1 - 10, posY1 - 10, posX2+5, posY2+10, 10, 10);//рисуем белый фон

	int i;
	for (i = 0; i < randomWord.Length(); i++)//рисуем квадритики и буквы
	{
		int recX = i * sizeFont + posX1;//считаем координаты начала отрисовки 
		int recY = posY1;
		Canvas->Rectangle(recX + (i * 10), recY, recX + sizeFont + (i * 10), recY + sizeFont);//рисуем квадратик
		AnsiString charStr = randomWord[i+1];//добавляем символ в строчку
		Canvas->Brush->Style = bsClear;//ставим прозрачность
		Canvas->TextOutA(recX + (i * 10) + 10, recY - 30, charStr);//выводим символ(букву)
	}	
}
//---------------------------------------------------------------------------
//функция создает новое случайное слово для отгадывания
void TForm1::newWord()
{
	randomWord = randomChars(words[rand() % countWords]);//берем случайное слово из массива
	currectWord = "";//обнуляем вводимое слово
	countMove = randomWord.Length();//кол-во ходов равняется длине слова
	//высчитываем кординаты отрисовки панели с буква в зависимости от длинны слова
	posX1 = Form1->Width / 2 - (randomWord.Length() * (sizeFont + 10) / 2);
	posY1 = Form1->Height / 2 - sizeFont;
	posX2 = posX1 + randomWord.Length() * (sizeFont + 10);
	posY2 = posY1 + sizeFont;

	drawWord();//вызываем функцию отрисовки панели с буквами
}
//---------------------------------------------------------------------------
//функция для новой игры
void TForm1::newGame()
{
	newWord();//создаем нове случайное слово
	//обнуляем параметры
	score = 0;
	countMove = randomWord.Length();
	podskazka = 3;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//функция вызывается при подсказке
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (podskazka > 0)//если подсказок больше 0 
	{
		ShowMessage("СЛОВО: " + rigthWord);//показываем правильное слово
		if (podskazka > 0)
			podskazka--;//уменьшаем подсказки
    }
}
//---------------------------------------------------------------------------
//функция автоматически вызывается windows для отрисовки окна
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	drawWord();//рисуем панель с буквами

	Canvas->Draw(0,0, back);//рисуем фон с изображения
	Canvas->Brush->Color=clWhite;//ставим белый цвет
	Canvas->Rectangle(10,10,330,80);//рисуем прямоугольник куда пишем вводимое слово
	//обновляем текст в лейблах и кнопке
	Label1->Caption = "ХОДЫ: " + IntToStr(countMove);
	Label2->Caption = "ОЧКИ: " + IntToStr(score);
	Button1->Caption = "Подсказка (" + IntToStr(podskazka) + ")";
}
//---------------------------------------------------------------------------
//функция вызывается при нажатии кнопки мыши
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbLeft)//если нажата ЛКМ
		if (X >= posX1 && Y >= posY1 && X <= posX2 && Y <= posY2)//проверяем попал ли курсор в панель с буквами
		{
			int kletka = (X - posX1 - 10) / (sizeFont + 8) + 1;//высчитываем нажатой клетку 
			if (countMove > 0 && kletka != 0 && !(kletka > randomWord.Length()))//проверяем пределы
			{
				currectWord += randomWord[kletka];//увеличиваем вводимое слово на нажатую букву
				countMove--;//уменьшаем ходы
			}
		}
	if(Button == mbRight)//если нажали ПКМ
	{
		currectWord.Delete(currectWord.Length(),1);//удаляем послдению букву из вводимого слоа
		if (countMove < randomWord.Length())
			countMove++;//увеличивыаем ходы с проверкой
	}
	Label3->Caption = currectWord;//отрисовываем вводимой слово в лейбле
}
//---------------------------------------------------------------------------
//функция вызывается при нажатии на кнопку проверки
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (currectWord == rigthWord)//если вводимой слово равно правильному
	{
		ShowMessage("=) +" + IntToStr(rigthWord.Length()) + " ОЧКОВ");//показываме окно оповещения
		score += rigthWord.Length();//увеличиваем очки на размер слова
	}
	else//иначе наооборот
	{	
		ShowMessage("=( -" + IntToStr(rigthWord.Length()) + " ОЧКОВ");
		score -= rigthWord.Length();
	}
	newWord();//делаем новое слово
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)//при нажатии на кнопку новый игры
{
	newGame();//создаем новую игру
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)//при нажатие на новую игру в меню
{
	newGame();//создаем новую игру
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)//при нажатие на справку в меню
{
	ShowMessage("Курсовая работа\nБИ1602\nВиктория Дёмина");//окно оповещения
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)//при нажатие на управления в меню
{
	ShowMessage("ЛКМ - поставить букву \n ПКМ - убрать букву");//окно оповещения
}
//---------------------------------------------------------------------------


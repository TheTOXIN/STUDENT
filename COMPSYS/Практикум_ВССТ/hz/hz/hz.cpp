#include "stdafx.h"
#include <windows.h> 
#include <fstream> 
#include <iostream> 
#include <time.h>  
#include <cstring>
using namespace std; //
#pragma comment(lib,"urlmon.lib") 
#pragma comment(lib,"winmm.lib")  
int Size(char *name)
{
ifstream file;
file.open(name,ios::binary);
int count=0;
char ch;
while(!file.eof())
{
file.get(ch);
count++;
}
file.close();
return count;
}
int main()
{
int i=1;
char path[256];
char filename[255];
char extension[5];
char name[50];
DWORD start, finish;
//
SetConsoleTitle("File Downloader by Bez and Velichko");
//
cout<<"Vvedite imya, pod kotorym hotite sohranit fail: ";
cin>>name;
cout<<"Vvedite rasshirenie (naprimer rar/exe/dll): ";
cin>>extension;
//
ofstream out("Links.txt", ios::out | ios::binary);
  char str[256];
  cout<<"vvedite URL dlya zakachki: ";
  cin>>str;
  out.write(str, strlen(str));

  out.close();




FILE *ptr;
ptr = fopen ("Links.txt","r");
if(ptr != NULL){
while(!feof(ptr)){
fgets(path,256,ptr);
itoa(i,filename,10);
strcat(filename,name);
strcat(filename,".");
strcat(filename,extension);
cout<<"\nZakachka iz: "<<path<<"\n";
start = timeGetTime();
URLDownloadToFile(0,path,filename,0,0);
finish = timeGetTime();
cout<<"\tZakachka "<<i<<" zavershena\n\tRazmer faila: "<<(Size(filename)/1024)<<" kb \n\tVremeni zatracheno: "<<(finish-start)/1000<<" sekund\n";
if(((finish-start)/1000)>0)
cout<<"\tSrednyaya skorost' zakachki: "<<((Size(filename)/1024)/((finish-start)/1000))<<" kb/s\n";
i++;
}
if(i==1)
{
cout<<"Ssylki ne naideny v faile Links.txt\n";
system("PAUSE");
return 1;
}
cout<<"Zakachka zavershena\n";
fclose(ptr);
system("PAUSE");
return 1;
}
else{
cout<<"Nevozmozhno naiti Links.txt\n";
system("PAUSE");
return 1;
}
cout<<"Zakachka zavershena\n";
system("PAUSE");
}

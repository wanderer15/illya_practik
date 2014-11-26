# include <iostream>
# include <fstream>
# include <conio.h>
# include <stdio.h>
# include <windows.h>

using namespace std;

void f_in(void);
double skan_pluss (int );
double skan_minus (int );
void pingvin (void );
void meny (void);
void analiz (void);

char file_name[150], mas[1000];
int graf = 1,t=0,stop=-15,numbers=1;
	
int main ()
{
setlocale (0,"rus");
	meny();
	
	getch ();
	return 0;
}

void f_in(void)
{	
	fstream f (file_name, ios::in);
	if (!f.is_open())
	{
	system ("cls");
	cout<<"\t\t\t Файла не iснує...";
	Sleep (1500);
	t=0;
	meny ();
	}
	
	for(;(!f.eof());)
	{
	f.getline(mas,1000);
	pingvin ();
	}
	
	f.close();
}

void meny (void)
{
	int key;
 	system ("cls");
 	for (;;)
 	{
 	if (t==0)
	{
	cout<<"Вкажiть iм*я файла для роботи : ";
	cin>>file_name;
	t++;
	}
	system ("cls");
	cout<<"1. Аналiзувати файл"<<endl<<"0. Вихiд"<<endl<<"<<";
	cin>>key;
	switch (key)
	{
		case 1 : { system ("cls");	 analiz ();	getch (); break;} 
		case 0 : { exit (1); break;} 
	}
	}
}

void analiz (void)
{
	int key;
	system ("cls");
	cout<<"1. Аналiз всього файлу"<<endl<<"2. Аналзi 12-ти елементiв."<<endl<<"0. Назад"<<endl<<"<<";
	cin>>key;
	switch (key)
	{
		case 1 : { system ("cls"); stop=-15; numbers =0; f_in();	getch (); break;} 
		case 2 : { system ("cls"); stop=0;	numbers=0; f_in();	getch (); break;}
	}
}

void pingvin (void)
{
	int num;
	for (int i=0,temp=graf;i<strlen(mas);i++)
	{
	
	if (num==0)
	{
	numbers++;	
	}
	
	if (stop==0)	
	if (numbers==13)
	{
		getch ();
		meny ();
	}
	if (num==0)
	{
	cout<<numbers<<" ";
	}
	
	if ((mas[i]>=65)&&(mas[i]<=90)||(mas[i]>=97)&&(mas[i]<=122))
	{
		
	cout<<mas[i];
	graf++;
	num++;

	}
	else 
	if ((mas[i]==' ')||(mas[i]==13))
	{
	cout<<endl;
	num=0;
	}
	
	
}
}

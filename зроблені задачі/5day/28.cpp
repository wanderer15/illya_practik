# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>

using namespace std;

void sort (void);
void c_in_data (void);
void printer (void);

struct data
{
	char name [50];
	int speed;
} data_key [25];

int main ()
{
	setlocale (0,"rus");
	int g=0;
	for (;;)
{
	cout<<"1. Внести записи"<<endl<<"2. Вивести на екран"<<endl<<"3. Вiдсортувати "<<endl<<"0. Exit"<<endl<<"<<";
	cin>>g;
	switch (g)
	{	case 0 : { cout<<endl<<"\t\tExit..."<<endl; exit (1); break;}
		case 1 : { c_in_data (); break; }
		case 2 : { printer (); getch (); break; }
		case 3 : { sort (); getch (); break; }
	}
	system ("cls");
}
	getch ();
	return 0;
}

void c_in_data (void)
{
	srand (time (NULL));
	for (int i=0; i<20;i++)
	{/*
		system ("cls");
		cout<<"\t Моделька № "<<i+1<<endl;
		cout<<"Вкажiть назву = ";
		cin>>data_key[i].name;
		cout<<"Вкажiть швидкiсть = ";
		cin>>data_key[i].speed;*/
		data_key[i].name[0]='i'+i;
		data_key[i].speed=rand ()%200;
		
	}
		cout<<"Записи внесені...";
}

void printer (void)
{
	system ("cls");
	for (int i=0; i<20;i++)
	{
		cout<<endl<<"Моделька "<<data_key[i].name<<"\t Швидкiсть "<<data_key[i].speed<<endl;
	}

}


void sort (void)
{
	int speed_user_key,g=20;
	cout<<"Вкажiть швидкiсть для сортування : ";
	cin>>speed_user_key;
		if (speed_user_key<0)
		{cout<<"Швидкiсть не можу бути мiнусова!!!";
		getch ();
		 sort ();
		}
		for (int i=0;i<20;i++)
		{
                  if (data_key[i].speed>speed_user_key) 
				  {
				  cout<<endl<<"\t Моделька "<<data_key[i].name<<"\t Швидкiсть "<<data_key[i].speed<<" км/ч"<<endl; g--;
				  }
		}
		if (g==20)
		cout<<endl<<"Записiв не знайдено з заданим значенням..."<<endl;
		cout<<endl<<"Сортування завершено..."<<endl;
}




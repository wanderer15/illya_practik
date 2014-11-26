# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>

using namespace std;

void printer (int );
void v_vod (int );
void sort (int );
int summa (int );

struct data
{
	char name [50];
	int predmet1;
	int predmet2;
	int predmet3;
	int predmet4;
} data_key [500];

int main ()
{
	setlocale (0,"rus");
	int g=0,max=3,test;
				for (;;)
			{
				cout<<"1. Внести записи"<<endl<<"2. Вивести на екран"<<endl<<"3. Вiдсортувати "<<endl<<"4. Options"<<endl<<"0. Exit"<<endl<<"<<";
				cin>>g;
				switch (g)
					{	case 0 : { cout<<endl<<"\t\tExit..."<<endl; exit (1); break;}
						case 1 : { v_vod (max); break; }
						case 2 : { printer (max); getch (); break; }
						case 3 : { sort (max); getch (); break; }
						case 4 : {cout<<"Задайте максимальне значення, (або при значеннi 0"<<endl<<"буде задано стандартне 22 записа)= "; cin>>test;
					if ((test!=0)&&(test>0))
					{
					max=test;
					cout<<"Значення змiнено..."<<endl; getch ();}
					else 
					{
					cout<<"Значення не змiнено..."<<endl;
					getch ();
					} break; 
					}
					}
				
				system ("cls");
			}
	getch ();
	return 0;
}

void v_vod (int max) 
{
	for (int i=0;i<max;)
	{
	system ("cls");
	srand (time(NULL));
			cout<<i+1<<" Name - ";
		cin>>data_key[i].name;
			cout<<"Ball 1 - ";
		cin>>data_key[i].predmet1;
			cout<<"Ball 2 - ";
		cin>>data_key[i].predmet2;
			cout<<"Ball 3 - ";
		cin>>data_key[i].predmet3;
			cout<<"Ball 4 - ";
		cin>>data_key[i].predmet4;
	
	if (!((data_key[i].predmet1>-1)&&(data_key[i].predmet2>-1)&&(data_key[i].predmet3>-1)&&(data_key[i].predmet4>-1)))
	{
	cout<<"Fatal system error!!!... (Данi введенi не коректно!.)";
	getch ();
	}
	else { i++; }
	/*data_key[i].name[0]=i+97;
	data_key[i].predmet1=rand()%100;
	srand (time(NULL));
	data_key[i].predmet2=rand()%100;
	srand (time(NULL));
	data_key[i].predmet3=rand()%100;
	srand (time(NULL));
	data_key[i].predmet4=rand()%100;*/
	
	}
}

void printer (int max)
{
system ("cls");
	for (int i=0;i<max;i++)
	{
		cout<<"\t\tStudent - "<<i+1<<endl;
		cout<<"\tName - "<<data_key[i].name<<endl;
		cout<<"\tSubject 1 - "<<data_key[i].predmet1<<endl;
		cout<<"\tSubject 2 - "<<data_key[i].predmet2<<endl;
		cout<<"\tSubject 3 - "<<data_key[i].predmet3<<endl;
		cout<<"\tSubject 4 - "<<data_key[i].predmet4<<endl;
		cout<<endl;
	}
}

void sort (int max)
{
int summ= summa (0),p=-1;	
	for (int i=0; i<max;i++)
	{
		if (summa (i)>summ)
			{
				summ=summa (i);
				p=i;
			}
	}
    if (p!=-1)		
cout<<"Total points "<<summ<<" Name - "<<data_key[p].name<<endl;	
		for (int i=0; i<max;i++)
		{
			if ((summa (i)==summ)&&(p!=i))
			{
				cout<<"Total points "<<summa(i)<<" Name - "<<data_key[i].name<<endl;
			}
		}		
	}

int summa (int i)
{
	return (data_key[i].predmet1+data_key[i].predmet1+data_key[i].predmet1+data_key[i].predmet1);
}




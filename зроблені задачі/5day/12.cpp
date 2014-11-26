# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>

using namespace std;

void c_in_data (void);
void printer (void);
void sort (void);
void pervoe_i_vtoroe_mesto (void);

struct data
{
	int numbers;
	char name [50];
	int chisla;
} data_key [25];

int main ()
{
	setlocale (0,"rus");
	int g=0;
	for (;;)
{
	cout<<"1. Внести записи"<<endl<<"2. Вивести на екран"<<endl<<"3. Сортування "<<endl<<"4. Показати команди що зайняли 1 i 2 мiсце "<<endl<<"0. Exit"<<endl<<"<<";
	cin>>g;
	switch (g)
	{	case 0 : { cout<<endl<<"\t\tExit..."<<endl; exit (1); break;}
		case 1 : { c_in_data (); break; }
		case 2 : { printer (); getch (); break; }
		case 3 : { sort (); getch (); break; }
		case 4 : { pervoe_i_vtoroe_mesto (); getch (); break;
		}
	}
	system ("cls");
}
	getch ();
	return 0;
}

void c_in_data (void)
{
	srand (time (NULL));
	for (int i=0; i<25;i++)
	{/*
		system ("cls");
		cout<<"\t Команда № "<<i+1<<endl;
		cout<<"Вкажiть назву = ";
		cin>>data_key[i].name;
		cout<<"Вкажiть рахунок = ";
		cin>>data_key[i].chisla;*/
		data_key[i].numbers=i+1;
		data_key[i].name[0]='i'+i;
		data_key[i].chisla=rand ()%10+1;
		
	}

}

void printer (void)
{
	system ("cls");
	for (int i=0; i<25;i++)
	{
		cout<<"\t Команда № "<<data_key[i].numbers<<endl<<"\t Назва"<<"\t Місце"<<endl;
		cout<<"\t"<<data_key[i].name<<"\t"<<data_key[i].chisla<<endl<<endl;
	}

}


void sort (void)
{
	for (int j=0;j<25-1;j++)
	{
		for (int i=0;i<25-1;i++)
		{
                  if (data_key[i].chisla>data_key[i+1].chisla) 
				  {
				  swap(data_key[i].chisla, data_key[i+1].chisla);
				  swap(data_key[i].name, data_key[i+1].name);
				  swap(data_key[i].numbers, data_key[i+1].numbers);
					}	  
		}
}
		cout<<"Сортування завершено..."<<endl;
}

void pervoe_i_vtoroe_mesto (void)
{
	int pervoe_mesto=data_key[0].chisla, vtoroe_mesto=data_key[1].chisla;

	if (pervoe_mesto>vtoroe_mesto)
	{
	swap(pervoe_mesto,vtoroe_mesto);
	}

	int num_1, num_2;

	for (int i=0;i<25;i++)
		 {
		 	if (data_key[i].chisla<pervoe_mesto)
		 	{pervoe_mesto=data_key[i].chisla;
		 	num_1=i;}
		 	if ((data_key[i].chisla<vtoroe_mesto)&&(data_key[i].chisla>pervoe_mesto))
		 	{vtoroe_mesto=data_key[i].chisla;
		 	num_2 =i;}
		 }
	cout<<"\t Перше мiсце займає "<<data_key[num_1].name<<" Посiла мiсце "<<data_key[num_1].chisla<<endl;
	cout<<"\t Друге мiсце займає "<<data_key[num_2].name<<" Посiла мiсце "<<data_key[num_2].chisla;
}


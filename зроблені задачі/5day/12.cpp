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
	cout<<"1. ������ ������"<<endl<<"2. ������� �� �����"<<endl<<"3. ���������� "<<endl<<"4. �������� ������� �� ������� 1 i 2 �i��� "<<endl<<"0. Exit"<<endl<<"<<";
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
		cout<<"\t ������� � "<<i+1<<endl;
		cout<<"����i�� ����� = ";
		cin>>data_key[i].name;
		cout<<"����i�� ������� = ";
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
		cout<<"\t ������� � "<<data_key[i].numbers<<endl<<"\t �����"<<"\t ̳���"<<endl;
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
		cout<<"���������� ���������..."<<endl;
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
	cout<<"\t ����� �i��� ����� "<<data_key[num_1].name<<" ���i�� �i��� "<<data_key[num_1].chisla<<endl;
	cout<<"\t ����� �i��� ����� "<<data_key[num_2].name<<" ���i�� �i��� "<<data_key[num_2].chisla;
}


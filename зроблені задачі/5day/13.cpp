# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>

using namespace std;

void c_in (void);
void become (int ,int );
void printer (void);
void filters (void);
void options (void);

int person=20;

struct data
{
	char name [50];
	float height;
	char  become[2];
} data_person [50];

int main ()
	{
		int key;
		for (;;)
		{
		
		system ("cls");
		cout<<"1. New record"<<endl<<"2. Show entries"<<endl<<"3. Filters"<<endl<<"4. Options"<<endl<<"0. Exit"<<endl<<"<<";
		cin>>key;
			switch (key)
			{
				case 1 : { c_in (); break;}
				case 2 : { printer (); break;}
				case 3 : { filters (); break;}
				case 4 : { options (); break;}
				case 0 : { cout<<"Exit..."; Sleep(500);return 0;}
			}
		}
}

void c_in (void)
{
	for (int i=0;i<person;)
	{
		system ("cls");
		cout<<"\tRecord "<<i+1<<"/"<<person<<endl<<" Name - ";
		cin>>data_person[i].name;
		cout<<" Height (1.6/160) - ";
		cin>> data_person[i].height;
		cout<<" Become (m/f) - ";
		cin>>data_person[i].become;
			if ((data_person[i].height<3)&&(data_person[i].height>0)&&((data_person[i].become[0]=='m')||(data_person[i].become[0]=='f')))
			{ i++; }
			else
			if ((data_person[i].height>=100)&&(data_person[i].height<=250)&&((data_person[i].become[0]=='m')||(data_person[i].become[0]=='f')))
			{
				data_person[i].height=data_person[i].height/100;
				i++;
			}
			else
			{
				cout<<endl<<"Complementary information entered incorrectly !.."<<endl;
				getch ();
			}
	}
	Sleep(500);
}

void printer (void)
{
	system ("cls");

	for (int i=0; i<person;i++)
	{
		if (data_person[i].become[0]=='m') 
		{
				cout<<" Name - "<<data_person[i].name<<" Height - "<<data_person[i].height<<" Become - "<<"male"<<endl;
		}
	}	
	cout<<endl<<endl;
	
	for (int i=0; i<person;i++)
	{
		if (data_person[i].become[0]=='f') 
		{
				cout<<" Name - "<<data_person[i].name<<" Height - "<<data_person[i].height<<" Become - "<<"female"<<endl;
		}
	}	
	getch ();
}


void filters (void)
{
	int m_max, f_max, m_point=-1, f_point=-1 ;
	
	for (int i=0; i<person;i++)
	{
		if (data_person[i].become[0]=='m') 
		{
				m_max=i;
				m_point=i;
		}
		
		if (data_person[i].become[0]=='f') 
		{
				f_max=i;
				f_point=i;
		}	
	}
	
	
	for (int i=0; i<person;i++)
	{
		if (data_person[i].become[0]=='m') 
		{
			if (m_max<data_person[i].height)
				{
				m_max=data_person[i].height;
				m_point=i;
				}
		}
	}	
	
	for (int i=0; i<person;i++)
	{
		if (data_person[i].become[0]=='f') 
		{
			if (f_max<data_person[i].height)
				{
				f_max=data_person[i].height;
				f_point=i;
				}
		}
	}
	cout<<endl<<endl<<"\t\tMax. height "<<endl;
	if (m_point!=-1)
	{cout<<" Name - "<<data_person[m_point].name<<" Height - "<<data_person[m_point].height<<" Become - "<<"male"<<endl;}
	
	if (f_point!=-1)
	{cout<<" Name - "<<data_person[f_point].name<<" Height - "<<data_person[f_point].height<<" Become - "<<"female"<<endl;}
	
	if ((m_point==-1)&&(f_point==-1))
	cout<<"\tRecords not found ...";
	getch ();
}

void options (void)
{
	int i,test;
	system ("cls");
	cout<<"1. Change the number of persons."<<endl<<"0. Close"<<endl;
	cin>>i;
	switch (i)
	{
		case 1 : { 
		cout<<"Set the number of persons : ";
		cin>>test;
		if ((test>0)&&(test<50))
		{
		person=test;
		cout<<"The operation was successful :)";
		}
		else 
		cout<<"Success apparently not successful :(";
		Sleep(500);
		break;}
	}
}


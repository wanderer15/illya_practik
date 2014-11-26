# include <iostream>
# include <fstream>
# include <conio.h>
# include <stdio.h>
# include <windows.h>
//# include <math.h>

using namespace std;

void f_in(void);
double skan_pluss (int );
double skan_minus (int );
int pingvin (void );
void meny (void);

char file_name[150], mas[1000];
int graf = 1,t=0;
	
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
	
	for(;!f.eof();)
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
		case 1 : { system ("cls");	f_in();	getch (); break;} 
		case 0 : { exit (1); break;} 
	}
	
	
	
	
	
	}
}

int pingvin (void)
{
	for (int i=0,temp=graf;i<strlen(mas);i++)
	{
	
	if (mas[i]=='+')
	{
	cout<<graf<<". "<<skan_minus (i)<<"+"<<skan_pluss (i)<<"="<<skan_minus (i)+skan_pluss (i)<<endl;
	graf++;
	}
	else if (mas[i]=='*')
	{
	cout<<graf<<". "<<skan_minus (i)<<"*"<<skan_pluss (i)<<"="<<skan_minus (i)*skan_pluss (i)<<endl;
	graf++;
	}
	else if (mas[i]=='-')
	{
	cout<<graf<<". "<<skan_minus (i)<<"-"<<skan_pluss (i)<<"="<<skan_minus (i)-skan_pluss (i)<<endl;
	graf++;
	}
	else if (mas[i]=='/')
	{
	cout<<graf<<". "<<skan_minus (i)<<"/"<<skan_pluss (i)<<"=";
	graf++;
	if (skan_pluss (i)!=0)
	cout<<skan_minus (i)/skan_pluss (i)<<endl;
	else
	cout<<"Error"<<endl;
	}
	
	}

}


double skan_pluss (int i)
{
	double summ=0;
	for (int e=i+1,t=1,g=0;  ;e++)
	{
	if ((48<=mas[e])&&(57>=mas[e]))
		{
		summ=summ*t+(mas[e]-48);
		t=10;
		}
	else
	return (summ);
	}		
}




double skan_minus (int i)
{
	int post=i;
	for (int e=i-1,t=0; t!=1 ;e--)
	{
	 if (((48>mas[e])||(57<mas[e])))
		{
		post=e;
		t++;
		}
	}

	double summ=0;
	for (int e=post+1,t=1,g=0;  ;e++)
	{
	if ((48<=mas[e])&&(57>=mas[e]))
	{
	summ=summ*t+(mas[e]-48);
	t=10;
	}
	else
	return (summ);
	}		
}


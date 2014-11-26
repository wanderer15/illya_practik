# include <iostream>
# include <conio.h>
# include <fstream>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>

using namespace std;

char  f_format[4]=".md";
int max_m=150, telnet=1;

void rand_file (char*);
void file_skan (char*);
int test_dill (char );


int main ()
{
	srand (time(NULL));
	setlocale (0,"rus");
	char f_name[150];
	char *file_name1=new char[(strlen(f_name))];
	int key,i=0,test;
	
	
	
	for (;;)
	{
	system("cls");
	if (i==0)
	{cout<<"Вкажiть iм*я файла "<<endl<<"<<";
	cin>>f_name;
	file_name1=f_name;
	strcat(file_name1,f_format); i++;}	
	system("cls");
	cout<<"1. Записати файл"<<endl<<"2. Проаналiзувати файл"<<endl<<"3. Змiнити кiлькiсть цифр"<<endl<<"4. Змiнити iм*я файлу"<<endl<<"0. Вихiд"<<endl;
	cin>>key;
		switch(key)
		{
		case 1 : {rand_file (file_name1); break;}
		case 2 : {file_skan (file_name1); break;}
		case 3 : {cout<<"Скiльки цифер потрiбно  = "; cin>>test; if (test>0) max_m=test; else {cout<<" Значення задано невiрно...   ";} Sleep (500); break;}
		case 4 : {i=0;int main (); break;}
		case 0 : { exit (1);  break;}
		}	
	}
	getch ();
	return 0;
}

void rand_file (char *f_name)
{
	char *file_name=new char[(strlen(f_name))];
	file_name=f_name;
	ofstream file;
	file.open (file_name, ios::out);
	for (int i=0;i<max_m ; i++)
	{
		file<<rand()%99<<" ";
	}

	file.close ();
}


void file_skan (char *file_name)
{
cout<<endl<<endl;


char xlam [10000];	
ifstream file;
file.open (file_name, ios::in);	
if (!file.is_open())
{
	cout<<endl<<"\tФайл неможливо вiдкрити... :("<<endl; 
	Sleep (500);
	main ();
}
file.getline(xlam,10000);

char *mas=new char[(strlen(xlam))];
	mas=xlam;
	for (int i = 0; i<strlen(xlam);i++)
	{
		cout<<mas[i];
	}
cout<<endl;
int symm=0;
for (int i=0; i <strlen(xlam);i++ )
{
	if ((mas[i]!=' ')&&(mas[i]!='\0'))
	{
		if ((test_dill (mas[i])==1)&&(test_dill (mas[i+1])))
		{
			symm++;
			if (telnet==1)
			cout<<symm<<" - "<<mas[i]<<mas[i+1]<<endl;
		}
	}
	
}
cout<<endl<<"Сума = "<<symm<<endl;
getch ();
}

int test_dill (char i)
{
	int a=(i-48)%2;
	return (a);
}

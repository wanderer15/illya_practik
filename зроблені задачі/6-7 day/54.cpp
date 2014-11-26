# include <iostream>
# include <conio.h>
# include <windows.h>
# include <stdio.h>
# include <fstream>
# include <string.h>
# include <stdlib.h>
# include <time.h>

using namespace std;

char file_name[50]="dima";
char temp_bufer[1000];
int stop=100, pozition=-1,naems=0;

	struct data
	{
		int 	chisla;	
	} Data[1000];
	
	
char new_file (void);
void open_file (void);
int analiz_int (void);
char share_struct (void);
void rename_file (void);
void c_cilkist (void);
void options (void);
int test (int );
	
int main ()
{
	setlocale (0, "rus");
	int key;
	if (naems==0)
	rename_file();
	naems++;
	for (;;)
	{
	system ("cls");
	cout<<"1. Створити новий файл"<<endl<<"2. Зчитати з файла у структуру"<<endl<<"3. Розгрупувати структуру у файли"<<endl<<"4. Налаштування"<<endl<<"0. Вихiд"<<endl;
	cin>>key;
	switch (key)
	{ 
	case 1 : { system ("cls"); new_file (); break;}
	case 2 : { system ("cls"); open_file (); Sleep(1500); break;}
	case 3 : { system ("cls"); share_struct (); getch (); break;}
	case 4 : { system ("cls"); options();  break;}
	case 0 : { exit (1); break;}
 	}
 	}
	getch ();
	return 0;
}

char new_file (void)
{
	ofstream file;
	char format[4]=".ua";
	char * temp_name = new char  [strlen(file_name)+strlen(format)];
	strcpy (temp_name,file_name);
	strcat(temp_name,format);
	file.open(temp_name, ios::out);
	for (int i=0;i<stop;i++)
	{
		file<<rand()%99+1<<" ";
	}
	cout<<"Файл збережено :)"<<endl<<temp_name;
	Sleep (1500);
}

void open_file (void)
{
	ifstream file_i;
	
	char format[4]=".ua";
	char * temp_name = new char  [strlen(file_name)+strlen(format)];
	strcpy (temp_name,file_name);
	strcat(temp_name,format);

	file_i.open(temp_name, ios::in);
	
	if (!file_i.is_open())
	{
	cout<<"Файл не знайдено...";
	Sleep (1500);
	main ();
	}

	while (!file_i.eof())
	{
	file_i.getline(temp_bufer,500);
	pozition++;
	analiz_int ();
	}
	cout<<"Файл вiдкрито... ";
}


int analiz_int (void)
{
int suma=0,start=0;
int test;
for (int i=strlen(temp_bufer)-2,p=1;i>=0;i--)
{
	if (temp_bufer[i]!=' ')
	{
	test=temp_bufer[i];
	suma+=(temp_bufer[i]-48)*p;	
	p*=10;
	}
	else 
	{
//	cout<<suma<<endl;
	Data[pozition].chisla=suma;
	pozition++;
	suma=0;
	p=1;
	}
}
Data[pozition].chisla=suma;
}

char share_struct (void)
{
	char f1ormat[7]="1.save";
	char * t1emp_name = new char  [strlen(file_name)+strlen(f1ormat)];
	strcpy (t1emp_name,file_name);
	strcat(t1emp_name,f1ormat);
	ofstream f1ile;
	f1ile.open(t1emp_name, ios::out);	
	
	char format[7]="0.save";
	char * temp_name = new char  [strlen(file_name)+strlen(format)];
	strcpy (temp_name,file_name);
	strcat(temp_name,format);
	
	ofstream file;
	file.open(temp_name, ios::out);
	
	for (int i=pozition;i>=0;i--)
	{
		
	if (test (i)!=0)
	 f1ile<<Data[i].chisla<<" ";
	else
	 file<<Data[i].chisla<<" ";
		
	}
	f1ile.close ();
	file.close();
	system ("cls");
	cout<<"\tФайли успiшно створенi 0 - (temp_name) та 1 - (t1emp_name)"<<endl;
	Sleep (1500);
}

int test (int i)
{
	return (Data[i].chisla%2);
}

void options (void)
{
	int key;
	for (;;)
	{
	system ("cls");
	cout<<"1. Змiнити назву файла"<<endl<<"2. Змiнити кiлькiсть записiв"<<endl<<"0. Назад"<<endl;
	cin>>key;
	switch (key)
	{
	case 1 : { rename_file (); break;}
	case 2 : { c_cilkist (); break;}
	case 0 : { main (); break;}
 	}
 	}
}

void rename_file (void)
{
	cout<<"Вкажiть iм*я для файла : ";
	cin>>file_name;
}

void c_cilkist (void)
{
	int test;
	cout<<"Вкажiть кiлькiсть = ";
	cin>>test;
	if ((test>0)&&(test<100))
	stop=test;
}

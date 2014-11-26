# include <iostream>
# include <conio.h>
# include <windows.h>
# include <stdio.h>
# include <fstream>
# include <string.h>

using namespace std;

char file_name[50]="dima";
char temp_bufer[500];
int stop=3, pozition=-1,naems=0;

	struct data
	{
		char	name [50];
		int 	naselenia;	
	} Data[150];
	
void vvod_test (void);
char new_file (void);
void open_file (void);
char analiz (void);
int analiz_int (void);
void share_struct (void);
void share_struct_persent (void);
char save_file_persent (void);
void rename_file (void);
void c_cilkist (void);
void options (void);
	
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
	cout<<"1. Створити новий файл"<<endl<<"2. Вiдкрити файл"<<endl<<"3. Перегляд структури"<<endl<<"4. Перегляд структури + 5%"<<endl<<"5. Зберегти як результат виконання (+ 5%)"<<endl<<"6. Налаштування"<<endl<<"0. Вихiд"<<endl;
	cin>>key;
	switch (key)
	{
	case 1 : { system ("cls"); vvod_test (); new_file (); break;}
	case 2 : { system ("cls"); open_file (); cout<<"Файл вiдкрито... "; Sleep(1500); break;}
	case 3 : { system ("cls"); share_struct (); getch (); break;}
	case 4 : { system ("cls"); share_struct_persent (); getch (); break;}
	case 5 : { system ("cls"); save_file_persent (); break;}
	case 6 : { system ("cls"); options();  break;}
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
		file<<"*"<<Data[i].name<<"#"<<Data[i].naselenia<<endl;
	}
	cout<<"Файл збережено :)"<<endl<<temp_name;
	Sleep (1500);
}

void vvod_test (void)
{
	for (int i=0,ge=0, error=0;i<stop;)
	{
		system ("cls");
		error=0;
		cout<<"\t\t"<<i+1<<"/"<<stop<<endl;
		cout<<"Назва : ";
		//if (ge>=1)
		cin.get();
		gets(Data[i].name);
		ge++;
		for (int test=0;test<50;test++)
		{
			if ((Data[i].name[test]==35)||(Data[i].name[test]==42))
			error++;
		}
		if (error==0)
			for (int next = 0; next<1;)
			{
			cout<<"Чисельнiсть = ";
			cin>>Data[i].naselenia;
			if (Data[i].naselenia>0)
			next++;
			}
		
		if (error==0)
		i++;
	}
	
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
	analiz ();
	analiz_int ();
	}

}

char analiz (void)
{
	char * name_analiz = new char [strlen (temp_bufer)];
	for (int i=1,t=0;i<strlen (temp_bufer);i++)
	{
		if ((temp_bufer[i]!=35))
		{
		Data[pozition].name[t]=temp_bufer[i];
		t++;
		}
		else 
		i=strlen (temp_bufer);
	}
}

int analiz_int (void)
{
	int suma=0,start=0;
for (int i=0;i<strlen (temp_bufer);i++)
{
	if ((temp_bufer[i]==35))
		{
		start=i;
		}	
}

int test;
for (int i=strlen(temp_bufer)-1,p=1;i>=start+1;i--)
{
	test=temp_bufer[i];
	suma+=(temp_bufer[i]-48)*p;	
	p*=10;
}
Data[pozition].naselenia=suma;
}

void share_struct (void)
{
	cout<<"\t\t\t Мiсто"<<"\t\tЧисельнiсть : "<<endl<<endl;
	for (int i=0;i<pozition;i++)
	{
		cout<<"\t\t\t "<<Data[i].name<<"\t - \t  "<<Data[i].naselenia<<endl;
	}
}

void share_struct_persent (void)
{
	cout<<"\t\t\t Мiсто"<<"\t\tЧисельнiсть + 5% : "<<endl<<endl;
	for (int i=0;i<pozition;i++)
	{
		cout<<"\t\t\t "<<Data[i].name<<"\t - \t  "<<Data[i].naselenia+((Data[i].naselenia/100)*5)<<endl;
	}
}

char save_file_persent (void)
{
	if (NULL==Data[0].naselenia)
	{
	system ("cls");
	cout<<"\t\tПорожнiй файл не буде збережений..."<<endl;	
	Sleep (1500);
	main ();
	}
	char format[6]=".save";
	char * temp_name = new char  [strlen(file_name)+strlen(format)];
	strcpy (temp_name,file_name);
	strcat(temp_name,format);
	
	ofstream file;
	file.open(temp_name, ios::out);
	file<<"\t\t\t Мiсто"<<"\t\tЧисельнiсть + 5% : "<<endl<<endl;
	for (int i=0;i<stop-1;i++)
	{
		
		file<<"\t\t\t "<<Data[i].name<<"\t - \t  "<<Data[i].naselenia+((Data[i].naselenia/100)*5)<<endl;
	}
	cout<<"Файл успiшно збережено :)"<<endl<<temp_name;
	Sleep (1500);
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


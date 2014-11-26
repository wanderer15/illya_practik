# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <fstream.h>
# include <time.h>
# include <Windows.h>

using namespace std;

void printer ( );
void v_vod ( );
void sort ( );
double summa (int );
void optiom_meny (void);
void meny_vvoda (void);
void v_vod_summ (void);
double procent (int );
void granichi (void);
void vvod_data_add (void);
void add_list (void);
void file_printer (void);

int max_b=5, min_b=0, persone=2, predmets=3, b_persone;
double X_max=85 , X_min=65 ,V_max=100 , V_min=85 ;
char file_name[100]="test", format[5]=".dat";

struct data
{
	char name [50];
	int predmet[50];
	double summ;
} data_key [500];


int main ()
{
	setlocale (0,"rus");
	int g;
				for (;;)
			{
				cout<<"1. Внести запис"<<endl<<"2. Вивести на екран"<<endl<<"3. Вiдсортувати "<<endl<<"4. Зберегти у файл"<<endl<<"5. Налаштування"<<endl<<"0. Вихiд"<<endl<<endl;
				cout<<"\tЛог: "<<endl<<"Персон - "<<persone<<endl<<"Кiлькiсть предметiв - "<<predmets<<endl<<"Максимальний та мiнiмальний допустимий бал - "<<max_b<<"/"<<min_b<<endl;
                cout<<"Дiапазон сортування (хорошисти) - "<<X_min<<"/"<<X_max<<endl;
                cout<<"Дiапазон сортування (вiдмiнники) - "<<V_min<<"/"<<V_max<<endl;
                cout<<"<<";
                cin>>g;
				switch (g)
					{	case 0 : { cout<<endl<<"\t\tExit..."<<endl; exit (1); break;}
						case 1 : { meny_vvoda (); break; }
						case 2 : { printer (); getch (); break; }
						case 3 : { sort (); getch (); break; }
						case 4 : { file_printer ();  break; }
						case 5 : { optiom_meny();  break; }
				
					}
					system ("cls");
			}
getch ();
return 0;
}

void v_vod () 
{
	for (int i=0;i<persone;i++)
	{
	system ("cls");
		cout<<i+1<<"/"<<persone<<" Iм*я - ";
		cin>>data_key[i].name;
		
	for (int g=0;g<predmets;)
	{
	cout<<"Предмет "<<g+1<<"/"<<predmets<<" ";
	cin>>data_key[i].predmet[g];
	if (!((data_key[i].predmet[g]<=max_b)&&(data_key[i].predmet[g]>=min_b)))
	{
	cout<<"Fatal system error!!!... (Данi введенi не коректно!.)"<<endl;
	Sleep (500);
	}
	else { g++; }
	}
	
	}
}

void printer (void)
{
system ("cls");
	for (int i=0;i<persone;i++)
	{
			cout<<"\t\t\t-------------------"<<endl<<"\t\t\t---------"<<i+1<<"---------"<<endl;
			cout<<"\t\t\t    Iм*я - "<<data_key[i].name<<endl;
			if (data_key[i].predmet[0]>data_key[i].summ)
			{
			for (int g=0;g<predmets;g++)
			{
			cout<<"\t\t\tПредмет "<<data_key[i].predmet[g]<<" бал. "<<endl;
			}
			cout<<"\t\t\tСереднiй бал "<<summa(i)/predmets/max_b<<endl<<endl;
			}
			else 
			cout<<"\t\t\tСереднiй бал "<<data_key[i].summ/predmets/max_b<<" бал. "<<endl<<endl;
			
	}
	cout<<endl<<endl<<"\tНатиснiть на будь-яку клавiшу щоб вийти в меню...";
}

void sort ()
{
	system ("cls");
	double suum_persone=0;
	for (int i=0; i<persone;i++)
	suum_persone+=summa (i);
	cout<<"Середнiй бал класу = "<<suum_persone/persone/predmets<<endl;
	cout<<endl<<"\t\t Хорошисти:"<<endl; 
	for (int i=0; i<persone;i++)
	{
	if ((procent (i)>=X_min)&&(procent (i)<=X_max))
	cout<<"Iм*я - "<<data_key[i].name<<" Cереднiй бал = "<<summa (i)/predmets<<" Рiзниця = "<<(summa (i)/predmets)-(suum_persone/persone/predmets)<<endl;
	}	
	cout<<endl<<"\t\t Вiдмiнники:"<<endl; 
	for (int i=0; i<persone;i++)
	{
	if ((procent (i)>=V_min)&&(procent (i)<=V_max))
	cout<<"Iм*я - "<<data_key[i].name<<" Cереднiй бал = "<<summa (i)/predmets<<" Рiзниця = "<<(summa (i)/predmets)-(suum_persone/persone)/predmets<<endl;
	}

}


double summa (int i)
{
	double suum=0;
	if (data_key[i].predmet[0]>data_key[i].summ)
		{
			for (int s=0;s<predmets;s++)
			suum+=data_key[i].predmet[s];
		}
		else 
		{
			suum+=data_key[i].summ;
		}
	return (suum);
}


double procent (int i)
{
	double suum=0;
	if (data_key[i].predmet[0]>data_key[i].summ)
		{
			for (int s=0;s<predmets;s++)
			suum+=data_key[i].predmet[s];
		}
		else 
		{
			suum+=data_key[i].summ;
		}	
		suum=((suum/predmets)/max_b)*100;
	return (suum);
}

void optiom_meny (void)
{
int test,i,test1,test2;
system ("cls");

cout<<"1. Змiнити кiлькiсть учнiв."<<endl<<"2. Змiнити кiлькiсть предметiв."<<endl<<"3. Задати максимальний та мiнiмальний бал."<<endl<<"4. Змiнити рамки вiдбору (xорошистiв/вiдмiнникiв)"<<endl<<"5. Змiнити iм*я файла для збереження"<<endl<<"0. Назад"<<endl<<"<<";
cin>>i;

switch (i)
{
case 1: {cout<<"Задайте кiлькiсть учнiв,"<<endl<<"(або при значеннi 0 буде задано стандартне 30 ) = "<<endl; 
cin>>test;
	if ((test!=0)&&(test>0)&&(test<500))
	{
	persone=test;
	cout<<"Значення змiнено  на  "<<test<<endl; }
	else 
	{
	cout<<"Значення не змiнено..."<<endl;
	} Sleep (500); break; }


case 2 : {cout<<"Задайте кiлькiсть предметiв, "<<endl<<"(або при значеннi 0 буде задано стандартне 5 ) = "<<endl; 
	cin>>test;
	if ((test!=0)&&(test>0)&&(test<50))
	{
	predmets=test;
	cout<<"Значення змiнено  на  "<<test<<endl; }
	else 
	{
	cout<<"Значення не змiнено..."<<endl;
	getch ();
	} Sleep (500); break; }


case 3 : 
	{
cout<<"Задайте максимальний бал : "<<endl<<"(або при значеннi 0 буде задано стандартне 5 ) = "<<endl; 
cin>>test1;
cout<<"Задайте мiнiмальний бал : "<<endl<<"(або при значеннi 0 буде задано стандартне 0 ) = "<<endl; 
cin>>test2;

	if (test2>test1)
	swap (test1,test2);
	
	if ((test1!=0)&&(test1>0)&&(test2!=0)&&(test2>0))
	{
	max_b=test1;
	min_b=test2;
	cout<<"Значення змiнено  на  (вiд "<<test1<<" до "<<test2<<")"<<endl; getch ();
	}
	else 
	{
	cout<<"Значення не змiнено..."<<endl;
	Sleep (500);
	} 
	break; 
	}
	case 4 : {granichi(); break; }
	case 5 : {system ("cls"); cin>>file_name;cout<<endl<<"I*мя змінено на "<<file_name; Sleep (500); break; }
}
}

void meny_vvoda (void)
{
	int i;
	system ("cls");
	cout<<"1. Вказати оцiнки по предметам."<<endl<<"2. Вказати середнiй бал."<<endl<<"3. Додати запис до iснуючих"<<endl<<"0. Назад"<<endl;
	cin>>i;
	switch (i)
	{	
	case 1 : { v_vod ();	break;}
	case 2 : { v_vod_summ ();	break;}
	case 3 : { vvod_data_add ();	break;}
	}
}


void vvod_data_add (void)
{
int test;
cout<<"Вкажiть скiльки записiв додати = ";
cin>>test;
if (test>0)
{
b_persone=persone;
persone+=test;
cout<<"Змiнено з "<<b_persone<<" на "<<persone<<endl;
Sleep (500);
add_list ();
}
else
{
cout<<"Значення не змiнено..."<<endl;
Sleep (500);    
}


}




void v_vod_summ (void)
{
	for (int i=0;i<persone;)
	{
		system ("cls");
		cout<<i+1<<" Iм*я - ";
		cin>>data_key[i].name;
		cout<<"Cереднiй бал ";
		cin>>data_key[i].summ;
			if (data_key[i].summ>=0)
			i++;
			else
			{
				cout<<endl<<"\t***!!!Значення може =0 , або >-1...!!!***"<<endl;
				Sleep (500);
			}
	}
	
}

void granichi (void)
{
	int i,max_test, min_test;
	system ("cls");
	cout<<"1. Змiнити дiапазон вiдбору (хорошисти)."<<endl<<"2. Змiнити дiапазон вiдбору (вiдмiнники)."<<endl<<"0. Назад"<<endl;
	cin>>i;
	switch (i)
{
	case 1 : { 
		cout<<"При значеннi 0 буде задано стандартне вiд 65 до 85"<<endl;
		cout<<"Вкажiть максимальне значення для вiдбору (хорошисти) = ";
		cin>>max_test;
		cout<<"Вкажiть мiнiмальне значення для вiдбору (хорошисти) = ";
		cin>>min_test;
		if (max_test<min_test)
		swap (max_test,min_test);
		
		if ((max_test>0)&&(min_test!=max_test)&&(max_test<=100)&&(min_test>0)&&(min_test<=100))
		{
		X_max=max_test;
		X_min=min_test;
		cout<<"Значення успiшно змiненi на (вiд "<<X_max<<" до "<<X_min<<")... ";
		}
		else
		cout<<"Значення не змiнено..."<<endl;
	    Sleep (500); break;}
	
	case 2 : { 
		cout<<"При значеннi 0 буде задано стандартне вiд 85 до 100"<<endl;
		cout<<"Вкажiть максимальне значення для вiдбору (вiдмiнники) = ";
		cin>>max_test;
		cout<<"Вкажiть мiнiмальне значення для вiдбору (вiдмiнники) = ";
		cin>>min_test;
		if (max_test<min_test)
		swap (max_test,min_test);
		
		if ((max_test>0)&&(min_test!=max_test)&&(max_test<=100)&&(min_test>0)&&(min_test<=100))
		{
		V_max=max_test;
		V_min=min_test;
		cout<<"Значення успiшно змінені на (вiд "<<V_max<<" до "<<V_min<<")... ";
		}
		else
		cout<<"Значення не змiнено..."<<endl;
        Sleep (500);	break;}
}	
}


void add_list (void)
{ 
  for (int i=b_persone;i<persone;i++)
	{
	system ("cls");
		cout<<i+1<<"/"<<persone<<" Iм*я - ";
		cin>>data_key[i].name;
		
	for (int g=0;g<predmets;)
	{
	cout<<"Предмет "<<g+1<<"/"<<predmets<<" ";
	cin>>data_key[i].predmet[g];
	if (!((data_key[i].predmet[g]<=max_b)&&(data_key[i].predmet[g]>=min_b)))
	{
	cout<<"Fatal system error!!!... (Данi введенi не коректно!.)"<<endl;
	Sleep (500);
	}
	else { g++; }
	}
	}
}

void file_printer (void)
{
     system ("cls"); 
     strcat(file_name,format);
     char * file_nam = new char [strlen(file_name)];
     file_nam=file_name;
     fstream f;
     f.open(file_nam, ios::out);
     if (!f.is_open())
     {cout<<"Файл не був вiдкритий!!!..."<<endl;
     Sleep (500);
     main ();
     } 
     for (int i=0;i<persone;i++)
	{
         if (data_key[i].predmet[0]!=' ')
			f<<data_key[i].name<<endl;
			if (data_key[i].predmet[0]>data_key[i].summ)
			{
			for (int g=0;g<predmets;g++)
			{
			f<<data_key[i].predmet[g]<<endl;
			}
			f<<summa(i)/predmets<<endl<<endl;
			}
			else 
			if (data_key[i].summ!=0)
			f<<data_key[i].summ/predmets<<endl<<endl;
			
	}
	cout<<"Данi успiшно доданi й файл :) "<<endl<<"\tНатиснiть на будь-яку клавiшу щоб вийти в меню...";
	getch ();
	system ("cls");
    main ();
}

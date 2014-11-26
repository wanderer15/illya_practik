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
				cout<<"1. ������ �����"<<endl<<"2. ������� �� �����"<<endl<<"3. �i���������� "<<endl<<"4. �������� � ����"<<endl<<"5. ������������"<<endl<<"0. ���i�"<<endl<<endl;
				cout<<"\t���: "<<endl<<"������ - "<<persone<<endl<<"�i���i��� �������i� - "<<predmets<<endl<<"������������ �� �i�i������� ���������� ��� - "<<max_b<<"/"<<min_b<<endl;
                cout<<"�i������ ���������� (���������) - "<<X_min<<"/"<<X_max<<endl;
                cout<<"�i������ ���������� (�i��i�����) - "<<V_min<<"/"<<V_max<<endl;
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
		cout<<i+1<<"/"<<persone<<" I�*� - ";
		cin>>data_key[i].name;
		
	for (int g=0;g<predmets;)
	{
	cout<<"������� "<<g+1<<"/"<<predmets<<" ";
	cin>>data_key[i].predmet[g];
	if (!((data_key[i].predmet[g]<=max_b)&&(data_key[i].predmet[g]>=min_b)))
	{
	cout<<"Fatal system error!!!... (���i ������i �� ��������!.)"<<endl;
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
			cout<<"\t\t\t    I�*� - "<<data_key[i].name<<endl;
			if (data_key[i].predmet[0]>data_key[i].summ)
			{
			for (int g=0;g<predmets;g++)
			{
			cout<<"\t\t\t������� "<<data_key[i].predmet[g]<<" ���. "<<endl;
			}
			cout<<"\t\t\t������i� ��� "<<summa(i)/predmets/max_b<<endl<<endl;
			}
			else 
			cout<<"\t\t\t������i� ��� "<<data_key[i].summ/predmets/max_b<<" ���. "<<endl<<endl;
			
	}
	cout<<endl<<endl<<"\t������i�� �� ����-��� ����i�� ��� ����� � ����...";
}

void sort ()
{
	system ("cls");
	double suum_persone=0;
	for (int i=0; i<persone;i++)
	suum_persone+=summa (i);
	cout<<"������i� ��� ����� = "<<suum_persone/persone/predmets<<endl;
	cout<<endl<<"\t\t ���������:"<<endl; 
	for (int i=0; i<persone;i++)
	{
	if ((procent (i)>=X_min)&&(procent (i)<=X_max))
	cout<<"I�*� - "<<data_key[i].name<<" C�����i� ��� = "<<summa (i)/predmets<<" �i����� = "<<(summa (i)/predmets)-(suum_persone/persone/predmets)<<endl;
	}	
	cout<<endl<<"\t\t �i��i�����:"<<endl; 
	for (int i=0; i<persone;i++)
	{
	if ((procent (i)>=V_min)&&(procent (i)<=V_max))
	cout<<"I�*� - "<<data_key[i].name<<" C�����i� ��� = "<<summa (i)/predmets<<" �i����� = "<<(summa (i)/predmets)-(suum_persone/persone)/predmets<<endl;
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

cout<<"1. ��i���� �i���i��� ���i�."<<endl<<"2. ��i���� �i���i��� �������i�."<<endl<<"3. ������ ������������ �� �i�i������� ���."<<endl<<"4. ��i���� ����� �i����� (x�������i�/�i��i����i�)"<<endl<<"5. ��i���� i�*� ����� ��� ����������"<<endl<<"0. �����"<<endl<<"<<";
cin>>i;

switch (i)
{
case 1: {cout<<"������� �i���i��� ���i�,"<<endl<<"(��� ��� �������i 0 ���� ������ ���������� 30 ) = "<<endl; 
cin>>test;
	if ((test!=0)&&(test>0)&&(test<500))
	{
	persone=test;
	cout<<"�������� ��i����  ��  "<<test<<endl; }
	else 
	{
	cout<<"�������� �� ��i����..."<<endl;
	} Sleep (500); break; }


case 2 : {cout<<"������� �i���i��� �������i�, "<<endl<<"(��� ��� �������i 0 ���� ������ ���������� 5 ) = "<<endl; 
	cin>>test;
	if ((test!=0)&&(test>0)&&(test<50))
	{
	predmets=test;
	cout<<"�������� ��i����  ��  "<<test<<endl; }
	else 
	{
	cout<<"�������� �� ��i����..."<<endl;
	getch ();
	} Sleep (500); break; }


case 3 : 
	{
cout<<"������� ������������ ��� : "<<endl<<"(��� ��� �������i 0 ���� ������ ���������� 5 ) = "<<endl; 
cin>>test1;
cout<<"������� �i�i������� ��� : "<<endl<<"(��� ��� �������i 0 ���� ������ ���������� 0 ) = "<<endl; 
cin>>test2;

	if (test2>test1)
	swap (test1,test2);
	
	if ((test1!=0)&&(test1>0)&&(test2!=0)&&(test2>0))
	{
	max_b=test1;
	min_b=test2;
	cout<<"�������� ��i����  ��  (�i� "<<test1<<" �� "<<test2<<")"<<endl; getch ();
	}
	else 
	{
	cout<<"�������� �� ��i����..."<<endl;
	Sleep (500);
	} 
	break; 
	}
	case 4 : {granichi(); break; }
	case 5 : {system ("cls"); cin>>file_name;cout<<endl<<"I*�� ������ �� "<<file_name; Sleep (500); break; }
}
}

void meny_vvoda (void)
{
	int i;
	system ("cls");
	cout<<"1. ������� ��i��� �� ���������."<<endl<<"2. ������� ������i� ���."<<endl<<"3. ������ ����� �� i�������"<<endl<<"0. �����"<<endl;
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
cout<<"����i�� ��i���� �����i� ������ = ";
cin>>test;
if (test>0)
{
b_persone=persone;
persone+=test;
cout<<"��i���� � "<<b_persone<<" �� "<<persone<<endl;
Sleep (500);
add_list ();
}
else
{
cout<<"�������� �� ��i����..."<<endl;
Sleep (500);    
}


}




void v_vod_summ (void)
{
	for (int i=0;i<persone;)
	{
		system ("cls");
		cout<<i+1<<" I�*� - ";
		cin>>data_key[i].name;
		cout<<"C�����i� ��� ";
		cin>>data_key[i].summ;
			if (data_key[i].summ>=0)
			i++;
			else
			{
				cout<<endl<<"\t***!!!�������� ���� =0 , ��� >-1...!!!***"<<endl;
				Sleep (500);
			}
	}
	
}

void granichi (void)
{
	int i,max_test, min_test;
	system ("cls");
	cout<<"1. ��i���� �i������ �i����� (���������)."<<endl<<"2. ��i���� �i������ �i����� (�i��i�����)."<<endl<<"0. �����"<<endl;
	cin>>i;
	switch (i)
{
	case 1 : { 
		cout<<"��� �������i 0 ���� ������ ���������� �i� 65 �� 85"<<endl;
		cout<<"����i�� ����������� �������� ��� �i����� (���������) = ";
		cin>>max_test;
		cout<<"����i�� �i�i������ �������� ��� �i����� (���������) = ";
		cin>>min_test;
		if (max_test<min_test)
		swap (max_test,min_test);
		
		if ((max_test>0)&&(min_test!=max_test)&&(max_test<=100)&&(min_test>0)&&(min_test<=100))
		{
		X_max=max_test;
		X_min=min_test;
		cout<<"�������� ���i��� ��i���i �� (�i� "<<X_max<<" �� "<<X_min<<")... ";
		}
		else
		cout<<"�������� �� ��i����..."<<endl;
	    Sleep (500); break;}
	
	case 2 : { 
		cout<<"��� �������i 0 ���� ������ ���������� �i� 85 �� 100"<<endl;
		cout<<"����i�� ����������� �������� ��� �i����� (�i��i�����) = ";
		cin>>max_test;
		cout<<"����i�� �i�i������ �������� ��� �i����� (�i��i�����) = ";
		cin>>min_test;
		if (max_test<min_test)
		swap (max_test,min_test);
		
		if ((max_test>0)&&(min_test!=max_test)&&(max_test<=100)&&(min_test>0)&&(min_test<=100))
		{
		V_max=max_test;
		V_min=min_test;
		cout<<"�������� ���i��� ����� �� (�i� "<<V_max<<" �� "<<V_min<<")... ";
		}
		else
		cout<<"�������� �� ��i����..."<<endl;
        Sleep (500);	break;}
}	
}


void add_list (void)
{ 
  for (int i=b_persone;i<persone;i++)
	{
	system ("cls");
		cout<<i+1<<"/"<<persone<<" I�*� - ";
		cin>>data_key[i].name;
		
	for (int g=0;g<predmets;)
	{
	cout<<"������� "<<g+1<<"/"<<predmets<<" ";
	cin>>data_key[i].predmet[g];
	if (!((data_key[i].predmet[g]<=max_b)&&(data_key[i].predmet[g]>=min_b)))
	{
	cout<<"Fatal system error!!!... (���i ������i �� ��������!.)"<<endl;
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
     {cout<<"���� �� ��� �i�������!!!..."<<endl;
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
	cout<<"���i ���i��� �����i � ���� :) "<<endl<<"\t������i�� �� ����-��� ����i�� ��� ����� � ����...";
	getch ();
	system ("cls");
    main ();
}

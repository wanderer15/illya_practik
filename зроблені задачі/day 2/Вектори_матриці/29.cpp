#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

using namespace std;



int main()
{
	setlocale (0,"rus");
    int size,chislo;
    for (int a=0;a<1;)
    {
    system ("cls");
	cout<<"����i�� ����i��i��� ��� ������i = ";
	cin >> size;
	if (size>1)
	a=1;
	}

	srand(time(NULL));

	 double** Pingvin = new double* [size];
	 for(int i = 0; i < size; i++)
	 {
	 Pingvin[i] = new double [size];
	 }
	 
	 for (int x=0;x<size;x++)
	 {
	 	for (int y=0;y<size;y++)
	 	{
	 		Pingvin[x][y]=sin(1.5);
	 	}
	 }
	 cout<<endl;
	 for (int str=0,x,y;str<size*2;)
	 {
	 	cout<<"����i�� ����������:"<<endl<<"X = ";
	 	cin>>x;
	 	if (x<size)
	 	{cout<<endl<<"Y = ";
		 cin>>y;
		 if (y<size)
	 	{
		 
		 if (Pingvin[x][y]==sin(1.5))
	 	{cout<<endl<<"��� ����� ��������?  = ";
	 		cin>>chislo;
		 	str++;
		 	Pingvin[x][y]=chislo;
		 }
	 	else 
		 cout<<endl<<"����.. �������� ��� i����......"<<endl;
		 }
	 	else
	 	cout<<endl<<"����.. �� ��������� �����i ����������..."<<endl;
		 }
	 	else
	 	cout<<endl<<"����.. �� ��������� �����i ����������..."<<endl;
	 	
	 }
	 
	 for (int x=0;x<size;x++)
	 {
	 	for (int y=0;y<size;y++)
	 	{
	 		cout<<Pingvin[x][y]<<" ";
	 	}
	 }
	
	getch ();
    return 0;
}




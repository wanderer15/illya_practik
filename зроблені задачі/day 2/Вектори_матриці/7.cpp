/*7.	Виконати злиття впорядкованого за зростанням A(m) і невпорядкованого B(n)
 масивів (n<<m) у впорядкований за неспаданням масив С.*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;



int main()
{
	setlocale (0,"rus");
    int size,change=0,x1=0,y1=0;
    cout<<"Здайте розмiрнiсть = ";
    cin >> size;
	srand(time(NULL));
	//створюємо динам. масив А
	int** A = new int* [size];
 	for(int i = 0; i < size; i++)
 	{
 	A[i] = new int [size];
	 }
	 //створюємо динам. масив B
	int** B = new int* [size];
 	for(int i = 0; i < size; i++)
 	{
 	B[i] = new int [size];
	 }
	 //створюємо динам. масив A1 / відсотовані елементи
	 int** A1 = new int* [size];
 	for(int i = 0; i < size; i++)
 	{
 	A1[i] = new int [size];
	 }
	//створюємо динам. масив P 
	  int** P = new int* [size*2];
 	for(int i = 0; i < size*2; i++)
 	{
 	P[i] = new int [size*2];
	 }
 	  
 	  
    // заповняємо створюємо масив А
    cout<<endl<<"\t A мас."<<endl;
    for (int x = 0; x < size; x++)
    {
    for (int y = 0; y < size; y++)
    {
         A[x][y]=rand()%9+1;
         cout<< A[x][y]<<" ";
    }
    cout<<endl;
	}
	
	   cout<<endl<<"\t B мас."<<endl;
	for (int x = 0; x < size; x++)
    {
    for (int y = 0; y < size; y++)
    {
         B[x][y]=rand()%9+1;
         cout<< B[x][y]<<" ";
    }
    cout<<endl;
	}
	

	
	
//сортування
for (int i=0;i <=9;i++)
{
	for(int x = 0; x < size; x++)
	{
	    for(int y = 0; y < size; y++)
	      {
	      	if (y1==size)
		    {
		    x1++;
		    y1=0;
		    } 	
	      		if (A[x][y]==i)
	          	{
				A1[x1][y1]=A[x][y];
				y1++;
				}
	      }
	}
}
        
   cout<<endl<<" A впорядкування..."<<endl;
   x1=0,y1=0;
for (int x = 0; x < size; x++)
    {
    for (int y = 0; y < size; y++)
    {
    	if  ((y1==(size*2)-0)&&(x1<=size))
    	{x1++;
		y1=0;}
         cout<< A1[x][y]<<" ";
         P[x1][y1]=A1[x][y];
         y1++;
         if (y==size-1)
         {
         	for (int t=0; t<size; t++)
         	{
         		if  ((y1==(size*2)-0)&&(x1<=size))
    			{x1++;
				y1=0;}
	         	cout<<B[x][t]<<" ";	
	         	P[x1][y1]=B[x][t];
	         	y1++;
         	}
         }
    }
    cout<<endl;
	}
	
	cout<<endl<<"\t P мас."<<endl;

	for (int i=0,st_l=0;i <=9;i++)
{
	for(int x = 0; x < size; x++)
	{
	    for(int y = 0; y < size*2; y++)
	      {
	      	if (y1==size)
		    {
		    x1++;
		    y1=0;
		    } 	
	      		if (P[x][y]==i)
	          	{
				cout<<P[x][y]<<" ";
				y1++;
				st_l++;
				}
			if (st_l==size*2)
			{
			st_l=0;
			cout<<endl;	
			}
	      }  
	}
}

	getch ();
    return 0;
}



# include <iostream>
# include <conio.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

using namespace std;



int main ()
{
setlocale(0, "rus");
srand(time(NULL));
int n;
cout<<"«адайте розiмрнiсть : ";
cin>>n;
   cout << endl<<"\tћатриц€ (A  /  b)"<<endl;
// определение вектора 
 int * mas_vector=new int [n];
 for (int i=0;i<n;i++)
 mas_vector[i]=rand()%9+1;
// определение матриць
 int** a = new int* [n];
 for(int i = 0; i < n; i++)
 {
 a[i] = new int [n];
 }


 int** nul_m = new int* [n];
 for(int i = 0; i < n; i++)
 {
 nul_m[i] = new int [n];
 }
 
 
 int** result_matrix = new int* [n];
 for(int i = 0; i < n; i++)
 {
 result_matrix[i] = new int [n];
 }
 
 int** result = new int* [n];
 for(int i = 0; i < n; i++)
 {
 result[i] = new int [n];
 }
 
 // ¬иводимо матрицю та заповн€Їмо
 for(int i = 0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 nul_m[i][k]=1;
 a[i][k]=rand()%9+1;
 cout << a[i][k] << " ";
 }
 cout <<"   "<<mas_vector[i]<< endl;
 }
 
   cout << endl<<"\tћатриц€ (A*b)"<<endl;
 //ћатриц€ (матриц€*вектор)
 for(int i = 0,summ=0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 	summ+=a[i][k]*mas_vector[k];
 }
 cout << "\t "<<summ<< "\t ";
 summ=0;
 cout << endl;
 }
 

  cout << endl<<"\tћатриц€ (A^2+b)"<<endl;
 //pow (матриц€,2)+вектор
 for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
{
result_matrix[i][j] = 0;
for(int k = 0;k < n; k++)
{
result_matrix[i][j] += a[i][k] * a[k][j];
}
}
 cout<<"ѕiдносимо до квадрату :"<<endl;
 for(int i = 0,summ=0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 cout << result_matrix[i][k] << "\t ";
 }
 cout << endl;
 } 
 cout<<endl;
 
  cout<<"—уму * на вектор :"<<endl;
 
 for(int i = 0,summ=0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 	summ+=result_matrix[i][k]*mas_vector[k];
 }
 cout << "\t "<<summ<< "\t ";
 summ=0;
 cout << endl;
 }
 
 
cout << endl<<"\tћатриц€ (A-E)*b"<<endl;
 //ћатриц€ - 1 матриц€ * вектор
 for(int i = 0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 	result[i][k]=a[i][k]- nul_m[i][k];
 cout <<result[i][k]<< "\t ";
 }
 cout << endl;
 }
 
 cout<<"—уму * на вектор :"<<endl;
 
 for(int i = 0,summ=0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 	summ+=result[i][k]*mas_vector[k];
 }
 cout << "\t "<<summ<< "\t ";
 summ=0;
 cout << endl;
 }
 
 
 // уничтожение массив≥в:
 for(int i = 0; i < n; i++)
 {
 delete [] a[i];
 delete [] nul_m[i];
 }
 delete [] a;
 delete [] nul_m;
 delete [] mas_vector;
 
 
	getch();
	return 0;    
}




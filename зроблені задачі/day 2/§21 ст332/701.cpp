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
cout<<"������� ���i���i��� : ";
cin>>n;
   cout << endl<<"\t������� (A  /  b)"<<endl;
// ����������� ������� 
 int * mas_vector=new int [n];
 for (int i=0;i<n;i++)
 mas_vector[i]=rand()%9+1;
// ����������� �������
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
 
 // �������� ������� �� ����������
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
 
   cout << endl<<"\t������� (A*b)"<<endl;
 //������� (�������*������)
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
 

  cout << endl<<"\t������� (A^2+b)"<<endl;
 //pow (�������,2)+������
 for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
{
result_matrix[i][j] = 0;
for(int k = 0;k < n; k++)
{
result_matrix[i][j] += a[i][k] * a[k][j];
}
}
 cout<<"�i������� �� �������� :"<<endl;
 for(int i = 0,summ=0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 cout << result_matrix[i][k] << "\t ";
 }
 cout << endl;
 } 
 cout<<endl;
 
  cout<<"���� * �� ������ :"<<endl;
 
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
 
 
cout << endl<<"\t������� (A-E)*b"<<endl;
 //������� - 1 ������� * ������
 for(int i = 0; i < n; i++)
 {
 for(int k = 0; k < n; k++)
 {
 	result[i][k]=a[i][k]- nul_m[i][k];
 cout <<result[i][k]<< "\t ";
 }
 cout << endl;
 }
 
 cout<<"���� * �� ������ :"<<endl;
 
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
 
 
 // ����������� �������:
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




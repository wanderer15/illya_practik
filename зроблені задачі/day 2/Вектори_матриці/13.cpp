/*���� ����������� ����� �����. �'�������, �� ����� ������� �� �� ���� ����� �����, 
��� ������� ����� ����-��� ���� ��������� ������ � ���� � �����
a.	��� ����������� �����
b.	��� �������� �����.*/


#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;



int main()
{
	setlocale (0,"rus");
	int size, tru_e=0;
		cout<<"��i���� �������i� �� ������ �������� ? :";
		cin>>size;
	double * mas_i=new double [size];
	double * mas_o=new double [size];
	
	for (int i=0;i<size;i++)
	{
		cin>>mas_i[i];
	}
	cout<<endl<<"�����! �� ����� ���i  ��������... :"<<endl;
	
	for (int i=0;i<size;i++)
	{
		cout<<mas_i[i]<<" ";
	}
	cout<<endl;

	for (int i=0;i<size;i++)
	{
		for (int dill=2;dill<10;dill++)
		if (mas_i[i]/dill<2)
		mas_o[i]=mas_i[i]/dill;
		
	}
		double transt=mas_o[0];
		for (int i=0;i<=size;i++)
	{
		if (transt==mas_o[i])
		tru_e++;
	}
	
	
	for (int i=0;i<size;i++)
	cout<<mas_o[i]<<" ";
	
	cout<<endl;
	if (tru_e==size)
	cout<<"��� �������!";
	else 
	cout<<"�� �������!";
	
getch ();
return 0;
}

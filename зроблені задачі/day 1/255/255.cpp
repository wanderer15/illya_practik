# include <iostream>
# include <conio.h>
# include <string.h>
# include <stdio.h>

using namespace std;

struct pipels 
{
       char name[50];
       int data;
}pip[100];

int main ()
{
setlocale(0, "rus");
int tumbler=0;
char start_str[500],filter_str;
cout<<"�����i�� ������� �� ����� : ";
gets(start_str);
char * mas_str_f = new char  [strlen(start_str)];
mas_str_f=start_str;
cout<<endl<<"����i�� ��� ����� ������ : ";
cin>>filter_str;

for (int i=0;i<=strlen(start_str);i++)
{
	if ((mas_str_f[i]==filter_str)&&(mas_str_f[i+1]==filter_str))
	{
	cout<<"����� "<<filter_str<<" ��������! ����( "<<i+1<<" ) �� �������."<<endl;
	tumbler++;
	}	
}

	if (tumbler==0)
	cout<<tumbler;

getch();
return 0;    
}

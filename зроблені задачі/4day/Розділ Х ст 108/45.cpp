# include <iostream>
# include <conio.h>
# include <math.h>
# include <Windows.h>

using namespace std;

int max_SF (int , int );
int krok_SF (int , int );
int c_in_FT (int , int ,int );
int co_utp (int , int , int );
int co_utm (int , int ,int );

int main ()
{
setlocale (0,"rus");
int start, finish;
cout<<"������� ������ ������� ����i��� : ";
cin>>start;
cout<<"������� ������ ������� ����i��� : ";
cin>>finish;
int krok=krok_SF (start, finish);
cout<<"���� = "<<krok<<endl<<"������i�� ����i�..."<<endl; 
getch ();

int x=c_in_FT ( start,  finish, krok);

if (krok_SF (start, finish)>0)
{
co_utp (start,  x,  krok);
cout<<endl<<"�������� � �i������i :"<<endl<<" Vid "<< start<<" do "<<x;
}

if (krok_SF (start, finish)<0)
{
co_utm  (x,  start,  krok);
cout<<endl<<"�������� � �i������i :"<<endl<<" Vid "<< start<<" do "<<x;
}
getch ();
return 0;
}

int krok_SF (int a, int b)
{
	return ((a-b)*-1);
}

int max_SF (int a, int b)
{
	if (a<b)
	return (b);
	else if (a>b)
	return (a-b);
	else if (a==b)
	return (a);
}

int c_in_FT (int s, int f, int k)
{
	system("cls");
	int test;
	if (f+k==0)
	f+=k;
	cout<<" �������� = "<<f<<" ��i������ : "<<f+k<<" 0 - Exit... "<<endl;
	cout<<"<<";
	cin>>test;
	
	
		if (test==0)
		{
		 return(f);
		}
		
		
	if (krok_SF(s, f)<0)
	{
	 if (test==f+k)	
	 f+=k;
	}
	
	if (krok_SF (s, f)>0)
	{
	 if (test==f+k)	
	 f+=k;
	}
	c_in_FT ( s,  f, k);
}

int co_utp (int start, int stop, int krok)
{
	for (int i=start;i<=stop; i+=krok)
	cout<<i<<"  ";
}



int co_utm (int start, int stop, int krok)
{
	for (int i=stop;i>=start; i+=krok)
	cout<<i<<" ";
}


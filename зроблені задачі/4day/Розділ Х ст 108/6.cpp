# include <iostream>
# include <conio.h>
# include <math.h>

using namespace std;

double smyrfik (double , double );

int main ()
{
	setlocale (0,"rus");
	double ab,ac,dc,bd,p;
	cout<<"����i�� ������� �B ";
	cin>>ab;
	cout<<"����i�� ������� �C ";
	cin>>ac;
	cout<<"����i�� ������� DC ";
	cin>>dc;
	if  ((ab>0)&&(ac>0)&&(dc>0))
	{
		bd=smyrfik(dc,smyrfik(ab,ac));
		p=ab+bd+dc+ac;
		cout<<"�������� = "<<p;
	}
	else 
	cout<<"����������� �����i �������...!!!";
getch ();
return 0;
}

double smyrfik (double a, double b)
{
	return (sqrt (a*a+b*b));
}

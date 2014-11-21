# include <iostream>
# include <conio.h>
# include <math.h>

using namespace std;

double smyrfik (double , double );

int main ()
{
	setlocale (0,"rus");
	double ab,ac,dc,bd,p;
	cout<<"Введiть сторону АB ";
	cin>>ab;
	cout<<"Введiть сторону АC ";
	cin>>ac;
	cout<<"Введiть сторону DC ";
	cin>>dc;
	if  ((ab>0)&&(ac>0)&&(dc>0))
	{
		bd=smyrfik(dc,smyrfik(ab,ac));
		p=ab+bd+dc+ac;
		cout<<"Периметр = "<<p;
	}
	else 
	cout<<"Неправильно заданi сторони...!!!";
getch ();
return 0;
}

double smyrfik (double a, double b)
{
	return (sqrt (a*a+b*b));
}

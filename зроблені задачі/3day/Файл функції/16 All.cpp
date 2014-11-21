# include <iostream>
# include <conio.h>
# include <Windows.h>
# include <math.h>

using namespace std;


double funktions_11 (double );



int main ()
{
double a,b,h;
setlocale(0,"rus");
for (int i=0;i!=1;)
{
system ("cls");
cout<<"¬кажiть початок дiапазону: ";
cin>>a;
cout<<endl<<"¬кажiть кiнець дiапазону: ";
cin>>b;
cout<<endl<<"¬кажiть крок дiапазону: ";
cin>>h;
if (a>b)
swap(a,b);
if ((a==b)||(h>=b)||(h<=0))
{
cout<<"Crash system error!!!";
getch ();
}
else 
i++;
}

for (double i=a;i<b;i+=h)
{
if ((i>=-2*M_PI)&&(i<=2*M_PI)&&(h==0.5))
funktions_11 (i);

}
getch ();
return 0;    
}


double funktions_11 (double x)
{
if ((log10(sin(x))/(tan(x)-2)<(log10(sin(x))/0))||(log10(sin(x))/(tan(x)-2)>(log10(sin(x))/0)))
cout<<"11. "<<log10(sin(x))/(tan(x)-2)<<endl;
}



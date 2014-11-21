
# include <iostream>
# include <conio.h>
# include <Windows.h>
# include <math.h>

using namespace std;

double funktions (double , double );
void funktion (double , double , double , double );


int main ()
{
setlocale(0, "rus");
int a,b,c,d;
cout<<"Задайте значення А : ";
cin>>a;
cout<<"Задайте значення B : ";
cin>>b;
cout<<"Задайте значення Д : ";
cin>>d;
cout<<"Задайте значення С : ";
cin>>c;
cout<<"Вiдпоiдь = ";
funktion (a , b, c, d);
getch ();
return 0;    
}

double funktions (double a, double b)
{
return (pow(a+b,5));
}

void funktion (double a, double b, double c, double d)
{
double sum=0,sum1=0;
sum=funktions (a , b)+funktions (c , d);
sum1=funktions (c , a)*funktions (b , d);
if (sum1!=0)
cout<<sum/sum1;
else 
cout<<"Дiлення неможливе...";
}

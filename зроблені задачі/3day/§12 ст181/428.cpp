
/*задать значение а и б 
*/
# include <iostream>
# include <conio.h>
# include <Windows.h>
# include <math.h>

using namespace std;

double funktions (double , double );


int main ()
{
setlocale(0, "rus");
double U, V, a,b;
cout<<"Задайте значення А : ";
cin>>a;
cout<<"Задайте значення B : ";
cin>>b;
cout<<endl<<"Вiдпоiдь при (пошуку меншого числа) У = ";
cout<<funktions (a , b);
U=funktions (a , b);
cout<<endl<<"Вiдпоiдь при (пошуку меншого числа) В = ";
V=funktions (a*b , b+b);
cout<<funktions (a*b , b+b);
cout<<endl<<"Вiдпоiдь при (пошуку меншого числа) = ";
cout<<funktions (U+(V*V), 3.14);
getch ();
return 0;    
}

double funktions (double a, double b)
{
if (a>b)
return (b);
else
return (a);
}


/*������ �������� � � � 
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
cout<<"������� �������� � : ";
cin>>a;
cout<<"������� �������� B : ";
cin>>b;
cout<<endl<<"�i���i�� ��� (������ ������� �����) � = ";
cout<<funktions (a , b);
U=funktions (a , b);
cout<<endl<<"�i���i�� ��� (������ ������� �����) � = ";
V=funktions (a*b , b+b);
cout<<funktions (a*b , b+b);
cout<<endl<<"�i���i�� ��� (������ ������� �����) = ";
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

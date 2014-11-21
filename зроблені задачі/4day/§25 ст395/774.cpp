# include <iostream>
# include <conio.h>
# include <math.h>

using namespace std;

int main ()
{
double U=5, V=10, ro=100, fi=45,alpha=0,t,h=(ro/fi);
alpha=V/U;

for (double i=ro;i>=0;i-=5,fi-=h)
{
cout<<"Vidstan = "<<i<<endl;
cout<<"Kyn = "<<fi<<endl;
cout<<endl;
}

getch ();
return 0;
}


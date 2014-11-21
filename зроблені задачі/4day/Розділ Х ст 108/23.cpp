# include <iostream>
# include <conio.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

int day_mcv (int , int ,int );
int god_mcv (int );
int month_mcv (int , int );
int day_EVM (int , int ,int );
void error_s (void);

int main ()
{
setlocale (0,"rus");
int g,n,m;
cout<<"Ââåäiòü äàòó â ôîðìàòi [pppp:mm:dd] : ";
cin>>g;	
if (!(g>0))
error_s ();
cin>>n;
if (!(n<=12)||!(n>0))
error_s ();
cin>>m;
if ((m<=0)||(m>month_mcv (n,  g)))
error_s ();

day_mcv ( n, g, m);
cout<<"Ðiê : "<<g<<" Ìiñÿöü : "<<n<<" Äåíü : "<<m<<endl;
day_EVM ( n, g, m);
getch ();
return 0;
}

int day_EVM (int month, int year,int day)
{
	if ((month==12)&&(day==month_mcv (month, year)))
	cout<<"Ðiê : "<<year+1<<" Ìiñÿöü : "<<1<<" Äåíü : "<<1<<endl;
	else
	if ((1<=day+1)&&(day+1<=month_mcv ( month,  year)))
	{
	cout<<"Ðiê : "<<year<<" Ìiñÿöü : "<<month<<" Äåíü : "<<day+1<<endl;
	}
	else 
	{
	if ((day+1>=month_mcv ( month+1,  year)))
	cout<<"Ðiê : "<<year<<" Ìiñÿöü : "<<month+1<<" Äåíü : "<<1<<endl;
	}
}

int day_mcv (int month, int year,int day)
{
	if ((month==1)&&(day==1))
	cout<<"Ðiê : "<<year-1<<" Ìiñÿöü : "<<12<<" Äåíü : "<<month_mcv (12,  year-1)<<endl;
	else
	if ((1<=day-1)&&(day-1<=month_mcv ( month,  year)))
	{
	cout<<"Ðiê : "<<year<<" Ìiñÿöü : "<<month<<" Äåíü : "<<day-1<<endl;
	}
	else 
	{
	if ((day-1<=month_mcv ( month-1,  year)))
	cout<<"Ðiê : "<<year<<" Ìiñÿöü : "<<month-1<<" Äåíü : "<<month_mcv ( month-1,  year)<<endl;
	}
}

int month_mcv (int month, int year)
{
	
if (god_mcv ( year)==0)
{	
if (month!= 2 && month < 13 && month > 0)
    {
    if (month % 2)
      return (30);
    else 
      return (31);
    }
    else if (month == 2)
    {
    return (28);
    }
    else 
    {
    std::cout << "Invalid value.\n";
}
}
else
{
if (month!= 2 && month < 13 && month > 0)
    {
    if (month % 2)
      return (31);
    else 
      return (30);
    }
    else if (month == 2)
    {
    return (29);
    }
    else 
    {
    std::cout << "Invalid value.\n";
}
}
}

int god_mcv (int year)
{
	if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
		return (1);
	else
		return (0);
}

void error_s (void)
{
	cout<<"Crash system error...!!!";
	getch ();
	exit (0);
}
 

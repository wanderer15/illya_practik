
# include <iostream>
# include <conio.h>
# include <Windows.h>
# include <math.h>

using namespace std;

void funktions (char );


int main ()
{
setlocale(0, "rus");
char mas;
for (;;)
{system ("cls");
cout<<"����i�� 1 ������ : ";
cin>>mas;
funktions (mas);}
return 0;    
}

void funktions (char mas)
{
if ((mas>=97)&&(mas<=122)||(mas>=65)&&(mas<=90)||(mas>=192)&&(mas<=223)||(mas>=224)&&(mas<=255))
cout<<"�� ����� �����";
else
if ((mas>=48)&&(mas<=57))
cout<<"�� ����� �����";
else
cout<<"�� ����� ������";
getch ();
}

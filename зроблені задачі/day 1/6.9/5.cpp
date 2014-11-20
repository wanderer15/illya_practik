# include <iostream>
# include <conio.h>
# include <string.h>

using namespace std;

int main ()
{
setlocale(0, "rus");
char mas [500];
int summ=0,slovo=0;
fgets (mas, 500, stdin);
char *masiv_char = new char [strlen(mas)];
masiv_char=mas;
for (int i=0; i<strlen(masiv_char)-1;i++)
{
    if ((masiv_char[i]!=' ')&&( masiv_char[i]!='/0'))
    summ++;
   else
   {
       slovo++;
    cout<<"Слово "<<slovo<<" мiстить "<<summ<<" симв."<<endl;
    summ=0;
   }
}
slovo++;
cout<<"Слово "<<slovo<<" мiстить "<<summ<<" симв."<<endl;
getch();
return 0;    
}

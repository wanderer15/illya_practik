# include <iostream>
# include <conio.h>
# include <string.h>

using namespace std;

int main ()
{
setlocale(0, "rus");
char mas [500];
double suma, mali_bukvu=0, veluki_kukvu=0,text=0,probel=0;
fgets (mas, 500, stdin);
char *masiv_char = new char [strlen(mas)];
masiv_char=mas;
for (int i=0; i<strlen(masiv_char)-1;i++)
{
    if (masiv_char[i]==' ')
    probel++;
    if ((masiv_char[i]>=97)&&( masiv_char[i]<=122))
    mali_bukvu++;
   else if ((masiv_char[i]>=65)&&( masiv_char[i]<=90))
   {
    veluki_kukvu++;
   }
}
cout<<"Кiлькiсть малих букв = "<<mali_bukvu<<endl;
cout<<"Кiлькiсть велихик букв = "<<veluki_kukvu<<endl;
text=strlen(masiv_char)-1-probel;
cout<<"Вiдсоток малих букв = "<<mali_bukvu/text*100<<endl;
cout<<"Вiдсоток великих букв = "<<mali_bukvu/text*100<<endl;
getch();
return 0;    
}

/*Після введення з клавіатури довільного рядка визначити і вивести 
на екран кількість літер кирилиці в ньому.*/
# include <iostream>
# include <conio.h>
# include <string.h>
# include <stdio.h>

using namespace std;

int main ()
{
setlocale(0, "rus");
char mas [500];
int litera=0;
cout<<"Введiть текст ";
fgets (mas, 500, stdin);
char *masiv_char = new char [strlen(mas)];
masiv_char=mas;
for (int i=0; i<strlen(masiv_char)-1;i++)
{
    if ((masiv_char[i]>=-96)&&(masiv_char[i]<=-81)||(masiv_char[i]>=-32)&&(masiv_char[i]<=-17)||(masiv_char[i]>=-128)&&(masiv_char[i]<=-97))
    litera++;
}
cout<<"Кiлькiсть лiтер = "<<litera;
getch();
return 0;    
}

/*Після введення з клавіатури рядками деяких прізвищ і поруч
 з ними віку (рік народження) відсортувати і видати на екран цей список, 
 але з відсортованими за абеткою прізвищами. Прізвища із символів різних
  алфавітів розташувати окремими групами.
*/
# include <iostream>
# include <conio.h>
# include <string.h>
# include <stdio.h>

using namespace std;

struct pipels 
{
       char name[50];
       int data;
}pip[100];

int main ()
{
setlocale(0, "rus");
int zap=0;
cout<<"Вкажiть скiльки записiв ввести :";
cin>>zap;
for (int i=0;i<zap;i++)
{cout<<"\t\t"<<i+1<<"- запис"<<endl;
cout<<"Вкажiть iм*я та фамiлiю :";
cin.get();
gets (pip[i].name);
cout<<"Вкажiть рiк :";
cin>>pip[i].data;
if (pip[i].data<0)
cout<<"Помилка... Рік не можу бути <0!!!..."<<endl;}
cout<<"\tIм*я та фамiлiя"<<"\t\tРiк"<<endl;

for (int v_alfavit=65, m_alfavit=97; v_alfavit<=90;v_alfavit++,m_alfavit++)
{
for (int num=0;num<=zap;num++)
{
    
    if (pip[num].name[0]==m_alfavit)
   {cout<<"\t"<<pip[num].name<<"\t\t"<<pip[num].data<<endl;
   }
    
    if (pip[num].name[0]==v_alfavit)
   {cout<<"\t"<<pip[num].name<<"\t\t"<<pip[num].data<<endl;
   }
        
}
}
getch();
return 0;    
}

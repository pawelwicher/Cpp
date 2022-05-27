/*L3_Wicher_STNinz_gr1_programB
Pawe³ Wicher 55555
Program F */
#include<iostream>

using namespace std;

main()
{
float x,eps,wyraz,suma,potega,silnia;
int i;
char end;

     do
     {
     cout<<"\nObliczanie liczby e do x\n\n";
     cout<<"Podaj x: ";
     cin>>x;
     cout<<"\nPodaj przyblizenie: ";
     cin>>eps;

     potega=1;
     silnia=1;
     suma=1;
     i=1;

         do
         {
          silnia*=i;
          potega*=x;               
          wyraz=potega/silnia;
          suma+=wyraz;
          i++;
          }
          while(wyraz>eps);

      cout<<"\n\n"<<suma;


      cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
      cin>>end;
       
      } 
      while(end!='q');    
}

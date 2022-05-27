/*
Data
*/

#include <iostream>

using namespace std;

int main()
{
int rok, miesiac, dzien, liczba_dni;   
char end;

do
{
cout<<"Podaj rok\n";
cin>>rok;
cout<<"\n";
cout<<"Podaj miesiac\n";
cin>>miesiac;
cout<<"\n";
cout<<"Podaj dzien\n";
cin>>dzien;
cout<<"\n";
cout<<"\n";



if(miesiac==2)
{
if(rok%4==0) liczba_dni=29;
else liczba_dni=28;
}
else
{
if(miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11) liczba_dni=30;
else liczba_dni=31;
}
if(liczba_dni<dzien) cout<<"miesiac "<<miesiac<<" ma "<<liczba_dni<<" dni. Podaj poprawna date\n\n";
else 
{
cout<<"Podana przez Ciebie data to: "<<rok<<"-"<<miesiac<<"-"<<dzien<<"\n\n";

     
if(liczba_dni==dzien)
{
dzien=1;

          if(miesiac==12)
          {
          miesiac=1;
          rok++;
          }
          else
          {
          miesiac++;
          }
}
else
{
dzien++;   
}
cout<<"Data dnia nastepnego to: "<<rok<<"-"<<miesiac<<"-"<<dzien<<"\n\n";
}





cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

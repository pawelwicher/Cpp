/*
plik_L2_wicher_STNinz_gr1_wczytaj_znaki.cpp
Wicher Pawe³ 55555
wczytaj_znaki
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
int licznik;
char end, znak;

do
{
licznik=0;
cout<<"Petla while\n";
while(znak!='*')
{
znak=getche();
licznik++;
}
cout<<"\nLiczba wprowadzonych znakow: "<<licznik-1<<"\n\n";


licznik=0;
cout<<"Petla do while\n";
do
{
znak=getche();
licznik++;
}
while(znak!='*');
cout<<"\nLiczba wprowadzonych znakow: "<<licznik-1<<"\n\n";



znak='p';
cout<<"Petla for\n";
for(licznik=0;znak!='*';licznik++)
{znak=getche();}
cout<<"\nLiczba wprowadzonych znakow: "<<licznik-1<<"\n\n";




cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}


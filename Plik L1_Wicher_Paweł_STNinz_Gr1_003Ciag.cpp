/*
Plik L3_Wicher_Pawe³_STNinz_Gr1_001Ciag.cpp
Pawe³ Wicher 55555 DevC++
*/

#include <iostream>

using namespace std;

int main()
{
int ile_liczb=1; 
int i;
int licznik=0;
int liczba, poprzedni, nastepny, roznica;
int suma=0;
int suma_parzystych=0;
int p=1;
char end;

do
{

while(ile_liczb<=1)
{
cout<<"Podaj dlugosc ciagu \n";
cin>>ile_liczb;
if(ile_liczb<=1)
cout<<"Musisz podac liczbe wieksza od 1\n";
}

cout<<"Wprowadz "<<ile_liczb<<" liczb \n\n";

cout<<"Podaj liczbe nr: 1\n";
cin>>liczba;
poprzedni=liczba;
suma=suma+liczba;
if((liczba%2)==0) 
suma_parzystych=suma_parzystych+liczba;


cout<<"Podaj liczbe nr: 2\n";
cin>>liczba;
nastepny=liczba;
suma=suma+liczba;
if((liczba%2)==0) 
suma_parzystych=suma_parzystych+liczba;

roznica=nastepny-poprzedni;

for (i=3; i<=ile_liczb; i++)
{
cout<<"Podaj liczbe nr: "<<i<<"\n";
cin>>liczba;

suma=suma+liczba;

if((liczba%2)==0) 
suma_parzystych=suma_parzystych+liczba;

poprzedni=nastepny;
nastepny=liczba;

if(roznica!=(nastepny-poprzedni))
p=0;

roznica=nastepny-poprzedni;
}

cout<<"Suma wyrazow ciagu wynosi: "<<suma<<" a suma parzystych wynosi: "<<suma_parzystych<<"\n";

if(p==1)
cout<<"Podany ciag JEST ciagiem arytmetycznym\n\n";
else
cout<<"Podany ciag NIE JEST ciagiem arytmetycznym\n\n";

cout<<"q - koniec, dowolny znak - kontynuacja\n";
cin>>end;
ile_liczb=1;
}
while(end!='q');

}

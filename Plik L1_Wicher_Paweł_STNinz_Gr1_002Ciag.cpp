/*
Plik L3_Wicher_Pawe³_STNinz_Gr1_001Ciag.cpp
Pawe³ Wicher 55555 DevC++
*/

#include <iostream>

using namespace std;

int main()
{
int ile_liczb, i;
int licznik=0;
int a,liczba;
char end;

cout<<"Podaj liczbe, ktora ma wystapic w ciagu\n\n";
cin>>a;
cout<<"liczba ta wynosi: "<<a<<"\n\n";
cout<<"Podaj dlugosc ciagu \n";
cin>>ile_liczb;
cout<<"Wprowadz "<<ile_liczb<<" liczb \n\n";

for (i=1; i<=ile_liczb; i++)
{
cout<<"Podaj liczbe nr: "<<i<<"\n";
cin>>liczba;

 
if(a==liczba)
licznik++;


}

cout<<"W twoim ciagu liczba "<<a<< " wystapila "<<licznik<<" razy.";
cin>>end;

}
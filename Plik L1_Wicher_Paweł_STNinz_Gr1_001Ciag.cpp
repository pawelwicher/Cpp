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
int a,b,liczba;
char end;

cout<<"Podaj a i b\n\n";
cin>>a;
cin>>b;
cout<<"a= "<<a<<" b="<<b<<"\n\n";
cout<<"Podaj dlugosc ciagu \n";
cin>>ile_liczb;
cout<<"Wprowadz "<<ile_liczb<<" liczb \n\n";

for (i=1; i<=ile_liczb; i++)
{
cout<<"Podaj liczbe nr: "<<i<<"\n";
cin>>liczba;

  if(a<=b)
  {  
     if(liczba>a && liczba<b)
     licznik++;
  }
  else
  {
     if(liczba<a && liczba>b)
     licznik++;
  }
}

cout<<"\n\n W przedziale od "<<a<<" do "<<b<<" znalazlo sie "<<licznik<<" wyrazow ciagu";
cin>>end;

}
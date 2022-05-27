
//program menu + rozne funkcje


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
int Pierwsza(int);
int Doskonala(int);




//****************************funkcja main**************************************
int main()
{
int p,liczba;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  cout<<"\nPodaj liczbe naturalna\n";
  cin>>liczba;
  if(Pierwsza(liczba)) cout<<"\n"<<liczba<<" jest liczba pierwsza\n";
  else cout<<"\n"<<liczba<<" NIE jest liczba pierwsza\n";
  break;
 }
 
 case 2:
 {
  cout<<"\nPodaj liczbe naturalna\n";
  cin>>liczba;
  if(Doskonala(liczba)) cout<<"\n"<<liczba<<" jest liczba doskonala\n";
  else cout<<"\n"<<liczba<<" NIE jest liczba doskonala\n";
  break;
 }
}

}
while(p!=0);    //do momentu kiedy uzytkownik nie wybierze w menu 0

}
//****************************funkcja main**************************************


//****************************menu programu*************************************
int menu()
{
int odp;
cout<<"\nWybierz jedna z opcji:";
cout<<"\n1 - sprawdz czy podana liczba jest liczba pierwsza";
cout<<"\n2 - sprawdz czy podana liczba jest liczba doskonala";
cout<<"\n0 - zakoncz program\n\n";

do
{
 cin>>odp;
}
while(odp<0 || odp>2);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
int Pierwsza(int x)
{
int i=2;
int liczba_dzielnikow=0;
while(i!=x)
{
if(x%i==0) {liczba_dzielnikow=1;break;}
i++;               
}
return !liczba_dzielnikow;
}
//****************************funkcja numer 1***********************************



//****************************funkcja numer 2***********************************
int Doskonala(int x)
{
int i=2;
int suma_dzielnikow=1;
while(i<=x/2)
{
if(x%i==0) suma_dzielnikow+=i;
i++;               
}
return suma_dzielnikow==x;

}
//****************************funkcja numer 2***********************************

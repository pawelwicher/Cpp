//struktury

#include <iostream>
using namespace std;


struct osoba
{
       char nazwisko[30];
       int kwota;
       int nominal[8];
};


int menu();             //prototypy funkcji
void DodajOsobe(osoba [],int);
void WyswietlOsobe(osoba [],int);
void ZmienOsobe(osoba [],int);
void Kasjer(int [],int);


//****************************funkcja main**************************************
int main()
{
int p,numer,i,nr;
int const ROZMIAR=10;
osoba os[ROZMIAR];

numer=0;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  DodajOsobe(os,numer);
  numer++;
  break;
 }
 
 case 2:
 {
  do{
  cout<<"Podaj numer rekordu (liczba od 1 do "<<numer<<"), ktory chcesz zmodyfikowac: ";
  cin>>nr;
  }while(nr<1 || nr>numer);
  nr--;
  DodajOsobe(os,nr);
  break;
 }
 
  case 3:
 {
  for(i=0;i<numer;i++)
  {
  cout<<"*** Rekord numer: "<<i+1<<"***\n";
  WyswietlOsobe(os,i);
  cout<<"*** *** *** *** ***\n\n";
  }
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
cout<<"\n1 - Dodaj osobe";
cout<<"\n2 - Zmien dane";
cout<<"\n3 - Wyswietl dane";
cout<<"\n0 - Zakoncz program\n\n";

do
{
 cin>>odp;
}
while(odp<0 || odp>3);
system("cls");
return odp;
}
//****************************menu programu*************************************


//**************************pozostale funkcje***********************************
void DodajOsobe(osoba os[],int nr)
{
int nom[8];

     cout<<"Podaj nazwisko: "; cin>>os[nr].nazwisko;
     cout<<"Podaj kwote: "; cin>>os[nr].kwota;
     Kasjer(nom,os[nr].kwota);
     for(int i=0;i<=7;i++)os[nr].nominal[i]=nom[i];
}

void WyswietlOsobe(osoba os[],int nr)
{
     cout<<"Nazwisko: "<<os[nr].nazwisko<<"\n";
     cout<<"Kwota: "<<os[nr].kwota<<"\n";
     cout<<"200 - "<<os[nr].nominal[0]<<"\n";
     cout<<"100 - "<<os[nr].nominal[1]<<"\n";
     cout<<"50 - "<<os[nr].nominal[2]<<"\n";
     cout<<"20 - "<<os[nr].nominal[3]<<"\n";
     cout<<"10 - "<<os[nr].nominal[4]<<"\n";
     cout<<"5 - "<<os[nr].nominal[5]<<"\n";
     cout<<"2 - "<<os[nr].nominal[6]<<"\n";
     cout<<"1 - "<<os[nr].nominal[7]<<"\n";
}

void Kasjer(int t[8],int kwota)
{
for(int i=0;i<=7;i++)
t[i]=0;

while(kwota>=200)
{kwota-=200;t[0]++;}

while(kwota>=100)
{kwota-=100;t[1]++;}

while(kwota>=50)
{kwota-=50;t[2]++;}

while(kwota>=20)
{kwota-=20;t[3]++;}

while(kwota>=10)
{kwota-=10;t[4]++;}

while(kwota>=5)
{kwota-=5;t[5]++;}

while(kwota>=2)
{kwota-=2;t[6]++;}

while(kwota>=1)
{kwota-=1;t[7]++;}
}
//**************************pozostale funkcje***********************************

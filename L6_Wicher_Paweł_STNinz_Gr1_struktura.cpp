#include <iostream>
#include <string>
using namespace std;


struct osoba
{
       int id;
       char imie[10];
       char nazwisko[10];
       int data;
};


int menu();
void KopiujTablice(osoba [],osoba[],int);
void DodajOsobe(osoba [],int);
void WyswietlOsobe(osoba [],int);



//****************************funkcja main**************************************
int main()
{
osoba* t1;
osoba* t2;
int p,id,licz;
int n=1;

t1=new osoba[1];
t2=new osoba[1];


do
{
p=menu();

switch(p)
{
 case 1:
 {
  DodajOsobe(t1,n-1);
  KopiujTablice(t1,t2,n);
  delete[] t1;
  n++;
  t1=new osoba[n];
  KopiujTablice(t2,t1,n-1);
  delete[] t2;
  t2=new osoba[n];      
  break;
 }
 

 
  case 2:
 {
 for(int i=0;i<n-1;i++)
 WyswietlOsobe(t1,i);
 cout<<"\n******************************\n\n";
  break;
 }
 
 case 3:
 {
 licz=0;
 cout<<"\nPodaj id osoby do wyswietlenia: ";
 cin>>id;
 for(int j=0;j<n-1;j++)
 {
 if(id==t1[j].id) {WyswietlOsobe(t1,j);licz++;}
 }
 if(licz==0){cout<<"\nNie ma osoby o podanym id";}
  cout<<"\n******************************\n\n";
 
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
cout<<"\n2 - Wyswietl dane";
cout<<"\n3 - Znajdz po id";
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
void DodajOsobe(osoba t[],int nr)
{
cout<<"Podaj id: ";
cin>>t[nr].id;
cout<<"Podaj imie: ";
cin>>t[nr].imie;
cout<<"Podaj nazwisko: ";
cin>>t[nr].nazwisko;
cout<<"Podaj date: ";
cin>>t[nr].data;
}

void WyswietlOsobe(osoba t[],int nr)
{
cout<<"\n******************************";
cout<<"\nId: "<<t[nr].id;
cout<<"\nImie: "<<t[nr].imie;
cout<<"\nNazwisko: "<<t[nr].nazwisko;
cout<<"\nData: "<<t[nr].data;

}

void KopiujTablice(osoba t1[],osoba t2[],int n)
{
for(int i=0;i<n;i++)
    {
    t2[i].id=t1[i].id;
    strcpy(t2[i].imie,t1[i].imie);
    strcpy(t2[i].nazwisko,t1[i].nazwisko);
    t2[i].data=t1[i].data;
    }
                      
}

//**************************pozostale funkcje***********************************

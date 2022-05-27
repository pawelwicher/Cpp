#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


struct osoba
{
       int id;
       char imie[10];
       char nazwisko[10];
       int data;
};


int menu();
void DodajOsobe(osoba [],int);
void WyswietlOsobe(osoba [],int);
void ZapiszBaze(FILE*,int,osoba []);
void OdczytajN(FILE*,int&);
void OdczytajBaze(FILE*,int&,osoba []);



//****************************funkcja main**************************************
int main()
{
osoba tab[100];
int p,id,licz;
int n=0;
FILE *plik;


OdczytajBaze(plik,n,tab);


do
{
p=menu();

switch(p)
{
 case 1:
 {
  DodajOsobe(tab,n);
  n++;
  ZapiszBaze(plik,n,tab);      
  break;
 }
 

 
  case 2:
 {
  cout<<"******************************";
  for(int i=0;i<n;i++)
  WyswietlOsobe(tab,i);
  cout<<"\n";  
  system("pause");
  system("cls");
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
cout<<"Wybierz jedna z opcji:";
cout<<"\n1 - Dodaj osobe";
cout<<"\n2 - Wyswietl dane";
cout<<"\n0 - Zakoncz program\n\n->";

do
{
 cin>>odp;
}
while(odp<0 || odp>2);
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
cout<<"\nId: "<<t[nr].id;
cout<<"\nImie: "<<t[nr].imie;
cout<<"\nNazwisko: "<<t[nr].nazwisko;
cout<<"\nData: "<<t[nr].data;
cout<<"\n******************************";
}



void ZapiszBaze(FILE *f,int liczbaRekordow, osoba t[])
{
    f=fopen("baza.txt","wb");         
    for(int i=0;i<liczbaRekordow;i++)
        fwrite(&t[i],sizeof(osoba),1,f);
    fclose(f);
    cout<<"Dane zapisane\n";
    system("pause");
    system("cls");        
}

void OdczytajBaze(FILE *f,int &n,osoba t[])
{
    f=fopen("baza.txt","rb");     
                                  
    while(!feof(f))      
    {        
        fread(&t[n],sizeof(osoba),1,f);
        if(feof(f))
            break;
        n++;
    }
    fclose(f); 
    cout<<"Dane odczytane\n";
    system("pause");
    system("cls");    
}


//**************************pozostale funkcje***********************************

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;


struct Lista2k
{
int liczba;
Lista2k* nast;
Lista2k* pop;
};


typedef Lista2k *wsk;


void Dolacz(wsk&,wsk&);
void NaKoncu(wsk&,wsk&,wsk);
void Przegladaj(wsk);
void Usun(wsk&,wsk&,wsk);
void Funkcja(wsk&,wsk&,wsk);
void Funkcja2(wsk&,wsk&);
void menu();



int main()
{
wsk P1=NULL,P2=NULL,K1=NULL,K2=NULL; //P1 - poczatek pierwszej listy, K1 - koniec pierwszej listy, itd...    

char z;
menu();
    while(z!='0')
    {
    cout<<"\n\n->";
    z=getche();
    system("cls");
        switch(z)
        {
        case '1':
        Dolacz(P1,K1); break;
        case '2':
        Dolacz(P2,K2); break;
        case '3':
        cout<<"Pierwsza lista: "; Przegladaj(P1);
        cout<<"\nDruga lista: "; Przegladaj(P2);
        getch(); break;
        case '4':
        Funkcja(P1,K1,P2); cout<<"Zrobione"; getch(); break;
        case '5':
        Funkcja2(P1,K1); cout<<"Zrobione"; getch(); break;
        }
    menu();
    }
}




void Dolacz(wsk &Pocz,wsk &Kon)
{
wsk E=new Lista2k;
cout<<"Podaj liczbe: "; cin>>E->liczba;
NaKoncu(Pocz,Kon,E);
}


void NaKoncu(wsk &Pocz,wsk &Kon,wsk E)
{
    E->nast=NULL;
    if(Pocz==NULL)
    {
    Pocz=E;
    E->pop=NULL;
    }
    else
    {
    E->pop=Kon;
    Kon->nast=E;
    }
    Kon=E;
}

void Przegladaj(wsk Pocz)
{
wsk E=Pocz;
    while(E!=NULL)
    { 
    cout<<E->liczba<<" ";
    E=E->nast;
    }
}

void Usun(wsk &Pocz,wsk &Kon,wsk E)
{
    if(E!=NULL)
    {
        if(E->pop==NULL) Pocz=E->nast;
        else E->pop->nast=E->nast;
        if(E->nast==NULL) Kon=E->pop;
        else E->nast->pop=E->pop;
    delete(E);    
    }
}

void Funkcja(wsk &Pocz1,wsk &Kon1,wsk Pocz2)
{
wsk E1=Pocz1;
wsk E2=Pocz2;
wsk TMP=NULL;   
/* funkcja usuwa z listy pierwszej elementy o takich 
wartsciach pola liczba, ktore wystepuja w liscie drugiej*/

    while(E2!=NULL)
    { 
    E1=Pocz1;
        while(E1!=NULL)
        {
        if(E1->liczba==E2->liczba) {TMP=E1; E1=E1->nast; Usun(Pocz1,Kon1,TMP);}
        else E1=E1->nast;             
        }    
    E2=E2->nast;
    }
}

void Funkcja2(wsk &Pocz,wsk &Kon)
{
wsk E=Pocz;
wsk TMP=NULL;
int p=0;    
/* funkcja co drugi element z listy*/

    while(E!=NULL)
    { 
    if(p==0){p=1; E=E->nast;}
    else {TMP=E; E=E->nast; Usun(Pocz,Kon,TMP); p=0;}
    
    }
}


void menu()
{
system("cls");
cout<<"Wybierz jedna z dostepnych opcji:\n";
cout<<"\n[1] - Dodaj do pierwszej listy";
cout<<"\n[2] - Dodaj do drugiej listy";
cout<<"\n[3] - Wyswietl obie listy";
cout<<"\n[4] - 1 Funkcja z kola :)";
cout<<"\n[5] - 2 Funkcja z kola :)";
cout<<"\n[0] - Koniec";     
}

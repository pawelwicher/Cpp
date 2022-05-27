#include "rekord.h"

void Wpisz_typ(ksiazka *wsk)
{
int p;
cout<<"Typ (n-naukowa, b-beletrystyka, c-czasopismo, s-slownik, p-poradnik): ";

    do
    {
        p=0;
        switch(getche())
        {
        case 'n':
        wsk->typ=naukowa;                    
        break;
        case 'b':
        wsk->typ=beletrystyka;               
        break;
        case 'c':
        wsk->typ=czasopismo;                 
        break;
        case 's':
        wsk->typ=slownik;                    
        break;
        case 'p':
        wsk->typ=poradnik;                   
        break;
        default:
        { 
        cout<<"\nPodaj znak ze zbioru ['n','b','c','s','p']: ";
        p=1;
        }
        }
    
    }
    while(p);
}

void Wyswietl_typ(ksiazka *wsk)
{
cout<<"\nTyp ksiazki: ";
switch (wsk->typ)
{
case naukowa:
cout<<"naukowa";
break;
case beletrystyka:
cout<<"beletrystyka";
break;
case czasopismo:
cout<<"czasopismo";
break;
case slownik:
cout<<"slownik";
break;
case poradnik:
cout<<"poradnik";
break;
}
}

int Przestepny(int r)
{
return ((r%400==0)||((r%4==0)&&(r%100!=0)));
}

int IleDni(int m,int r)
{
switch(m)
{
case 4: case 6: case 9: case 11:
return 30;

case 2:
if(Przestepny(r)) return 29;
else return 28;

default: return 31;
}
}

void DodajDzien(int &d,int &m,int &r)
{
d++;
if(d>IleDni(m,r))
{
d=1;m++;

if(m>12)
{m=1;r++;}
}
}

void Oblicz_date(ksiazka *wsk)
{
wsk->data_zwrotu.d=14;
wsk->data_zwrotu.m=3;
wsk->data_zwrotu.r=2007;

for(int i=0;i<31;i++)
DodajDzien(wsk->data_zwrotu.d,wsk->data_zwrotu.m,wsk->data_zwrotu.r);
}


void Wypelnij(ksiazka *wsk)
{ 
cout<<"Wprowadzanie danych rekordu";

cout<<"\nId: ";
cin>>wsk->id;

cout<<"Tytul: "<<flush;
fflush(stdin);
gets(wsk->tytul);

cout<<"Autor: ";
gets(wsk->autor);

Wpisz_typ(wsk);

cout<<"\nCzy pozycja dostepna? [T/N]: ";
wsk->dostepna=toupper(getche())=='T'?1:0;;
if(!wsk->dostepna) {cout<<"\nPodaj id czytelnika: "; cin>>wsk->id_czytelnika; Oblicz_date(wsk);}
else {wsk->data_zwrotu.d=0;wsk->data_zwrotu.m=0;wsk->data_zwrotu.r=0;cout<<"\n";}

cout<<"Liczba wypozyczen: ";
cin>>wsk->liczba_wypozyczen;

getch();
}

void Wyswietl(ksiazka *wsk)
{
cout<<"\nId: "<<wsk->id;
cout<<"\nTytul: "<<wsk->tytul;
cout<<"\nAutor: "<<wsk->autor;
Wyswietl_typ(wsk);
if(wsk->dostepna) cout<<"\nPozycja dostepna";
else
{ 
cout<<"\nPozycja wypozyczona, id czytelnika: "<<wsk->id_czytelnika;
cout<<"\nData zwrotu: "<<wsk->data_zwrotu.d<<"/"
<<wsk->data_zwrotu.m<<"/"<<wsk->data_zwrotu.r<<"r.";
}
cout<<"\nLiczba wypozyczen: "<<wsk->liczba_wypozyczen;
}



void Aktualizuj_rekord(ksiazka *wsk)
{
char zn;
int p;
cout<<"\n\nWybierz pole do aktualizacji ['i','t','a','p','d','l']: ";
    do
    {
        p=0;
        switch(getche())
        {
        case 'i':
        zn='i';                    
        break;
        case 't':
        zn='t';                     
        break;
        case 'a':
        zn='a';              
        break;
        case 'p':
        zn='p';                    
        break;
        case 'd':
        zn='d';                    
        break;
        case 'l':
        zn='l';                    
        break;
        default:
        { 
        cout<<"\nPodaj znak ze zbioru ['i','t','a','p','d','l']: ";
        p=1;
        }
        }
        
    }while(p);

    cout<<"\n\nPodaj dane poprawianego pola\n";
    
    switch (zn)
    {
    case 'i':
    cout<<"\nId: ";cin>>wsk->id;
    break;
    case 't':
    cout<<"\nTytul: "<<flush;
    fflush(stdin);
    gets(wsk->tytul);
    break;
    case 'a':
    cout<<"\nAutor: "<<flush;
    fflush(stdin);
    gets(wsk->autor);
    break;
    case 'p':
    Wpisz_typ(wsk);
    break;
    case 'd':
    cout<<"\nCzy pozycja dostepna? [T/N]: ";
    wsk->dostepna=toupper(getche())=='T'?1:0;
    if(!wsk->dostepna)
    {
    cout<<"\nPodaj id czytelnika: ";
    cin>>wsk->id_czytelnika;
    Oblicz_date(wsk);
    }
    break;
    case 'l':
    cout<<"\nLiczba wypozyczen: ";
    cin>>wsk->liczba_wypozyczen;
    break;
    }
}

int Porownanie(char *napis1,char *napis2)
{
if(strstr(napis1,napis2)==NULL) return 0; else return 1;
}


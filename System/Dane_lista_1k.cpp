#include "Dane_lista_1k.h"

void Wypelnij(Pracownik &dane,int klucz)
{
dane.id=klucz;

cout<<"Imie: "<<flush;
fflush(stdin);
gets(dane.imie);

cout<<"Nazwisko: ";
gets(dane.nazwisko);

WpiszTytul(dane);
WpiszWydzial(dane);
}

void Wyswietl(Pracownik dane)
{
cout<<"ID:";
cout<<dane.id<<", ";
WyswietlTytul(dane);
cout<<" "<<dane.imie<<" "<<dane.nazwisko;
cout<<", wydzial ";
WyswietlWydzial(dane);
cout<<"\n";
}

void WyswietlTytul(Pracownik dane)
{
    switch(dane.tytul)
    {
    case mgr:
    cout<<"mgr"; break;
    case dr:
    cout<<"dr";  break;
    case prof:
    cout<<"prof";break;
    }
}

void WpiszTytul(Pracownik &dane)
{
int i,blad;
cout<<"Tytul naukowy: [m]-mgr, [d]-dr, [p]-prof\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case 'm':
        dane.tytul=mgr; break;
        case 'd':
        dane.tytul=dr;  break;
        case 'p':
        dane.tytul=prof;break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Tytul naukowy: [m]-mgr, [d]-dr, [p]-prof\n";
        blad=1;
        }
        }
    }while(blad);
}

void WyswietlWydzial(Pracownik dane)
{
    switch(dane.wydzial)
    {
    case ZI:
    cout<<"ZI"; break;
    case GN:
    cout<<"GN";  break;
    case IE:
    cout<<"IE";break;
    }
}

void WpiszWydzial(Pracownik &dane)
{
int i,blad;
cout<<"\nWydzial: [z]-ZI, [g]-GN, [i]-IE\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case 'z':
        dane.wydzial=ZI; break;
        case 'g':
        dane.wydzial=GN;  break;
        case 'i':
        dane.wydzial=IE;break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Wydzial: [z]-ZI, [g]-GN, [i]-IE\n";
        blad=1;
        }
        }
    }while(blad);
}


void AktualizujPracownika(Pracownik &dane)
{
char zn;
int p;
cout<<"\n\nWybierz pole do aktualizacji: ";
cout<<"\n[i] - imie";
cout<<"\n[n] - nazwisko";
cout<<"\n[t] - tytul";
cout<<"\n[w] - wydzial\n";
    do
    {
        p=0;
        switch(getche())
        {
            case 'i':
            zn='i';                    
            break;
            case 'n':
            zn='n';                     
            break;
            case 't':
            zn='t';              
            break;
            case 'w':
            zn='w';                    
            break;
            default:
            { 
            cout<<"\nPodaj znak ze zbioru ['i','n','t','w']: ";
            p=1;
            }
        }
        
    }while(p);

    cout<<"\nPodaj dane poprawianego pola\n";
    
    switch (zn)
    {
    case 'i':
    cout<<"\nImie: "<<flush;
    fflush(stdin);
    gets(dane.imie);
    break;
    case 'n':
    cout<<"\nNazwisko: "<<flush;
    fflush(stdin);
    gets(dane.nazwisko);
    break;
    case 't':
    WpiszTytul(dane);
    break;
    case 'w':
    WpiszWydzial(dane);
    break;
    }
}

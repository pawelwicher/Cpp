#include "Dane_lista_2k.h"

void Wypelnij(Student &dane,int klucz)
{
dane.indeks=klucz;

cout<<"Imie: "<<flush;
fflush(stdin);
gets(dane.imie);

cout<<"Nazwisko: ";
gets(dane.nazwisko);

WpiszKierunek(dane);
WpiszRok(dane);
}

void Wyswietl(Student dane)
{
cout<<dane.imie<<" "<<dane.nazwisko<<", "<<dane.indeks;
cout<<", ";
WyswietlRok(dane);
cout<<" ";
WyswietlKierunek(dane);
cout<<"\n";
}

void WyswietlKierunek(Student dane)
{
    switch(dane.kierunek)
    {
    case FiB:
    cout<<"FiB"; break;
    case IiE:
    cout<<"IiE"; break;
    case ZiM:
    cout<<"ZiM"; break;
    }
}

void WpiszKierunek(Student &dane)
{
int i,blad;
cout<<"Kierunek studiow: [f]-FiB, [i]-IiE, [z]-ZiM\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case 'f':
        dane.kierunek=FiB; break;
        case 'i':
        dane.kierunek=IiE; break;
        case 'z':
        dane.kierunek=ZiM; break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Kierunek studiow: [f]-FiB, [i]-IiE, [z]-ZiM\n";
        blad=1;
        }
        }
    }while(blad);
}

void WyswietlRok(Student dane)
{
    switch(dane.rok)
    {
    case I:
    cout<<"I"; break;
    case II:
    cout<<"II";  break;
    case III:
    cout<<"III";break;
    case IV:
    cout<<"IV";break;
    case V:
    cout<<"V";break;
    }
}

void WpiszRok(Student &dane)
{
int i,blad;
cout<<"\nRok studiow: [1]-I, [2]-II, [3]-III, [4]-IV, [5]-V\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case '1':
        dane.rok=I;   break;
        case '2':
        dane.rok=II;  break;
        case '3':
        dane.rok=III; break;
        case '4':
        dane.rok=IV;  break;
        case '5':
        dane.rok=V;   break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Rok studiow: [1]-I, [2]-II, [3]-III, [4]-IV, [5]-V\n";
        blad=1;
        }
        }
    }while(blad);
}


void AktualizujStudenta(Student &dane)
{
char zn;
int p;
cout<<"\n\nWybierz pole do aktualizacji: ";
cout<<"\n[i] - imie";
cout<<"\n[n] - nazwisko";
cout<<"\n[k] - kierunek";
cout<<"\n[r] - rok studiow\n";
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
            case 'k':
            zn='k';              
            break;
            case 'r':
            zn='r';                    
            break;
            default:
            { 
            cout<<"\nPodaj znak ze zbioru ['i','n','k','r']: ";
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
    case 'k':
    WpiszKierunek(dane);
    break;
    case 'r':
    WpiszRok(dane);
    break;
    }
}

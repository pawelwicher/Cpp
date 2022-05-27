#include "Dane_lista_1kc.h"

void Wypelnij(Kurs &dane,int klucz)
{
dane.id=klucz;
cout<<"Kod kursu: "<<flush;
fflush(stdin);
gets(dane.kod);
cout<<"Nazwa kursu: "<<flush;
fflush(stdin);
gets(dane.nazwa);
WpiszKierunek(dane);
WpiszRok(dane);
WpiszTyp(dane);
WpiszDzien(dane);
cout<<"\nPoczatek zajec [g m]: "; cin>>dane.poczatek.godzina>>dane.poczatek.minuta;
cout<<"Koniec zajec [g m]: "; cin>>dane.koniec.godzina>>dane.koniec.minuta;
cout<<"Sala: "<<flush;
fflush(stdin);
gets(dane.sala);
cout<<"Liczba miejsc: "; cin>>dane.liczba_miejsc;
dane.id_pracownika=0;
}

void Wyswietl(Kurs dane)
{
wL1k Pocz=NULL;
cout<<"\nId: "<<dane.id;
cout<<", "<<dane.kod<<", "<<dane.nazwa<<", ";
WyswietlTyp(dane);
cout<<", ";
WyswietlKierunek(dane);
cout<<" ";
WyswietlRok(dane);
cout<<"\n";
WyswietlDzien(dane);
cout<<", "<<dane.poczatek.godzina<<":"<<dane.poczatek.minuta<<"-"<<dane.koniec.godzina<<":"<<dane.koniec.minuta;
cout<<", "<<dane.sala;
cout<<"\nLiczba miejsc: "<<dane.liczba_miejsc;
cout<<", Prowadzacy: ";
if(!dane.id_pracownika) cout<<"nie przypisany\n";
}

void Wyswietl2(Kurs dane)
{
wL1k Pocz=NULL;
cout<<"\n\nId: "<<dane.id;
cout<<", "<<dane.kod<<", "<<dane.nazwa<<", ";
WyswietlTyp(dane);
cout<<", ";
WyswietlKierunek(dane);
cout<<" ";
WyswietlRok(dane);
cout<<"\n";
WyswietlDzien(dane);
cout<<", "<<dane.poczatek.godzina<<":"<<dane.poczatek.minuta<<"-"<<dane.koniec.godzina<<":"<<dane.koniec.minuta;
cout<<", "<<dane.sala;
cout<<"\nLiczba miejsc: "<<dane.liczba_miejsc;
}

void WyswietlKierunek(Kurs dane)
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

void WpiszKierunek(Kurs &dane)
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

void WyswietlRok(Kurs dane)
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

void WpiszRok(Kurs &dane)
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


void WyswietlTyp(Kurs dane)
{
    switch(dane.typ)
    {
    case cw:
    cout<<"cw"; break;
    case w:
    cout<<"w";  break;
    case l:
    cout<<"l";  break;
    }
}

void WpiszTyp(Kurs &dane)
{
int i,blad;
cout<<"\nTyp zajec: [1]-cw, [2]-w, [3]-l\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case '1':
        dane.typ=cw;   break;
        case '2':
        dane.typ=w;  break;
        case '3':
        dane.typ=l; break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Typ zajec: [1]-cw, [2]-w, [3]-l\n";
        blad=1;
        }
        }
    }while(blad);
}


void WyswietlDzien(Kurs dane)
{
    switch(dane.dzien)
    {
    case pon:
    cout<<"poniedzialek"; break;
    case wt:
    cout<<"wtorek";  			break;
    case sr:
    cout<<"sroda";  			break;
    case czw:
    cout<<"czwartek";  		break;
    case pt:
    cout<<"piatek";  			break;
    }
}

void WpiszDzien(Kurs &dane)
{
int i,blad;
cout<<"\nDzien tygodnia: [1]-pon, [2]-wt, [3]-sr, [4]-czw, [5]-pt\n";
    do
    {
    blad=0;
        switch (getche())
        {
        case '1':
        dane.dzien=pon; break;
        case '2':
        dane.dzien=wt;  break;
        case '3':
        dane.dzien=sr;  break;
        case '4':
        dane.dzien=czw; break;
        case '5':
        dane.dzien=pt;  break;
        default:
        {
        cout<<"\nBlad - wybierz jeszcze raz. Dzien tygodnia: [1]-pon, [2]-wt, [3]-sr, [4]-czw, [5]-pt\n";
        blad=1;
        }
        }
    }while(blad);
}


int PorownajGodziny(Kurs dane,int g1,int m1,int g2,int m2)
{
if(dane.poczatek.godzina*60+dane.poczatek.minuta>=g1*60+m1 && dane.poczatek.godzina*60+dane.poczatek.minuta<=g2*60+m2)
return 0;
else if(dane.koniec.godzina*60+dane.koniec.minuta>=g1*60+m1 && dane.koniec.godzina*60+dane.koniec.minuta<=g2*60+m2)
return 0;
else
return 1;
}

void AktualizujKurs(Kurs &dane)
{
char zn;
int p;
cout<<"\n\nWybierz pole do aktualizacji: ";
cout<<"\n[p] - kod";
cout<<"\n[n] - nazwa";
cout<<"\n[k] - kierunek";
cout<<"\n[r] - rok studiow";
cout<<"\n[t] - typ";
cout<<"\n[d] - dzien";
cout<<"\n[g] - godziny";
cout<<"\n[s] - sala";
cout<<"\n[l] - liczba miejsc\n";
    do
    {
        p=0;
        switch(getche())
        {
            case 'p':
            zn='p';                    
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
            case 't':
            zn='t';                    
            break;
            case 'd':
            zn='d';                    
            break;
            case 'g':
            zn='g';                    
            break;
            case 's':
            zn='s';                    
            break;
            case 'l':
            zn='l';                    
            break;
            default:
            { 
            cout<<"\nPodaj znak ze zbioru ['p','n','k','r','t','d','g','s','l']: ";
            p=1;
            }
        }
        
    }while(p);

    cout<<"\nPodaj dane poprawianego pola\n";
    
    switch (zn)
    {
    case 'p':
    cout<<"\nKod: "<<flush;
    fflush(stdin);
    gets(dane.kod);
    break;
    case 'n':
    cout<<"\nNazwa: "<<flush;
    fflush(stdin);
    gets(dane.nazwa);
    break;
    case 'k':
    WpiszKierunek(dane);
    break;
    case 'r':
    WpiszRok(dane);
    break;
    case 't':
    WpiszTyp(dane);
    break;
    case 'd':
    WpiszDzien(dane);
    break;
    case 'g':
    cout<<"Poczatek zajec [g m]: "; cin>>dane.poczatek.godzina>>dane.poczatek.minuta;
    cout<<"Koniec zajec [g m]: "; cin>>dane.koniec.godzina>>dane.koniec.minuta;
    break;
    case 's':
    cout<<"Sala: "<<flush;
    fflush(stdin);
    gets(dane.sala);
    break;
    case 'l':
    cout<<"Liczba miejsc: "; cin>>dane.liczba_miejsc;
    break;
    }
}

void PrzypiszPracownika(Kurs &dane,int klucz)
{
dane.id_pracownika=klucz;
cout<<"\nKurs przypisany";
}

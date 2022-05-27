#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


enum Rodzaj {beletrystyka, naukowa, podroznicza, slownik, inna};

struct Data
{ 
    int d;
    int m;
    int r;
};

struct ksiazka
{
    char tytul[30];
    char autor[20];
    int numer;
    Rodzaj rodzaj;
    int status;
    char czytelnik[20];
    Data dataZwr;
    int liczbaWypozyczen;
};


char menu();                                     //prototypy uzytych funkcji
void DodajPozycje(ksiazka [],int);
void AktualizujPozycje(ksiazka [],int);
void WyswietlPozycje(ksiazka [],int);
void UsunPozycje(ksiazka [],int,int&);
void Wpisz(char [],int);
Rodzaj WypelnijRodzaj();
void PokazRodzaj(int);
void ZapiszBaze(FILE*,int,ksiazka []);
void OdczytajBaze(FILE*,int&,ksiazka []);
int TakNie();
int SzukajTekstu(char [],char[]);

//******************************************************************************
int main()
{
int const MAX=10;  //maksymalna pojemnosc bazy                                                              
ksiazka t[MAX];
char p,q,r;    //znaki, ktore wczytuje za pomoca getch() w roznych przypadkach
int n=0;       //liczba rekordow w bazie
int nrUsun;    //numer rekordu do usuniecia
int nrAkt;     //numer rekordu do aktualizacji
int k,licznik;
FILE *plik;
char tytul[30],autor[20];      //napisy potrzebne przy wyszukiwaniu


OdczytajBaze(plik,n,t);        //wczytywanie do tablicy "t" rekordow zapisanych w pliku oraz ustalenie liczby rekordow
    do
    {
    p=menu();                  //p - wartosc zalezy od wyboru uzytkownika w menu glownym programu
        switch(p)
        {
            case '1':
            {
                if(n<MAX)                  //ograniczenie pojemnosci bazy
                {
                    DodajPozycje(t,n);
                    n++;                   //licznik liczby rekordow, po dodaniu rekordu zwiekszony
                    ZapiszBaze(plik,n,t);
                }
                else
                {
                    cout<<"Baza pelna. Nie mozna dodac rekordu\n";
                    system("pause");
                    system("cls");  
                } 
                break;
            }
             
            case '2':               //Przewijana lista pozycji
            {
                k=0;
                do
                {
                WyswietlPozycje(t,k);
                cout<<"******************************";
                cout<<"\n1 - poprzedni\n2 - nastepny\n0 - koniec przegladania\n\n->";
                q=getche();
                    if(q=='1')
                    {
                        if(k==0) k=n-1;
                        else k--;
                    }
                    if(q=='2')
                    {
                        if(k==n-1) k=0;
                        else k++;
                    }                                
                system("cls");
                }
                while(q!='0'); 
                break;
            }
            
            case '3':          //usuniecie rekordu o numerze nrUsun
            {
                cout<<"Podaj nr rekordu do usuniecia: ";
                cin>>nrUsun;
                    if(nrUsun<=n && nrUsun>0)         //sprawdzenie czy istnieje taki rekord
                    {
                        system("cls");
                        UsunPozycje(t,nrUsun-1,n);            //mamy tu -1 bo tablice sa indeksowane od 0
                        ZapiszBaze(plik,n,t);
                    }
                    else
                    {
                        cout<<"Nie ma takiego rekordu\n";
                        system("pause");
                        system("cls");
                    } 
                break;
            }
            
            case '4':
            {
            cout<<"Podaj numer rekordu do aktualizacji: ";
            cin>>nrAkt;
                if(nrAkt<=n && nrAkt>0)                 //sprawdzenie czy istnieje taki rekord
                {
                    system("cls");
                    AktualizujPozycje(t,nrAkt-1);
                    ZapiszBaze(plik,n,t);
                }
                else
                {
                    cout<<"Nie ma takiego rekordu\n";
                    system("pause");
                    system("cls");
                }
            break;
            }
            
            case '5':
            {
            licznik=0;
            cout<<"Wybierz pole, po ktorym chcesz szukac:\n1 - tytul\n2 - autor\n";
            do
            {
                r=getche();
                if(r!='1' && r!='2') 
                    cout<<"\nWybierz 1 lub 2 ";
                else
                    break;
            }
            while(1);
            system("cls");
            if(r=='1')
            {
            cout<<"Wyszukiwanie wg pola 'tytul'\n->";
            Wpisz(tytul,30);
                for(int i=0;i<n;i++)
                {
                    if(SzukajTekstu(t[i].tytul,tytul))
                    {
                        WyswietlPozycje(t,i);         //gdy pole rekordu zawiera szukana wartosc to wyswietla rekord
                        licznik++;
                    }
                }
            }
            if(r=='2')
            {
            cout<<"Wyszukiwanie wg pola 'autor'\n->";
            Wpisz(autor,30);
                for(int i=0;i<n;i++)
                {
                    if(SzukajTekstu(t[i].autor,autor))
                    {
                        WyswietlPozycje(t,i);
                        licznik++;
                    }
                }
            }
            cout<<"******************************\n"<<"Liczba znalezionych pozycji: "<<licznik<<"\n";
            system("pause");
            system("cls");
            break;
            }
        }
    
    }
    while(p!='0');    //dopoki nie nacisnieto klawisza 0
}
//******************************************************************************
char menu()           //menu glowne
{
char odp;

cout<<"1 - Dodaj rekord";
cout<<"\n2 - Przegladaj baze";
cout<<"\n3 - Usun rekord";
cout<<"\n4 - Aktualizuj rekord";
cout<<"\n5 - Wyszukaj rekord";
cout<<"\n0 - Zakoncz program\n\n->";

    do
    {
    odp=getche();
    }
    while(odp<'0' || odp>'5');
system("cls");
return odp;
}
//******************************************************************************
void DodajPozycje(ksiazka t[],int nr)
{
char odp;

t[nr].numer=nr+1;
fflush(stdin);   //czyszczenie bufora
cout<<"Podaj tytul: ";
Wpisz(t[nr].tytul,30);         //uzylem wlasnej funkcji do wczytywanie napisow (wczytuje znaki po spacji)
cout<<"Podaj autora: ";        //wczytywanie wszystkich skladowych struktury
Wpisz(t[nr].autor,20);
cout<<"Podaj kategorie (wybierz jedna z dostepnych opcji)";
cout<<"\nb - beletystyka\nn - naukowa\np - podroznicza\ns - slownik\ni - inna\n";
t[nr].rodzaj=WypelnijRodzaj();           //wypelnienie pola typu enum za pomoca odpowiedniej funkcji
cout<<"\nCzy pozycja dostepna? [t/n]: ";
    do
    {
    odp=getche();
    if(odp!='t' && odp!='n') 
        cout<<"[t/n]? ";
    else
        break;
    }
    while(1);
fflush(stdin);
    if(odp=='n')      //gdy ksiazka niedostepna
    {
        t[nr].status=1;
        cout<<"\nPodaj dane czytelnika: ";
        Wpisz(t[nr].czytelnik,20);
        cout<<"Podaj date zwrotu (kolejno: d,m,r):\n";
        cin>>t[nr].dataZwr.d>>t[nr].dataZwr.m>>t[nr].dataZwr.r;
    }
    else              //gdy dostepna
    {
        t[nr].status=0;
        strcpy(t[nr].czytelnik,"n/d");
        t[nr].dataZwr.d=0;
        t[nr].dataZwr.m=0;
        t[nr].dataZwr.r=0;
    }
cout<<"\nPodaj liczbe wypozyczen: ";
cin>>t[nr].liczbaWypozyczen;
system("cls");  
}
//******************************************************************************
void AktualizujPozycje(ksiazka t[],int nr)
{
char odp;

fflush(stdin);   //czyszczenie bufora

cout<<"Tytul: "<<t[nr].tytul;
if(TakNie())                   //TakNie odpowiada pytaniu czy chcesz zmienic zawartosc pola czy zostawic stara
{
cout<<"\nNowa warotsc: ";
Wpisz(t[nr].tytul,30);         //uzylem wlasnej funkcji do wczytywanie napisow (wczytuje znaki po spacji)
}

cout<<"\nAutor: "<<t[nr].autor;       //wczytywanie wszystkich skladowych struktury
if(TakNie()) 
{
cout<<"\nNowa warotsc: ";
Wpisz(t[nr].autor,20);         
}

cout<<"\nKategoria: ";
PokazRodzaj(t[nr].rodzaj);
if(TakNie()) 
{
cout<<"\nNowa kategoria (wybierz jedna z dostepnych opcji)";
cout<<"\nb - beletystyka\nn - naukowa\np - podroznicza\ns - slownik\ni - inna\n";
t[nr].rodzaj=WypelnijRodzaj();           //wypelnienie pola typu enum za pomoca odpowiedniej funkcji
}

if(!t[nr].status) cout<<"\nStatus: dostepna";
else cout<<"\nStatus: wypozyczona";
if(TakNie()) 
{
cout<<"\nCzy pozycja dostepna? [t/n]: ";
    do
    {
    odp=getche();
    if(odp!='t' && odp!='n') 
        cout<<"[t/n]? ";
    else
        break;
    }
    while(1);
fflush(stdin);
    if(odp=='n')      //gdy ksiazka niedostepna
    {
        t[nr].status=1;
        cout<<"\nCzytelnik: "<<t[nr].czytelnik;
        if(TakNie()) 
        {
        cout<<"\nNowa warotsc: ";
        Wpisz(t[nr].czytelnik,20);        
        }
        
        cout<<"\nData zwrotu: "<<t[nr].dataZwr.d<<"-"<<t[nr].dataZwr.m<<"-"<<t[nr].dataZwr.r;
        if(TakNie()) 
        {
        cout<<"\nNowa wartosc (kolejno: d,m,r)\n";
        cin>>t[nr].dataZwr.d>>t[nr].dataZwr.m>>t[nr].dataZwr.r;       
        }



    }
    else              //gdy dostepna
    {
        t[nr].status=0;
        strcpy(t[nr].czytelnik,"n/d");
        t[nr].dataZwr.d=0;
        t[nr].dataZwr.m=0;
        t[nr].dataZwr.r=0;
    }         
}

cout<<"\nLiczba wypozyczen: "<<t[nr].liczbaWypozyczen;
if(TakNie()) 
{
cout<<"\nNowa warotsc: ";
cin>>t[nr].liczbaWypozyczen;       
}

system("cls");  
}
//******************************************************************************
void UsunPozycje(ksiazka t[],int nrRekordu,int &n)
{
for(int i=nrRekordu;i<n-1;i++)
    t[i]=t[i+1];              //wymazanie rekordu o wskazanym numerze
n--;                          //zmniejszenie liczby rekordow w bazie o 1
for(int i=0;i<=n;i++)
    t[i].numer=i+1;
}

//******************************************************************************
void WyswietlPozycje(ksiazka t[],int nr)
{
fflush(stdin);                          //wyswietlenie wszystkich skladowych struktury
cout<<"******************************";
cout<<"\nNumer: "<<t[nr].numer;
cout<<"\nTytul: "<<t[nr].tytul;
cout<<"\nAutor: "<<t[nr].autor;
cout<<"\nKategoria: ";
PokazRodzaj(t[nr].rodzaj);
if(!t[nr].status) cout<<"\nStatus: dostepna";
else cout<<"\nStatus: wypozyczona";
cout<<"\nCzytelnik: "<<t[nr].czytelnik;
cout<<"\nData zwrotu: "<<t[nr].dataZwr.d<<"-"<<t[nr].dataZwr.m<<"-"<<t[nr].dataZwr.r;
cout<<"\nLiczba wypozyczen: "<<t[nr].liczbaWypozyczen<<"\n";
}
//******************************************************************************
void ZapiszBaze(FILE *f,int liczbaRekordow, ksiazka t[])
{
    f=fopen("baza.txt","wb");               //zapisanie wszystkich rekordow bazy do pliku baza.txt
    for(int i=0;i<liczbaRekordow;i++)
        fwrite(&t[i],sizeof(ksiazka),1,f);
    fclose(f);
    cout<<"Dane zapisane\n";
    system("pause");
    system("cls");        
}
//******************************************************************************
void OdczytajBaze(FILE *f,int &n,ksiazka t[])
{
    f=fopen("baza.txt","rb");     //odczyt pliku z rekordami i wypelnienie kolejnych elementow tablicy t
                                  //odczytanymi rekordami z pliku
    while(!feof(f))     //dopoki nie napotka konca pliku  
    {        
        fread(&t[n],sizeof(ksiazka),1,f);
        if(feof(f))
            break;
        n++;
    }
    fclose(f); 
    cout<<"Dane odczytane\n";
    system("pause");
    system("cls");    
}
//******************************************************************************
void Wpisz(char t[],int n)
{
	do                  //funkcja pobiera ciag znakow (ze spacjami) o okreslonej dlugosci
	{
    gets(t);
    if(strlen(t)>n)
    cout<<"Wpis moze zawierac maksymalnie "<<n<<" znakow. Wpisz ponownie\n";
	}
    while(strlen(t)>n);
fflush(stdin);
}
//******************************************************************************
Rodzaj WypelnijRodzaj()
{
char zn;

zn=getche();
    switch (zn)
    {        
        case 'b':
        {return beletrystyka;break;}
        case 'n':
        {return naukowa;break;}
        case 'p':
        {return podroznicza;break;}    
        case 's':
        {return slownik;break;}
        default :
        {return inna;break;}
    }

}
//******************************************************************************
void PokazRodzaj(int n)
{
    switch (n)
    {        
        case 0:
        {cout<<"beletrystyka";break;}
        case 1:
        {cout<<"naukowa";break;}
        case 2:
        {cout<<"podroznicza";break;}    
        case 3:
        {cout<<"slownik";break;}
        default :
        {cout<<"inna";break;}
    }
}
//******************************************************************************
int TakNie()
{
char odp;   //funkcja - decyzja; wybor jednej z dwoch opcji, napisana zeby nie powtarzac kodu
cout<<"\nAktualizujesz ta pozycje [t/n]? ";
    do
    {
    odp=getche();
    if(odp!='t' && odp!='n') 
        cout<<"\n[t/n]? ";
    else
        break;
    }
    while(1);
    
if(odp=='t') return 1;
else return 0;
}
//******************************************************************************
int SzukajTekstu(char tekst1[],char tekst2[])
{
if((strstr(tekst1,tekst2))==NULL) return 0;  //funkcja zwraca 1 gdy pewien tekst zawiera zadany inny tekst
return 1;
}

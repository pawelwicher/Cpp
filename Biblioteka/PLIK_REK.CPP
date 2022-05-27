#include "plik_rek.h"


void Dopisz_rekord(void)
{ 
    FILE *wp;
    ksiazka buf;    
    if((wp=fopen("dane.dat","ab"))==NULL)
    {
        cout<<"\nNiemozliwe otwarcie pliku dane.dat";
        getch();
        return;
    }
    Wypelnij(&buf);
    fwrite(&buf,sizeof(buf),1,wp);
    fclose(wp);
}

void Wyswietl_rekordy(void)
{
    FILE* wp;
    int nr=0;
    ksiazka buf;
    if(Sprawdz_plik(&wp))
    {
        while(fread(&buf,sizeof(buf),1,wp)==1)
        {
            cout<<"\nRekord o numerze "<<nr++;
            Wyswietl(&buf);
            cout<<"\n";
        }
        fclose(wp);
    }
    getch();
}


int Sprawdz_plik(FILE **wp)
{
    if((*wp = fopen("dane.dat","rb"))==NULL)
    {
        cout<<"\nNie mozna otworzyc pliku dane.dat";
        getch();
        return 0;
    }
    else
    {
        fseek(*wp,0,SEEK_END);
        if(!ftell(*wp))
        {
            cout<<"\nPlik jest pusty"<<endl;
            getch();
            return 0;
        }
        else
        { 
            fseek(*wp,0,SEEK_SET);
            return 1;
        }
    }
}


void Aktualizuj()
{    
int nr;
int i=0;
int k=0;

FILE* wp;
ksiazka buf;

    if(Sprawdz_plik(&wp))
    {   
    cout<<"Podaj ID rekordu do aktualizacji: "; cin>>nr;
    
    while (fread(&buf,sizeof(buf),1,wp)==1)
    {
    i++;
    if(buf.id==nr) {Wyswietl(&buf);k=1;break;}        
    }

    if(k)
    {
    Aktualizuj_rekord(&buf);
    wp=fopen("dane.dat","r+b");
    fseek(wp,(i-1)*sizeof(ksiazka),SEEK_SET);
    fwrite(&buf, sizeof(buf),1,wp);
    fclose(wp);
    }
    else
    cout<<"\nBrak rekordu o podanym ID";
    getch();
    }
}

void Wyszukaj()
{
char zn;
int p,i=0;
FILE* wp;
ksiazka buf;
char napis[25];


cout<<"Wyszukiwanie wg pola 'tytul' lub 'autor' ['t','a']: ";
    do
    {
        p=0;
        switch(getche())
        {
            case 't':
            zn='t';                    break;
            case 'a':
            zn='a';                     break;

            default:
            { 
            cout<<"\nPodaj znak ze zbioru ['t','a']: ";
            p=1;
            }
        }    
    }
    while(p);
    
    cout<<"\n\nPodaj wartosc pola do wyszukiwania: "<<flush; fflush(stdin); gets(napis);
    
    if(Sprawdz_plik(&wp))
    {
        while (fread(&buf,sizeof(buf),1,wp)==1)
        {
            switch(zn)
            {
            case 't':
            if(Porownanie(buf.tytul,napis))
            {Wyswietl(&buf); i++;} break;
            case 'a':
            if(Porownanie(buf.autor,napis))
            {Wyswietl(&buf); i++;} break;         
            }
        }
    
    if(i) cout<<"\n\nZnaleziono "<<i<<" rekordow";
    else cout<<"\n\nNie znaleziono zadych rekordow";
    getch();                    
    }
}

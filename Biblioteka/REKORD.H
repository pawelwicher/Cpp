#ifndef rekord
#define rekord

#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

enum rodzaj_ksiazki {naukowa,beletrystyka,czasopismo,slownik,poradnik};

struct data
{
int d;
int m;
int r;
};

struct ksiazka
{
int id;
char tytul[40];
char autor[25];
rodzaj_ksiazki typ;
int dostepna;
int liczba_wypozyczen;
data data_zwrotu;
int id_czytelnika;
};

                         

void Wpisz_typ(ksiazka *wsk);
void Wyswietl_typ(ksiazka *wsk);
void Oblicz_date(ksiazka *wsk);
void Wypelnij(ksiazka *wsk);
void Wyswietl(ksiazka *wsk);
void Aktualizuj_rekord(ksiazka *wsk);
int Porownanie(char *napis1,char *napis2);
#endif

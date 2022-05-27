#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#ifndef Dane_Lista_1k
#define Dane_Lista_1k

enum Tytul{mgr,dr,prof};
enum Wydzial{ZI,GN,IE};

struct Pracownik
{
int id;
char imie[10];
char nazwisko[15];
Tytul tytul;
Wydzial wydzial;
};

void Wypelnij(Pracownik &dane,int klucz);
void Wyswietl(Pracownik dane);
void WyswietlTytul(Pracownik dane);
void WpiszTytul(Pracownik &dane);
void WyswietlWydzial(Pracownik dane);
void WpiszWydzial(Pracownik &dane);
void AktualizujPracownika(Pracownik &dane);

#endif

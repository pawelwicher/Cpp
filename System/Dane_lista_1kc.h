#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Lista_1k.h"
#include "Lista_2k.h"

#ifndef Dane_Lista_1kc
#define Dane_Lista_1kc


enum Typ{cw,w,l};
enum Dzien{pon,wt,sr,czw,pt};

struct Czas
{
int godzina;
int minuta;
};

struct Kurs
{
int id;
char kod[7];
char nazwa[20];
Kierunek kierunek;
Rok rok;
Typ typ;
Dzien dzien;
Czas poczatek,koniec;
int liczba_miejsc;
char sala[10];
int id_pracownika;
};

void Wypelnij(Kurs &dane,int klucz);
void Wyswietl(Kurs dane);
void Wyswietl2(Kurs dane);
void WyswietlKierunek(Kurs dane);
void WpiszKierunek(Kurs &dane);
void WyswietlRok(Kurs dane);
void WpiszRok(Kurs &dane);
void WyswietlTyp(Kurs dane);
void WpiszTyp(Kurs &dane);
void WyswietlDzien(Kurs dane);
void WpiszDzien(Kurs &dane);
int PorownajGodziny(Kurs dane,int g1,int m1,int g2,int m2);
void AktualizujKurs(Kurs &dane);
void PrzypiszPracownika(Kurs &dane,int klucz);

#endif

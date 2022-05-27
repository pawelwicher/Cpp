#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>
#include <windows.h>

#ifndef Slownik
#define Slownik

using namespace std;

struct S
{
char slowoPol[10];
char slowoAng[10];
};


struct Wezel
{
S slownik;
int glebokosc;
int wysokosc;
Wezel* lewy;
Wezel* prawy;
};

typedef Wezel* wsk;


void Dolacz(wsk &wb,char slowoPol[10],char slowoAng[10]);
void DolaczSlowo(wsk &wb);
void PoliczParametry(wsk wb,int &poziom);

void Zapisz(wsk wb, FILE* f);
void ZapiszDrzewo(wsk wb);
void OdczytajDrzewo(wsk &wb);

void WyswietlAlfabetycznie(wsk wb);

void PreOrder(wsk wb);
void InOrder(wsk wb);
void PostOrder(wsk wb);

wsk Szukaj(wsk wb,char slowoPol[10]);
void WyszukajSlowo(wsk wb);

int Wysokosc(wsk wb);
int LiczLiscie(wsk wb);
int LiczWezly(wsk wb);

void ParametryDrzewa(wsk wb);
void Rysuj(wsk wb,int x,int poziom);
void Wywazenie(wsk wb,int &wywazenie);
int WezlyWewnetrzne(wsk wb);
void WezlyZewnetrzne(wsk wb,int &wz);
void JedenPotomek(wsk wb,int &jp);
void WezlyNaPoziomach(wsk wb,int &poziom,int poziomy[]);

int Kwadrat(int x,int n);
int Abs(int x);
void gotoxy(int x,int y);

#endif

#include <iostream.h>
#include <conio.h>
#include <windows.h>

#ifndef PLANSZA
#define PLANSZA
const int W=25;
const int S=20;

class Plansza
{
public:
int plansza[W][S];
int kierunek;

Plansza();
void Aktualizuj_plansze(int,int,int,int,int,int[4][4],int[4][4]);
void Kasuj_linie(int);
void Sprawdz_linie();
void Rysuj_plansze();
bool Koniec_gry();
}; 
#endif

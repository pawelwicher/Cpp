#include "Plansza.h"
#include "Siatki.h"

#ifndef KLOCEK
#define KLOCEK
class Klocek
{
public:
bool ruch;
int x;
int y;
int przesuniecie;
int obrot;
int ile_siatek;
int siatka[4][4][4];

Klocek(int);
void Lewo(Plansza*);
void Prawo(Plansza*);
void Dol(Plansza*);
void Rotacja(Plansza*);
bool Kolizja_kierunku(int,int,Plansza*);
bool Kolizja_obrotu(int,int,Plansza*);
void Koniec(Plansza*);
};





#endif

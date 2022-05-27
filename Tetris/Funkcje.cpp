#include "Funkcje.h"



void Odswierz(Plansza *p,Klocek *k)
{
int ob;
if(k->obrot==0) ob=k->ile_siatek-1; else ob=k->obrot-1;
p->Aktualizuj_plansze(k->x,k->y,k->obrot,k->ile_siatek,
k->przesuniecie,k->siatka[k->obrot],k->siatka[ob]);
p->Rysuj_plansze();    
}

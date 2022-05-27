#ifndef Lista_1k
#define Lista_1k
#include "Dane_lista_1k.h"

struct Lista1k
{
Pracownik daneP;
Lista1k* nast;
};

typedef Lista1k *wL1k;

void DolaczL1k(wL1k &Pocz,wL1k &Kon);
void PrzegladajL1k(wL1k Pocz);
void PrzegladajZKluczemL1k(wL1k Pocz,int klucz);
void UsunL1k(wL1k &Pocz,wL1k &Kon,int id_pracownika);
int SprawdzKluczL1k(wL1k Pocz,int klucz);
void AktualizujL1k(wL1k Pocz);
void WyszukajL1k(wL1k Pocz);
void ZapiszL1k(wL1k Pocz);
void OdczytajL1k(wL1k &Pocz,wL1k &Kon);

#endif

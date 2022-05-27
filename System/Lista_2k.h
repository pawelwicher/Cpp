#ifndef Lista_2k
#define Lista_2k
#include "Dane_lista_2k.h"

struct Lista2k
{
Student daneS;
Lista2k* nast;
Lista2k* pop;
};

typedef Lista2k *wL2k;

void DolaczL2k(wL2k &Pocz,wL2k &Kon);
void PrzegladajL2k(wL2k Pocz);
void PrzegladajZKluczemL2k(wL2k Pocz,int klucz);
void UsunL2k(wL2k &Pocz,wL2k &Kon,int id_studenta);
int SprawdzKluczL2k(wL2k Pocz,int klucz);
void AktualizujL2k(wL2k Pocz);
void WyszukajL2k(wL2k Pocz);
void ZapiszL2k(wL2k Pocz);
void OdczytajL2k(wL2k &Pocz,wL2k &Kon);

#endif

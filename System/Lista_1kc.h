#ifndef Lista_1kc
#define Lista_1kc

#include "Dane_lista_1kc.h"
#include "lista_2kc.h"

struct Lista1kc
{
Kurs daneK;
Lista1kc* nast;
};

typedef Lista1kc *wL1kc;

wL1kc InicjujGloweL1kc();
void DolaczL1kc(wL1kc &Glowa);
void PrzegladajL1kc(wL1kc Glowa,wL1k Pocz);
void PrzegladajZKluczemL1kc(wL1kc Glowa,wL1k Pocz,int kluczK,int kluczP);
void PrzypiszPracownikaL1kc(wL1kc Glowa,wL1k Pocz);
void UsunL1kc(wL1kc &Glowa,int id_kursu);
int SprawdzKluczL1kc(wL1kc Glowa,int klucz);
void AktualizujL1kc(wL1kc Glowa,wL2kc GlowaL2kc);
void WyszukajL1kc(wL1kc Glowa);
void ZapiszL1kc(wL1kc Glowa);
void OdczytajL1kc(wL1kc &Glowa);

#endif

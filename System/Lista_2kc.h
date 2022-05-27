#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#ifndef Lista_2kc
#define Lista_2kc

struct Zapis
{
int id_kursu;
int id_studenta;
char kod[7];
};

struct Lista2kc
{
Zapis daneZ;
Lista2kc* nast;
Lista2kc* pop;
};

typedef Lista2kc *wL2kc;

wL2kc InicjujGloweL2kc();
void DolaczL2kc(wL2kc &Glowa,int id_kursu, int id_studenta,char kod[7]);
void ZapiszL2kc(wL2kc Glowa);
void OdczytajL2kc(wL2kc Glowa);
int SprawdzZapisL2kc(wL2kc Glowa,int id_kursu, int id_studenta);
int SprawdzZapisyL2kc(wL2kc Glowa,int id_kursu);
void UsunZapis(wL2kc &Glowa,int id_kursu, int id_studenta);


void Przegladaj(wL2kc Glowa);//pomocnicza

#endif

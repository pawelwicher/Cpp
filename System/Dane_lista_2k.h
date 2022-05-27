#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#ifndef Dane_Lista_2k
#define Dane_Lista_2k

enum Kierunek{FiB,IiE,ZiM};
enum Rok{I,II,III,IV,V};

struct Student
{
int indeks;
char imie[10];
char nazwisko[15];
Kierunek kierunek;
Rok rok;
};

void Wypelnij(Student &dane,int klucz);
void Wyswietl(Student dane);
void WyswietlKierunek(Student dane);
void WpiszKierunek(Student &dane);
void WyswietlRok(Student dane);
void WpiszRok(Student &dane);
void AktualizujStudenta(Student &dane);

#endif

#include "Operacje.h"
/*
Struktury:
- Pracownik (id, imie, nazwisko, tytul naukowy, wydzial) LISTA JEDNOKIERUNKOWA

- Student (nr indeksu, imie, nazwisko, kierunek, rok studiow) LISTA DWUKIERUNKOWA

- Kurs (kod kursu, nazwa, id pracownika, kierunek, rok studiow, liczba dostepnych miejsc, sala
dzien, godziny, typ - cw,w,l) LISTA JEDNOKIERUNKOWA CYKLICZNA

- Zapis (kod kursu, id studenta - powiazanie studenta z kursem) LISTA DWUKIERUNKOWA CYKLICZNA
*/


int main()
{ 
wL1k PoczL1k=NULL,KonL1k=NULL;
wL2k PoczL2k=NULL,KonL2k=NULL;
wL1kc GlowaL1kc=InicjujGloweL1kc();
wL2kc GlowaL2kc=InicjujGloweL2kc();

Zapisy(PoczL1k,PoczL2k,KonL1k,KonL2k,GlowaL1kc,GlowaL2kc);
}

#include "Klocek.h"

int los()
{return (1+rand()%7);}

int main()
{
char znak;
srand ((int) time(NULL)); 

Plansza *p=new Plansza();
Klocek *k=new Klocek(los());
p->Rysuj_plansze();
int ob;
    do 
    {
    if(p->Koniec_gry()) break;
    //Sleep(100);
    
    
    if(k->obrot==0) ob=k->ile_siatek-1; else ob=k->obrot-1;
    p->Aktualizuj_plansze(k->x,k->y,k->obrot,k->ile_siatek,
    k->przesuniecie,k->siatka[k->obrot],k->siatka[ob]);
    p->Sprawdz_linie();
    p->Rysuj_plansze();
    
    znak=getche();
        switch(znak)
        {
        case 'j':
        k->Lewo(p); break;
        case 'l':
        k->Prawo(p); break;
        case 'k':
        k->Dol(p);
        if(k->ruch==false) k=new Klocek(los());
        break;
        case 'i':
        k->Rotacja(p); break;              
        }
    
    }
    while(znak!='0');
    
system("pause");
}




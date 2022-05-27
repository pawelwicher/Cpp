#include "Klocek.h"
//******************************************************************************
Klocek::Klocek(int numer_klocka)
{
ruch=true;
    switch(numer_klocka)
    {
    case 1:       
    ile_siatek=2; Kopiuj_tablice(siatka,klocek1,ile_siatek); x=0; break;
    case 2:       
    ile_siatek=4; Kopiuj_tablice(siatka,klocek2,ile_siatek); x=1; break;
    case 3:       
    ile_siatek=4; Kopiuj_tablice(siatka,klocek3,ile_siatek); x=1; break;
    case 4:        
    ile_siatek=1; Kopiuj_tablice(siatka,klocek4,ile_siatek); x=2; break;
    case 5:        
    ile_siatek=4; Kopiuj_tablice(siatka,klocek5,ile_siatek); x=2; break;
    case 6:        
    ile_siatek=2; Kopiuj_tablice(siatka,klocek6,ile_siatek); x=2; break;
    case 7:       
    ile_siatek=2; Kopiuj_tablice(siatka,klocek7,ile_siatek); x=2; break;
    }
y=9;
obrot=0;
}
//******************************************************************************
void Klocek::Lewo(Plansza *p)
{
if(!this->Kolizja_kierunku(x,y-1,p)) {y--; p->kierunek=1;}
}
//******************************************************************************
void Klocek::Prawo(Plansza *p)
{
if(!this->Kolizja_kierunku(x,y+1,p)) {y++; p->kierunek=2;}
}
//******************************************************************************
void Klocek::Dol(Plansza *p)
{
if(this->Kolizja_kierunku(x+1,y,p)) {ruch=false; this->Koniec(p);}
else {x++; p->kierunek=3;}
}
//******************************************************************************
void Klocek::Rotacja(Plansza *p)
{
bool rotacja=true;
int k[3]={0};
int i,j,ob;

if(obrot==ile_siatek-1) ob=0; else ob=obrot+1;

k[0]=this->Kolizja_obrotu(x,y,p);
k[1]=this->Kolizja_obrotu(x,y+1,p);
k[2]=this->Kolizja_obrotu(x,y-1,p);   
      
    for(i=0;i<3;i++) if(!k[i]) break;
    
    switch(i)
    {
    case 0:
    this->przesuniecie=0; break;
    case 1:
    this->przesuniecie=1; y++; break;
    case 2:
    this->przesuniecie=-1; y--; break;
    case 3:
    rotacja=false; break;
    }

    if(rotacja)
    {
        if(obrot==ile_siatek-1) obrot=0; else obrot++;
        p->kierunek=4;
    }
}
//******************************************************************************
bool Klocek::Kolizja_kierunku(int X,int Y,Plansza *p)
{
bool kolizja=false;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            if(siatka[obrot][i][j]==1 && p->plansza[X+i][Y+j]==-1) {kolizja=true; break;}
    if(kolizja) break;
    }
return kolizja;
}
//******************************************************************************
bool Klocek::Kolizja_obrotu(int X,int Y,Plansza *p)
{
bool kolizja=false;
int ob;
    if(obrot==ile_siatek-1) ob=0; else ob=obrot+1;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            if(siatka[ob][i][j]==1 && p->plansza[X+i][Y+j]==-1) {kolizja=true; break;}
    if(kolizja) break;
    }
return kolizja;
}
//******************************************************************************
void Klocek::Koniec(Plansza *p)
{
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        if(siatka[obrot][i][j]==1) p->plansza[x+i][y+j]=-1;
}
//******************************************************************************

#include "Plansza.h"
//******************************************************************************
Plansza::Plansza()
{
for(int i=0;i<W;i++)
    for(int j=0;j<S;j++)
        if(j<3 || j>=S-3 || i>=W-3) plansza[i][j]=-1;
        else plansza[i][j]=0;
/*        
plansza[10][3]=-1;
plansza[10][4]=-1;
plansza[10][5]=-1;
plansza[10][6]=-1;
plansza[10][7]=-1;
plansza[10][8]=-1;
plansza[10][9]=-1;
plansza[10][11]=-1;
plansza[10][12]=-1;
plansza[10][13]=-1;
plansza[10][14]=-1;
plansza[10][15]=-1;
plansza[10][16]=-1;
*/
}
//******************************************************************************
void Plansza::Aktualizuj_plansze(int x,int y,int obrot,
int ile_siatek,int przesuniecie,int t[4][4],int t1[4][4])
{
int ob,i,j;

for(i=0;i<4;i++) for(j=0;j<4;j++) if(t[i][j]!=0) plansza[x+i][y+j]=t[i][j];

    switch(kierunek)
    {
    case 1:
    for(i=0;i<4;i++) for(j=3;j>=0;j--) if(t[i][j]!=0) {plansza[x+i][y+j+1]=0; break;}
    break;
    
    case 2:
    for(i=0;i<4;i++) for(j=0;j<4;j++) if(t[i][j]!=0) {plansza[x+i][y+j-1]=0; break;}
    break;
    
    case 3:
    for(i=0;i<4;i++) for(j=0;j<4;j++) if(t[j][i]!=0) {plansza[x+j-1][y+i]=0; break;}
    break;
    
    case 4:
    for(i=0;i<4;i++) for(j=0;j<4;j++) if(t1[i][j]!=0) plansza[x+i][y+j-przesuniecie]=0;
    for(i=0;i<4;i++) for(j=0;j<4;j++) if(t[i][j]!=0) plansza[x+i][y+j]=t[i][j];
    break;
    }
}
//******************************************************************************
void Plansza::Kasuj_linie(int x)
{
for(int i=3;i<S-3;i++)
plansza[x][i]=0;

for(int i=x-1;i>4;i--)
for(int j=3;j<S-3;j++)
if(plansza[i][j]==-1) {plansza[i+1][j]=plansza[i][j]; plansza[i][j]=0;}     
}
//******************************************************************************
void Plansza::Sprawdz_linie()
{
bool kasuj=true;
    for(int i=4;i<W-3;i++)
    {
        for(int j=3;j<S-3;j++)
            if(plansza[i][j]!=-1) {kasuj=false; break;}
    if(kasuj==true) this->Kasuj_linie(i);
    else kasuj=true;
    }
}
//******************************************************************************
void Plansza::Rysuj_plansze()
{
system("cls");
    for(int i=4;i<W;i++)
    {
        for(int j=0;j<S;j++)
        
        if(j<3 || j>=S-3 || i>=W-3) cout<<"|";
        else
            switch(plansza[i][j])
            {
            case -1:
            cout<<"#"; break;
            case 0:
            cout<<" "; break;
            default:
            cout<<"@";        
            }
    cout<<"\n";
    } 
    
        
} 
//******************************************************************************
bool Plansza::Koniec_gry()
{
bool koniec=false;
    for(int i=3;i<S-3;i++)
        if(plansza[3][i]==-1) {koniec=true; break;}
return koniec;    
}
//******************************************************************************

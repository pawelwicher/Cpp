#include "Logika.h"

int Plansza[10][10]={0};

void TAB(int Tab[10][10])
{
for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        Tab[i][j]=rand()%4;
}

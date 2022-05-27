#include <iostream>
#include <ctime> 
using namespace std;

void OdkryjPoleRek(int,int,int,int[5][10]);
void Funkcja(int[5][10]);
void Funkcja2(int [5][10]);
int CzySamotna(int,int,int,int[5][10]);

int main()
{

int tab[5][10];
int a,b,nr;
srand ((int)time(NULL)); 

for(int i=0;i<5;i++)
for(int j=0;j<10;j++)
tab[i][j]=rand()%2+1;

do                       //2. funkcja przesuwajaca kolumny do lewej po wyzerowaniu
{                        //ktores z kolumn

for(int i=0;i<5;i++)
{
for(int j=0;j<10;j++)
{ 
cout<<tab[i][j];
}
cout<<"\n";
}


cout<<"\n";
cin>>nr;
cin>>a>>b;
cout<<"\n";

if(!CzySamotna(a-1,b-1,nr,tab))
{
OdkryjPoleRek(a-1,b-1,nr,tab);
Funkcja(tab);
Funkcja2(tab);
}

}while(a!=99);

cout<<"\n";
system("pause");
}


void OdkryjPoleRek(int x,int y,int nr, int t[5][10])
{
    if (x<0 || x>=5 || y<0 || y>=10)
    return;

     
    if(t[x][y]==nr)
    {
    t[x][y]=0;                    
    OdkryjPoleRek(x,y-1,nr,t);
    OdkryjPoleRek(x-1,y,nr,t);
    OdkryjPoleRek(x+1,y,nr,t);
    OdkryjPoleRek(x,y+1,nr,t);
    } 
}

void Funkcja(int t[5][10])
{
int k;
int t1[5];


for(int j=0;j<10;j++)
{
k=4; 

for(int i=4;i>=0;i--)
if(t[i][j]!=0) {t1[k]=t[i][j]; k--;}

for(int i=0;i<=k;i++)
t1[i]=0;

for(int i=0;i<5;i++)
t[i][j]=t1[i];
}
    

}


int CzySamotna(int x,int y,int nr,int t[5][10])
{
int p=0;
//narozniki
if(x==0 && y==0){if(t[x+1][y]!=nr && t[x][y+1]!=nr) p=1;}
if(x==0 && y==9){if(t[x+1][y]!=nr && t[x][y-1]!=nr) p=1;}
if(x==9 && y==0){if(t[x-1][y]!=nr && t[x][y+1]!=nr) p=1;}
if(x==9 && y==9){if(t[x-1][y]!=nr && t[x][y-1]!=nr) p=1;}

//krawedzie
if(x==0 && y>0 && y<9){if(t[x+1][y]!=nr && t[x][y+1]!=nr && t[x][y-1]!=nr) p=1;}
if(x==9 && y>0 && y<9){if(t[x-1][y]!=nr && t[x][y+1]!=nr && t[x][y-1]!=nr) p=1;}
if(y==0 && x>0 && x<9){if(t[x][y+1]!=nr && t[x+1][y]!=nr && t[x-1][y]!=nr) p=1;}
if(y==9 && x>0 && x<9){if(t[x][y-1]!=nr && t[x+1][y]!=nr && t[x-1][y]!=nr) p=1;}

//wnetrze
if(x>0 && x<9 && y>0 && y<9)
{if(t[x+1][y]!=nr && t[x-1][y]!=nr&& t[x][y+1]!=nr && t[x][y-1]!=nr) p=1;}

return p;
}



void Funkcja2(int t[5][10])
{
int m=0;
for(int i=9;i>=0;i--)
if(t[4][i]==0)
{
for(int j=i;j<10-1;j++)
for(int k=0;k<5;k++)
t[k][j]=t[k][j+1];  

for(int k=0;k<5;k++)
t[k][9-m]=0; 
m++;          
}


}

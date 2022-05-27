/* siec jednowarstwowa - rozpoznawanie znakow drukowanych
program jest na tyle elastyczny ze umozliwia dodawanie kolejnych znakow do nauki
bez wiekszej ingerencji w kod; nalezy zmienic stale zdefiniowane N i P oraz dodac
zakodowany zero-jedynkowo znak do macierzy "znaki" oraz rozszerzyc macierz wag */

#include <iostream>
#include <math.h>
#include <ctime> 
#define N 3                     //liczba neuronow w sieci
#define W 36                    //liczba wejsc sieci
#define Z 3                     //liczba rozpoznawalnych znakow
#define P 3                     //liczba par uczacych (P=N)
using namespace std;

int menu();
void mnozenieMacierzy(float [][W],float [W],float [N]);              //funkcja mnozy macierz wag z wektorem wejsc
float f(float);                                                      //funkcja aktywacji
void odpowiedzSieci(float [][W],float [W],float [N],float [N]);
void wyswietlZnak(float [W]);
float los();

//******************************* funkcja: main ********************************
int main()
{

float znaki[N][W]={
{0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,-1},      //znak "A"
{1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,-1},      //znak "B"
{0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,-1}};     //znak "C"

float wagi[N][W]={
0.03,	0.07,	0.05,	0.01,	0.05,	0.02,	0.01,	0.07,	0.08,
0.06,	0.07,	0.06,	0.01,	0.02,	0.04,	0.03,	0.06,	0.04,
0.09,	0.07,	0.03,	0.04,	0.02,	0.02,	0.1,	0.1,	0.05,
0.02,	0.01,	0.07,	0.04,	0.05,	0.08,	0.02,	0.02,	0.06,
0.07,	0.08,	0.02,	0.1,	0.04,	0.02,	0.08,	0.07,	0.09,       //poczatkowe przypadkowe wartosci wag
0.08,	0.02,	0.09,	0.03,	0.1,	0.09,	0.01,	0.02,	0.04,
0.04,	0.08,	0.07,	0.02,	0.04,	0.03,	0.02,	0.09,	0.06,
0.07,	0.06,	0.1,	0.04,	0.06,	0.01,	0.01,	0.02,	0.07,
0.02,	0.09,	0.1,	0.05,	0.05,	0.04,	0.09,	0.06,	0.09,
0.06,	0.05,	0.07,	0.08,	0.06,	0.09,	0.01,	0.09,	0.08,
0.1,	0.05,	0.03,	0.01,	0.05,	0.05,	0.09,	0.07,	0.04,
0.1,	0.08,	0.01,	0.04,	0.06,	0.06,	0.03,	0.04,	0.1};

float znakA[W]={
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,1,
1,0,0,0,1,
1,0,0,0,1,
1,0,0,0,1,-1};

float znakB[W]={
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,0,-1};

float znakC[W]={
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,1,
0,1,1,1,0,-1};

float znak1[W]={
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,0,0,0,1,-1};

float znak2[W]={
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,1,1,1,0,-1};

float znak3[W]={
1,1,1,1,0,
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,1,1,1,0,-1};

float znakLosowy[W]={0};

float net[N]={0};                             //wynik iloczynu skalarnego wektorow wag i wejsc (wyzerowane)
float z[N]={0};                               //wektor wyjsc (wyzerowane)            
float d[N][N]={{1,0,0},{0,1,0},{0,0,1}};      //tablica wektorow oczekiwanych wyjsc
const float ni=2;                             //wspolczynnik uczenia; zalezy od niego szybkosc zbieznosci do Emax
const float Emax=0.0001;                      //progowa laczna wartosc bledu
float E=0;                                    //blad bierzacy
int l=0;                                      //licznik krokow algorytmu
int licznik=0;                                //zmienna pokazujaca liczbe cykli uczenia po ukonczeniu algorytmu
float suma;                                   //zmienna pomocnicza
int dalej=1;                                  //zmienna pomocnicza
int k;                                        //zmienna pomocnicza
int p;                                        //zmienna pomocnicza


//**************************** algorytm uczenia ********************************
while(dalej)
{
licznik++;
    while(l<P)
    {   
    mnozenieMacierzy(wagi,znaki[l],net);
        for(int k=0;k<N;k++)
        {
        z[k]=f(net[k]);        
        for(int i=0;i<W;i++)
        wagi[k][i]+=ni*(d[l][k]-z[k])*z[k]*(1-z[k])*znaki[l][i];   //aktualizacja wag
        suma+=(d[l][k]-z[k])*(d[l][k]-z[k]);                       //licznie bledu
        }
    E+=0.5*suma;                                                   //liczenie bledu
    suma=0;
    l++;
    }
    if(E>Emax){l=0;E=0;}                                           //regula stopu
    else dalej=0;
}
cout<<"Koniec nauki. Siec rozpoznaje 3 znaki (A,B,C).\n";
cout<<"Wspolczynnik uczenia: "<<ni<<"\n";
cout<<"Dopuszczalny blad Emax: "<<Emax<<"\n";
cout<<"Algorytm zakonczyl sie po "<<licznik<<" cyklach uczenia.\n";
//**************************** algorytm uczenia ********************************

srand ((int) time(NULL)); 

do
{
p=menu();

    switch(p)
    {
        case 1:
        {
        wyswietlZnak(znakA);
        odpowiedzSieci(wagi,znakA,net,z);
        break;
        }
        
        case 2:
        {
        wyswietlZnak(znakB);
        odpowiedzSieci(wagi,znakB,net,z);
        break;
        }
        
        case 3:
        {
        wyswietlZnak(znakC);
        odpowiedzSieci(wagi,znakC,net,z);
        break;
        }
        
        case 4:
        {
        wyswietlZnak(znak1);
        odpowiedzSieci(wagi,znak1,net,z);
        break;
        }
        
        case 5:
        {
        wyswietlZnak(znak2);
        odpowiedzSieci(wagi,znak2,net,z);
        break;
        }
        
        case 6:
        {
        wyswietlZnak(znak3);
        odpowiedzSieci(wagi,znak3,net,z);
        break;
        }
        
        case 7:
        {
        for(int i=0;i<W-1;i++)
        znakLosowy[i]=los();
        znakLosowy[W-1]=-1;
        wyswietlZnak(znakLosowy);
        odpowiedzSieci(wagi,znakLosowy,net,z);
        break;
        }
    }

}
while(p!=0);    //do momentu kiedy uzytkownik nie wybierze w menu 0
}
//******************************* funkcja: main ********************************
//******************************* funkcja: menu ********************************
int menu()
{
int odp;
 cout<<"\nWybierz jedna z opcji:";
 cout<<"\n1 - Znak 'A'";
 cout<<"\n2 - Znak 'B'";
 cout<<"\n3 - Znak 'C'";
 cout<<"\n4 - Znak 'A' (zmieniony)";
 cout<<"\n5 - Znak 'B' (zmieniony)";
 cout<<"\n6 - Znak 'C' (zmieniony)";
 cout<<"\n7 - Znak losowy";  
 cout<<"\n0 - Zakoncz program\n\n";

do
{
cin>>odp;
}
while(odp<0 || odp>7);
system("cls");
return odp;
}
//******************************* funkcja: menu ********************************
//************************* funkcja: mnozenieMacierzy **************************
void mnozenieMacierzy(float tabA[][W],float tabB[W],float tabC[N])
{
    for(int i=0;i<N;i++)
    {
        *(tabC+i)=0;
        for(int k=0;k<W;k++)
        *(tabC+i)+=*(*(tabA+i)+k) * (*(tabB+k));
    }
}
//************************* funkcja: mnozenieMacierzy **************************
//************************* funkcja: f (f. aktywacji) **************************
float f(float net)
{
const float lambda=1;
      return 1/(1+exp(-lambda*net));
}
//************************* funkcja: f (f. aktywacji) **************************
//************************** funkcja: f wyswietlZnak ***************************
void wyswietlZnak(float t[W])
{
cout<<"\n";
for(int i=0;i<W;i++)
{
if(*(t+i)==1) cout<<"#";
else cout<<" ";
if((i+1)%5==0) cout<<"\n";    
}
}
//************************** funkcja: f wyswietlZnak ***************************
//************************* funkcja: f odpowiedzSieci **************************
void odpowiedzSieci(float tabA[][W],float tabB[W],float tabC[N],float tabD[N])
{
mnozenieMacierzy(tabA,tabB,tabC);   
cout<<"\nOdpowiedz sieci na zadany sygnal:\n";
    for(int k=0;k<N;k++)
    {
    tabD[k]=f(tabC[k]);
    cout<<"Neuron["<<k+1<<"] ---> "<<tabD[k]<<"\n";
    }
}

float los()
{
if(rand()%2) return 1;
else return 0; 
} 
//************************* funkcja: f odpowiedzSieci **************************

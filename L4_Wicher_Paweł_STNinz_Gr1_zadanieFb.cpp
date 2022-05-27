/*
Plik L4_Wicher_Pawe³_STNinz_Gr1_zadanieFb.cpp
Pawe³ Wicher 55555 DevC++
*/


#include <iostream>
using namespace std;


int menu();             //prototypy funkcji
void czytajTablice(float [],int);
void ogladajTablice(float [],int);
float MAX(float [],int);
float MIN(float [],int);
int iMAX(float [],int);
int iMIN(float [],int);


//****************************funkcja main**************************************
int main()
{
const int ROZMIAR=20;
float tablica[ROZMIAR];
int ile;
int p;
double liczba,przyblizenie;

do
{
p=menu();

    switch(p)
    {
        case 1:
        {
        cout<<"\nPodaj liczbe elemetow w tablicy\n";
        cin>>ile;
        czytajTablice(tablica,ile);
        break;
        }
        
        case 2:
        {
        ogladajTablice(tablica,ile);
        cout<<"\n";
        break;
        }
        
        case 3:
        {
        cout<<"\nElement o NAJWIEKSZEJ wartosci w podanej tablicy wynosi: "<<MAX(tablica,ile)<<"\n";     
        break;
        }
        
        case 4:
        {
        cout<<"\nElement o NAJMNIEJSZEJ wartosci w podanej tablicy wynosi: "<<MIN(tablica,ile)<<"\n";                  
        break;
        }
        
        case 5:
        {
        cout<<"\nNumer elementu o NAJWIEKSZEJ wartosci podanej tablicy wynosi: "<<iMAX(tablica,ile)<<"\n";     
        break;
        }
        
        case 6:
        {
        cout<<"\nNumer elementu o NAJMNIEJSZEJ wartosci podanej tablicy wynosi: "<<iMIN(tablica,ile)<<"\n";                  
        break;
        }
        
        case 7:
        {
        cout<<"\nMAX=t["<<iMAX(tablica,ile)<<"]="<<MAX(tablica,ile)<<"\n";             
        cout<<"MIN=t["<<iMIN(tablica,ile)<<"]="<<MIN(tablica,ile)<<"\n"; 
        break;
        }
    }

}
while(p!=0);    //do momentu kiedy uzytkownik nie wybierze w menu 0

}
//****************************funkcja main**************************************


//****************************menu programu*************************************
int menu()
{

int odp;

 cout<<"\nWybierz jedna z opcji:";
 cout<<"\n1 - Wprowadzanie danych";
 cout<<"\n2 - Przegladanie danych";
 cout<<"\n3 - Wartosc MAKSYMALNA w tablicy";
 cout<<"\n4 - Wartosc MINIMALNA w tablicy";
 cout<<"\n5 - Numer elementu o NAJWIEKSZEJ wartosci";
 cout<<"\n6 - Numer elementu o NAJMNIEJSZEJ wartosci";
 cout<<"\n7 - MIN i MAX wraz z indeksami";
 cout<<"\n0 - zakoncz program\n\n";

do
{
cin>>odp;
}
while(odp<0 || odp>7);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja: wczytajTablice***************************
void czytajTablice(float t[],int n)
{
     cout<<"\nPodaj "<<n<<" liczb\n";
     for(int i=0;i<n;i++)
     {
        cout<<"liczba nr: "<<i<<"\n";
        cin>>t[i];
     }
}
//****************************funkcja: wczytajTablice***************************


//****************************funkcja: ogladajTablice***************************
void ogladajTablice(float t[],int n)
{
 for(int i=0;i<n;i++)
 cout<<"\nt["<<i<<"]="<<t[i];
}
//****************************funkcja: ogladajTablice***************************

//****************************funkcja: MAX**************************************
float MAX(float t[],int n)
{
 float max=t[0];

 for(int i=0;i<n;i++)
 if(t[i]>max) max=t[i];

 return max;
}
//****************************funkcja: MAX**************************************

//****************************funkcja: MIN**************************************
float MIN(float t[],int n)
{
 float min=t[0];

 for(int i=0;i<n;i++)
 if(t[i]<min) min=t[i];

 return min;
}
//****************************funkcja: MIN**************************************


//****************************funkcja: iMAX*************************************
int iMAX(float t[],int n)
{
 float max=t[0];
 int imax=0;

 for(int i=0;i<n;i++)
 if(t[i]>max) imax=i;

 return imax;
}
//****************************funkcja: iMAX*************************************

//****************************funkcja: iMIN*************************************
int iMIN(float t[],int n)
{
float min=t[0];
int imin=0;

for(int i=0;i<n;i++)
if(t[i]<min) imin=i;

return imin;
}
//****************************funkcja: iMIN*************************************
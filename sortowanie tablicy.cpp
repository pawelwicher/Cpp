/*
Plik L4_Wicher_Pawe³_STNinz_Gr1_zadanieFb.cpp
Pawe³ Wicher 55555 DevC++
*/


#include <iostream>
using namespace std;


int menu();             //prototypy funkcji
void czytajTablice(float*,int);
void ogladajTablice(float*,int);
void Sortuj(float*,int);


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
        Sortuj(tablica,ile);
        cout<<"Tablica posortowana\n";
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
 cout<<"\n3 - Sortuj tablice";
 cout<<"\n0 - zakoncz program\n\n";

do
{
cin>>odp;
}
while(odp<0 || odp>3);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja: wczytajTablice***************************
void czytajTablice(float *t,int n)
{
     cout<<"\nPodaj "<<n<<" liczb\n";
     for(int i=0;i<n;i++)
     {
        cout<<"liczba nr: "<<i<<"\n";
        cin>>*(t+i);
     }
}
//****************************funkcja: wczytajTablice***************************


//****************************funkcja: ogladajTablice***************************
void ogladajTablice(float *t,int n)
{
 for(int i=0;i<n;i++)
 cout<<"\nt["<<i<<"]="<<*t++;
}
//****************************funkcja: ogladajTablice***************************

//****************************funkcja: Sortuj***********************************
void Sortuj(float *t, int n)
{

   for (int i=0; i<n; i++)
   {
      for (int j=0; j<n-1; j++)
      {
         if (t[j]>t[j+1])
         {
            float tmp;
            tmp = t[j];
            t[j] = t[j+1];
            t[j+1] = tmp;
         }
      }
   }

}
//****************************funkcja: Sortuj***********************************


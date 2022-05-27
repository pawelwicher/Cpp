/*
Plik L4_Wicher_Pawe³_STNinz_Gr1_zadanieB.cpp
Pawe³ Wicher 55555 DevC++
*/
#include <iostream>
using namespace std;

int menu();             //prototypy funkcji
double EdoX(double,double);
double SinX(double,double);
double CosX(double,double);
double Abs(double);

//****************************funkcja main**************************************
int main()
{
int p;
double liczba,dokladnosc;

do
{
p=menu();

switch(p)
    {
         case 1:
         {
          cout<<"\nPodaj liczbe\n";
          cin>>liczba;
          cout<<"\nPodaj dokladnosc\n";
          cin>>dokladnosc;
          cout<<"\n"<<"e^"<<liczba<<"="<<EdoX(liczba,dokladnosc);
          break;
         }
         
         case 2:
         {
          cout<<"\nPodaj liczbe\n";
          cin>>liczba;
          cout<<"\nPodaj dokladnosc\n";
          cin>>dokladnosc;
          cout<<"\n"<<"sin("<<liczba<<")="<<SinX(liczba,dokladnosc);
          break;
         }
         
         case 3:
         {
          cout<<"\nPodaj liczbe\n";
          cin>>liczba;
          cout<<"\nPodaj dokladnosc\n";
          cin>>dokladnosc;
          cout<<"\n"<<"cos("<<liczba<<")="<<CosX(liczba,dokladnosc);
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

 cout<<"\n\nWybierz jedna z opcji:";
 cout<<"\n1 - obliczanie wartosci funkcji e^x w punkcie x przy zadanej dokladnosci";
 cout<<"\n2 - obliczanie wartosci funkcji sin(x) przy zadanej dokladnosci";
 cout<<"\n3 - obliczanie wartosci funkcji cos(x) przy zadanej dokladnosci";
 cout<<"\n0 - zakoncz program\n\n";

do
{
cin>>odp;
}
while(odp<0 || odp>3);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja: EdoX*************************************
double EdoX(double x,double eps)
{
double potega=1;
double silnia=1;
double suma=1;
double wyraz=0;
int i=1;

do
{
    silnia*=i;
    potega*=x;
    wyraz=potega/silnia;
    suma+=wyraz;
    i++;
}
while(wyraz>eps);

return suma;
}
//****************************funkcja: EdoX*************************************

//****************************funkcja: SinX*************************************
double SinX(double x,double eps)
{
int k=0;
double s,w;
w=x;
s=x;

while(Abs(w)>eps)
{
w=-w;
k++;
w*=x*x/(2*k*(2*k+1));
s+=w;
}
return s;
}
//****************************funkcja: SinX*************************************

//****************************funkcja: CosX*************************************
double CosX(double x,double eps)
{
int k=0;
double s,w;
w=1;
s=1;

while(Abs(w)>eps)
{
w=-w;
k++;
w*=x*x/(2*k*(2*k+1));
s+=w;
}
return s;
}
//****************************funkcja: CosX*************************************

//****************************funkcja: Abs**************************************
double Abs(double x)
{
if(x<0) return -x;
else return x;
}
//****************************funkcja: Abs**************************************


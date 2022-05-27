/*
plik_L2_wicher_STNinz_gr1_ciag_n_liczb.cpp
Wicher Pawe³ 55555
ciag_n_liczb
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
int n,i,liczba,max,min,imax,imin;
char end;

do
{
 cout<<"ile liczb chcesz podac? ";
 cin>>n;
 cout<<"\n";

 cout<<"Podaj liczbe nr: 1\n";
 cin>>liczba;
 cout<<"\n";

 min=liczba;
 max=liczba;
 imin=1;
 imax=1;
 for(i=2;i<n+1;i++)
 {
   cout<<"Podaj liczbe nr: "<<i<<"\n";
   cin>>liczba;
   cout<<"\n";
   
   if(liczba>max) {max=liczba; imax=i;}
   if(liczba<min) {min=liczba; imin=i;}
 }
 cout<<"\n\nMAX="<<max<<" i byl to wyraz o numerze "<<imax<<"\n";
 cout<<"\nMIN="<<min<<" i byl to wyraz o numerze "<<imin<<"\n";

 cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
 cin>>end; 
} 
while(end!='q');
    
}


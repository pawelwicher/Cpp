/*L3_Wicher_STNinz_gr1_programF
Pawe³ Wicher 55555
Program F */
#include<iostream>

using namespace std;

main()
{
float tab[100],max,min;
int i,n,imax,imin;

cout<<"Podaj ile liczb chcesz wprowadzic: "; cin>>n;
for(i=0;i<n;i++)
{cout<<"\nPodaj liczbe nr: "<<i<<"\n"; cin>>tab[i];}

cout<<"\n\nPodales nastepujace liczby:\n";        
for(i=0;i<n;i++)
{cout<<"tab["<<i<<"]="<<tab[i]<<"\n";}      

max=tab[0];
min=tab[0];
imax=0;
imin=0;


for(i=0;i<n;i++)
{
if(tab[i]>max) {max=tab[i]; imax=i;}
if(tab[i]<min) {min=tab[i]; imin=i;}
}       

cout<<"\n\n";
cout<<"MAX=tab["<<imax<<"]="<<max<<"\n";
cout<<"MIN=tab["<<imin<<"]="<<min<<"\n";

system("pause");


}
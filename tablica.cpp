/*
tablice
*/

#include <iostream>

using namespace std;



int main()
{
const int WYM=100;
float x[WYM],liczba;
int i=1,j,k,przesun;
char end;

do
{
cout<<"Podaj pierwsza liczbe\n";
cin>>x[0];
cout<<"Podaj kolejne liczby: \n";

while(i<WYM)
{
    cout<<"?"; cin>>liczba;
    if(liczba<0) continue;
    if(liczba==0) break;
    przesun=0;
    
    for(k=0;k<i;k++)
    {
        if(x[k]>liczba)
        {
        przesun=1;
        for(j=i;j>k;j--)
        {x[j]=x[j-1];}
        x[k]=liczba;
        }
        break;
    }
    
    if(przesun==0) x[i]=liczba;
    i++;
}
i--;

cout<<"\n";
for(i=0;i<5;i++)
cout<<"\n"<<x[i];
    
    





cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

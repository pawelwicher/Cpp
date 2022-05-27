/*
trojkat z gwiazdek
*/

#include <iostream>

using namespace std;

int main()
{
int wielkosc_drzewka,n,k,p,i,j,ile_gwiazdek, ile_spacji;   
char end;

do
{
cout<<"podaj wielkosc drzewka: ";
cin>>wielkosc_drzewka;
cout<<"\n";

n=2;
p=wielkosc_drzewka;

for(k=1;k<wielkosc_drzewka+1;k++)
{
n++;
ile_gwiazdek=1;
ile_spacji=n-1;


for(i=1;i<n+1;i++)
{
 for(j=1;j<p;j++)
 {cout<<" ";}                 
                                  
 for(j=1;j<ile_spacji+1;j++)
 {cout<<" ";}
 
 for(j=1;j<ile_gwiazdek+1;j++)
 {cout<<"*";}
 
ile_gwiazdek+=2;
ile_spacji--;

cout<<"\n";
}
p--;

}

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

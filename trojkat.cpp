/*
trojkat z gwiazdek
*/

#include <iostream>

using namespace std;

void Trojkat(int);

int main()
{
int x;   
char end;

do
{
cout<<"podaj dlugosc boku trojkata: ";
cin>>x;
cout<<"\n";
Trojkat(x);




cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

void Trojkat(int n)
{
int i,j,ile_gwiazdek, ile_spacji;  

    ile_gwiazdek=1;
    ile_spacji=n-1;
    
    for(i=1;i<=n;i++)
    {
                    
     for(j=1;j<=ile_spacji;j++)
     cout<<" ";
     
     for(j=1;j<=ile_gwiazdek;j++)
     cout<<"*";
     
    ile_gwiazdek+=2;
    ile_spacji--; 
    cout<<"\n";
    }

}

/*
Sortowanie trzech liczb ze swapem
*/

#include <iostream>

using namespace std;

int main()
{
int a,b,c,temp;   
char end;

do
{
cout<<"Podaj a: ";
cin>>a;
cout<<"\n";
cout<<"Podaj b: ";
cin>>b;
cout<<"\n";
cout<<"Podaj c: ";
cin>>c;
cout<<"\n\n";

if(a>b){temp=a; a=b; b=temp;}
if(b>c){temp=b; b=c; c=temp;}
if(a>b){temp=a; a=b; b=temp;}

cout<<"Podane liczby w kolejnosci rosnacej: "<<a<<", "<<b<<", "<<c;

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

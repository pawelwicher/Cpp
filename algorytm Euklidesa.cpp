/*
Euklides
*/

#include <iostream>

using namespace std;

int main()
{
int a,b,a1,b1;   
char end;



do
{

cout<<"Podaj a i b\n";
cin>>a;
cin>>b;

a1=a;
b1=b;

while(a!=b)
{
if(a>b) a=a-b;
else b=b-a;
}

cout<<"\nNajmniejsza wspolna wielokrotnosc liczb "<<a1<<" i "<<b1<<" wynosi "<<a;

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n\n";
cin>>end; 
} 
while(end!='q');    
}

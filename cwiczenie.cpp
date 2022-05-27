/*
Cwiczenie
*/

#include <iostream>

using namespace std;

int main()
{  
char end;
int i;

do
{
    
i=2;
   
while(i)
{cout<<i--<<"\n";}          //wynik: 2,1

cout<<"\n";

i=2;
while(i)
{cout<<--i<<"\n";}          //wynik: 1,0

cout<<"\n";

i=2;
while(i--)
{cout<<i<<"\n";}            //wynik: 1,0

cout<<"\n";

i=2;
while(--i)
{cout<<i<<"\n";}            //wynik: 1




cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

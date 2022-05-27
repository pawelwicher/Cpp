/*
trojkat z gwiazdek
*/

#include <iostream>

using namespace std;

int main()
{
int a,b,r;   
char end;

do
{

do{
cout<<"Podaj a i b ";
cin>>a>>b;
} while(a<=0 || b<=0);

while(r=a%b)
{
a=b;
b=r;
}
cout<<"\nNWD= "<<b;

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

/*
Liczby lustrzane
*/

#include <iostream>

using namespace std;

int main()
{
int x,x1,y;   
char end;

do
{

cout<<"\nPodaj liczbe naturalna\n";  
cin>>x;
x1=x;
cout<<"\n";
   
y=0;

while(x!=0)    
{
y=y*10+x%10;
x=x/10;
}

cout<<"lustrzane odbicie "<<x1<<" to "<<y;


cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

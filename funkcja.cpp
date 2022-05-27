/*

*/
#include <iostream>
using namespace std;

int F(int);

int main()
{
int liczba;
char end;

do
{
cout<<"\n";
cin>>liczba;
cout<<F(liczba);


cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}


int F(int x)
{
int y;
for(y=x%10;x=x/10;y+=x%10);
return y;
}


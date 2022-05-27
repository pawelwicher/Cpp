/*
Najkrotszy IF
*/

#include <iostream>

using namespace std;

int main()
{
int n,test;   
char end;

do
{
cout<<"Podaj liczbe\n";
cin>>n;
cout<<"\n";
test=n?1:0;
cout<<"Wynik testu: "<<test;




cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

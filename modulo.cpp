/*
funkcja operator modulo
*/

#include <iostream>

using namespace std;

int Mod(int,int);

int main()
{
int x,y;

char end;

do
{
cout<<"podaj dwie liczby naturalne\n";
cin>>x>>y;
cout<<x<<"%"<<y<<"="<<Mod(x,y);

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

int Mod(int a,int b)
{
 return a-b*(a/b);
}

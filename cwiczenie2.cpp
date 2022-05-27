/*
Cwiczenie
*/

#include <iostream>

using namespace std;

int F1(int,int,int);
int F2(int,int,int);
int F3(int);

int main()
{  
char end;
int x,y,z;

do
{
cin>>x>>y>>z;    
cout<<F1(x,y,z)<<"\n";
cout<<F2(x,y,z)<<"\n";    

cout<<F3(x)<<"\n"; 



cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

int F1(int a,int b, int c)
{
if(a>b/2) return c+2;
else return c-2;
}

int F2(int a,int b, int c)
{
return(a>b/2)?c+2:c-2;
}

int F3(int a)
{
return(--a);
}

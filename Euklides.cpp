/*
algorytm Euklidesa
*/

#include <iostream>

using namespace std;

int main()
{
int a,b,a1,b1;   
char end;

do
{
cout<<"podaj a i b:\n";
cin>>a>>b;
a1=a;
b1=b;
cout<<"\n\n";

while(a!=b)
{
           if(a>b) a-=b;
           else b-=a;
}
cout<<"NWW dla liczb: "<<a1<<" i "<<b1<<" wynosi: "<<a;


cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

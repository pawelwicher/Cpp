/*
Liczby doskonale
*/

#include <iostream>

using namespace std;

int main()
{
int n,s,d;   
char end;

do
{
cout<<"Podaj liczbe naturalna\n";
cin>>n;
cout<<"\n\n";

s=0;
d=0;

while(d!=n/2)
{
d++;
if(n%d==0) s=s+d;
}
cout<<s<<"\n";


if(s==n) cout<<n<<" JEST liczba doskonala";
else cout<<n<<" NIE JEST liczba doskonala";

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

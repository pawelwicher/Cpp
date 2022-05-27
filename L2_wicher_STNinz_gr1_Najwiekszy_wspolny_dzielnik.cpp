/*
plik_L2_wicher_STNinz_gr1_Najwiekszy_wspolny_dzielnik.cpp
Wicher Pawe³ 55555
Najwiekszy_wspolny_dzielnik
*/

#include <iostream>

using namespace std;

int main()
{
int a,b,a1,b1,ile_par,i;
 
char end;

do
{
     
cout<<"ile par liczb? ";
cin>>ile_par;
cout<<"\n";     

for (i=1;i<ile_par+1;i++)
{

cout<<"para nr: "<<i<<"\n";

cout<<"podaj a: ";
cin>>a;
cout<<"podaj b: ";
cin>>b;


a1=a;
b1=b;

while(a!=b)
{
if(a>b) a=a-b;
else b=b-a;
}

cout<<"\nNWD nr: "<<i<<" dla pary "<<a1<<" i "<<b1<<" wynosi: "<<a<<"\n\n";
}


cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

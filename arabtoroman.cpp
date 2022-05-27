/*
Konwersja liczby arabskiej na rzymska
*/

#include <iostream>

using namespace std;

int main()
{
int n,arabska,i;
int tysiace, setki, dziesiatki, jednosci;   
char end;

do
{
cout<<"Podaj liczbe naturalna\n";
cin>>n;
cout<<"\n\n";

arabska=n;

tysiace=0;
setki=0;
dziesiatki=0;
jednosci=0;

while(n>=1000)
{
n=n-1000;
tysiace++;
}

while(n>=100)
{
n=n-100;
setki++;
}

while(n>=10)
{
n=n-10;
dziesiatki++;
}

while(n>0)
{
n=n-1;
jednosci++;
}

cout<<"liczba tysiecy: "<<tysiace<<"\n";
cout<<"liczba setek: "<<setki<<"\n";
cout<<"liczba dziesiatek: "<<dziesiatki<<"\n";
cout<<"liczba jednosci: "<<jednosci<<"\n";

cout<<"\n\n";
cout<<arabska<<" = ";

for(i=1;i<=tysiace;i++)
{cout<<"M";}

if(setki==9) cout<<"CM";
if(setki==8) cout<<"DCCC";
if(setki==7) cout<<"DCC";
if(setki==6) cout<<"DC";
if(setki==5) cout<<"D";
if(setki==4) cout<<"CD";
if(setki==3) cout<<"CCC";
if(setki==2) cout<<"CC";
if(setki==1) cout<<"C";

if(dziesiatki==9) cout<<"XC";
if(dziesiatki==8) cout<<"LXXX";
if(dziesiatki==7) cout<<"LXX";
if(dziesiatki==6) cout<<"LX";
if(dziesiatki==5) cout<<"L";
if(dziesiatki==4) cout<<"XL";
if(dziesiatki==3) cout<<"XXX";
if(dziesiatki==2) cout<<"XX";
if(dziesiatki==1) cout<<"X";

if(jednosci==9) cout<<"IX";
if(jednosci==8) cout<<"VIII";
if(jednosci==7) cout<<"VII";
if(jednosci==6) cout<<"VI";
if(jednosci==5) cout<<"V";
if(jednosci==4) cout<<"IV";
if(jednosci==3) cout<<"III";
if(jednosci==2) cout<<"II";
if(jednosci==1) cout<<"I";


cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

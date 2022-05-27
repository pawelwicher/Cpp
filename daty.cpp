/*
Cwiczenie z dat
*/
#include <iostream>
using namespace std;

int Przestepny(int);
int IleDni(int,int);
void DodajDzien(int&,int&,int&);

int main()
{
int dzien,miesiac,rok;
char end;

do
{
cin>>dzien>>miesiac>>rok;
DodajDzien(dzien,miesiac,rok);
cout<<dzien<<"-"<<miesiac<<"-"<<rok;

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}


int Przestepny(int r)
{return ((r%400==0)||((r%4==0)&&(r%100!=0)));}

int IleDni(int m,int r)
{
switch(m)
{
case 4: case 6: case 9: case 11:
return 30;

case 2:
if(Przestepny(r)) return 29;
else return 28;

default: return 31;
}
}

void DodajDzien(int &d,int &m,int &r)
{
d++;
if(d>IleDni(m,r))
{
d=1;m++;

if(m>12)
{m=1;r++;}

}

}


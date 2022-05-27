#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void Wpisz(char [],int);
double Potega(double,int);


int main()
{
char tablicaZnakow[]="0123456789ABCDEF";
char liczba[]="102BCD";
int p=2;
int k=0,l=0;

double wynik=0;

for(int i=0;i<strlen(liczba);i++)
{
k=0;
for(int j=0;j<p;j++)
if(liczba[i]==tablicaZnakow[j]) k=1;


l+=k;
}

cout<<l<<"\n";

for(int i=0;i<strlen(liczba);i++)
for(int j=0;j<p;j++)
if(liczba[strlen(liczba)-1-i]==tablicaZnakow[j]) wynik+=j*Potega(p,i);



cout<<wynik<<"\n";


system("pause");
}



double Potega(double x,int n)
{
double wynik=1;
for(int i=0;i<n;i++)
wynik*=x;
return wynik; 
}



void Wpisz(char t[],int n)
{
	do
	{
    gets(t);
    if(strlen(t)>n)
    cout<<"Wpis moze zawierac maksymalnie "<<n<<" znakow. Wpisz ponownie\n";
	}
    while(strlen(t)>n);
fflush(stdin);
}

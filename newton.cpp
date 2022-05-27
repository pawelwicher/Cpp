/*
algorytm Newtona
*/

#include <iostream>

using namespace std;

double Pierwiastek(double,int);

int main()
{
int liczba,liczba_iteracji;
char end;

do
{

cout<<"Podaj liczbe\n";
cin>>liczba;
cout<<"\n";

cout<<"Podaj liczbe iteracji\n";
cin>>liczba_iteracji;
cout<<"\n\n";

cout<<"W wyniku "<<liczba_iteracji<<" iteracji algorytmu Newtona\notrzymano przyblizenie pierwiastka liczby "<<liczba<<" rowne:\n"<<Pierwiastek(liczba,liczba_iteracji);

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

double Pierwiastek(double a,int n)
{
double x=a*0.5;
for(int i=1;i<=n;i++)       
x=0.5*(x+a/x);
return x;
}

  


//program menu + rozne funkcje


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
void Bin(int);




//****************************funkcja main**************************************
int main()
{
int p,liczba;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  cout<<"\nPodaj liczbe naturalna\n";
  cin>>liczba;
  Bin(liczba);
  cout<<"\n\n";
  break;
 }

}
}
while(p!=0);    //do momentu kiedy uzytkownik nie wybierze w menu 0

}
//****************************funkcja main**************************************


//****************************menu programu*************************************
int menu()
{

int odp;

 cout<<"\nWybierz jedna z opcji:";
 cout<<"\n1 - zamiana liczby dziesietnej na dwojkowa";
 cout<<"\n0 - zakoncz program\n\n";

do
{
 cin>>odp;
 if(odp<0 || odp>1)
 {
 cout<<"Wybierz jedna z dostepnych opcji";
 cout<<"\n1 - zamiana liczby dziesietnej na dwojkowa";
 cout<<"\n0 - zakoncz program\n\n";
 }
}
while(odp<0 || odp>1);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
void Bin(int x)
{
int i=1;
while(i<=x)
{
i*=2;
}
i/=2;

do
{
if(x>=i) {cout<<"1"; x-=i; i/=2;}
else {cout<<"0"; i/=2;}
}
while(i);

}
//****************************funkcja numer 1***********************************


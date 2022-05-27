
//program menu + rozne funkcje


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
double Sin(double,double);
double Abs(double);




//****************************funkcja main**************************************
int main()
{
int p;
double liczba,przyblizenie;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  cout<<"\nPodaj liczbe\n";
  cin>>liczba;
  cout<<"\nPodaj przyblizenie\n";
  cin>>przyblizenie;
  cout<<"\n"<<Sin(liczba,przyblizenie);
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
 cout<<"\n1 - obliczanie wartosci funkcji sinus w punkcie x";
 cout<<"\n0 - zakoncz program\n\n";

do
{
 cin>>odp;
 if(odp<0 || odp>1)
 {
 cout<<"Wybierz jedna z dostepnych opcji";
 cout<<"\n1 - obliczanie wartosci funkcji sinus w punkcie x";
 cout<<"\n0 - zakoncz program\n\n";
 }
}
while(odp<0 || odp>1);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
double Sin(double x, double eps)
{
int k=0;
double s,w;
w=x;
s=x;

while(Abs(w)>eps)
{
w=-w;
k++;
w*=x*x/(2*k*(2*k+1));
s+=w;
}
return s;
}
//****************************funkcja numer 1***********************************


//****************************funkcja numer 2***********************************
double Abs(double x)
{
if(x<0) return -x;
else return x;
}
//****************************funkcja numer 2***********************************


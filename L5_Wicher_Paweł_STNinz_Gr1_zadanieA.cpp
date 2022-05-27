
//program menu + rozne funkcje


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
void Prosta(double,double);
void Okrag(double,double,double);



//****************************funkcja main**************************************
int main()
{
int p,i,n;
double a,b,promien;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  cout<<"Ile punktow chcesz sprawdzic?\n"; cin>>n;
  for(i=1;i<=n;i++)
  {
  cout<<"Podaj pare nr: "<<i<<"\n";
  cout<<"x("<<i<<")=";
  cin>>a;
  cout<<"y("<<i<<")=";
  cin>>b;
  Prosta(a,b);
  }
  break;
 }
 
  case 2:
 {
  cout<<"Ile punktow chcesz sprawdzic?\n"; cin>>n;
  cout<<"\nPromien okregu?\n"; cin>>promien;
  for(i=1;i<=n;i++)
  {
  cout<<"Podaj pare nr: "<<i<<"\n";
  cout<<"x("<<i<<")=";
  cin>>a;
  cout<<"y("<<i<<")=";
  cin>>b;
  Okrag(a,b,promien);
  }
  
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
 cout<<"\n1 - Prosta";
 cout<<"\n2 - Okrag";
 cout<<"\n0 - Koniec\n\n";

do
{
 cin>>odp;
 if(odp<0 || odp>2)
 {
 cout<<"\nWybierz jedna z opcji:";
 cout<<"\n1 - Prosta";
 cout<<"\n2 - Okrag";
 cout<<"\n0 - Koniec\n\n";
 }
}
while(odp<0 || odp>2);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
void Prosta(double x,double y)
{
if(y>x) cout<<"\npunkt ("<<x<<","<<y<<") lezy POWYZEJ prostej y=x\n\n";
else
{
if(x==y) cout<<"\npunkt ("<<x<<","<<y<<") lezy NA prostej y=x\n\n";
else cout<<"\npunkt ("<<x<<","<<y<<") lezy PONIZEJ prostej y=x\n\n";
}
}
//****************************funkcja numer 1***********************************


//****************************funkcja numer 2***********************************
void Okrag(double x,double y,double r)
{
if(x*x+y*y<r*r) cout<<"\npunkt ("<<x<<","<<y<<") lezy WEWNATRZ okregu o promieniu 1 i srodku w (0,0)\n\n";
else
{
if(x*x+y*y==r*r) cout<<"\npunkt ("<<x<<","<<y<<") lezy NA okregu o promieniu 1 i srodku w (0,0)\n\n";
else cout<<"\npunkt ("<<x<<","<<y<<") lezy NA ZEWNATRZ okregu o promieniu 1 i srodku w (0,0)\n\n";

}
}
//****************************funkcja numer 2***********************************


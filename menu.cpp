
//program menu + rozne funkcje


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
int SumaCyfr(int);
int Lustrzane(int);




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
  cout<<"\nSuma cyfr liczby "<<liczba<<" wynosi: "<<SumaCyfr(liczba)<<"\n\n";
  break;
 }
 
 case 2:
 {
  cout<<"\nPodaj liczbe naturalna\n";
  cin>>liczba;
  cout<<"\nOdbicie lustrzane liczby "<<liczba<<" to: "<<Lustrzane(liczba)<<"\n\n";
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
cout<<"\n1 - oblicz sume cyfr liczby naturalnej";
cout<<"\n2 - odbicie lustrzane liczby naturalnej";
cout<<"\n0 - zakoncz program\n\n";

do
{
 cin>>odp;
}
while(odp<0 || odp>2);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
int SumaCyfr(int x)
{
int y=0;

while(x!=0)
{
 y+=x%10;
 x=x/10;
}
return y;
}
//****************************funkcja numer 1***********************************



//****************************funkcja numer 2***********************************
int Lustrzane(int x)
{
int y=0;

while(x!=0)
{
 y=y*10+x%10;
 x=x/10;
}
return y;
}
//****************************funkcja numer 2***********************************


//menu szablon


#include <iostream>
using namespace std;



int menu();             //prototypy funkcji
void f1();
void f2();
void f3();




//****************************funkcja main**************************************
int main()
{
int p;

do
{
p=menu();

switch(p)
{
 case 1:
 {
  f1();
  break;
 }
 
 case 2:
 {
  f2();
  break;
 }
 
  case 3:
 {
  f3();
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
cout<<"\n1 - funkcja nr 1";
cout<<"\n2 - funkcja nr 2";
cout<<"\n3 - funkcja nr 3";
cout<<"\n0 - zakoncz program\n\n";

do
{
 cin>>odp;
}
while(odp<0 || odp>3);
return odp;
}
//****************************menu programu*************************************



//****************************funkcja numer 1***********************************
void f1()
{
     cout<<"\n\nWykonano funkcje nr 1\n\n";
}
//****************************funkcja numer 1***********************************




//****************************funkcja numer 2***********************************
void f2()
{
     cout<<"\n\nWykonano funkcje nr 2\n\n";
}
//****************************funkcja numer 2***********************************



//****************************funkcja numer 3***********************************
void f3()
{
     cout<<"\n\nWykonano funkcje nr 3\n\n";
}
//****************************funkcja numer 3***********************************

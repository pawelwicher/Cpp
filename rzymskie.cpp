/*
Konwersja liczby arabskiej na rzymska
*/

#include <iostream>

using namespace std;

int main()
{
int liczba,nr,nom; 
char end;

do
{
cout<<"Podaj liczbe naturalna\n";
cin>>liczba;
cout<<"\n\n";

for(nr=1;nr<=13;nr++)
{
 switch(nr)
  {
  case 1: nom=1000; break;
  case 2: nom=900; break;
  case 3: nom=500; break;
  case 4: nom=400; break;
  case 5: nom=100; break;
  case 6: nom=90; break;
  case 7: nom=50; break;
  case 8: nom=40; break;
  case 9: nom=10; break;
  case 10: nom=9; break;
  case 11: nom=5; break;
  case 12: nom=4; break;
  case 13: nom=1; break;
  }
 while(liczba>=nom)
 {
  switch(nom)
  {
  case 1000: cout<<"M";break;
  case 900: cout<<"CM";break;
  case 500: cout<<"D";break;
  case 400: cout<<"CD";break;
  case 100: cout<<"C";break;
  case 90: cout<<"XC";break;
  case 50: cout<<"L";break;
  case 40: cout<<"XL";break;
  case 10: cout<<"X";break;
  case 9: cout<<"IX";break;
  case 5: cout<<"V";break;
  case 4: cout<<"IV";break;
  case 1: cout<<"I";break;
  }
 liczba-=nom; 
 }
}
cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}

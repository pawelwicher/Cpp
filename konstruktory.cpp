#include <iostream>
using namespace std;

class Klasa
{
public:
int x;
Klasa(int);
void Dodaj(); 
};

Klasa::Klasa(int a=0){x=a;}
void Klasa::Dodaj(){x++;}

int main()
{
void (Klasa::*ptr)();
ptr=&Klasa::Dodaj;    
    
Klasa *wsk=new Klasa;

cout<<wsk->x<<"\n";
(wsk->*ptr)();
cout<<wsk->x<<"\n";

cout<<"\n\n";
system("pause");
}

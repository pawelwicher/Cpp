#include <iostream>
#include <conio.h>

using namespace std;

class WYJATEK      // klasa ABSTRAKCYJNA
{
public:
virtual void Wypisz()=0;
virtual ~WYJATEK(){};
};

class DZ: public WYJATEK // dzielenie zera
{
public:
void Wypisz()
{
cout<<"Blad typu dzielenie zerem!";
}
};


class DPZ: public WYJATEK // dzielenie przez zero
{
public:
void Wypisz()
{
cout<<"Blad typu dzielenie przez zero!";
}
};

double Podziel(double x, double y) throw (DPZ,DZ)
{
if (x==0)
  {
   DZ ob;
   throw ob;
  }
if (y==0)
  {
   DPZ ob;
   throw ob;
  }
return x/y;
}




int main()
{

try
{
  Podziel(1,2);
  Podziel(0,1);
  Podziel(1,0);
}

catch (WYJATEK &wy)
{
  cout<<"Wystapil wyjatek: ";
  wy.Wypisz();
}

getch();
}

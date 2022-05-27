#include <iostream>
using namespace std;

//przeciazanie operatorow - algebra Boola

class Zmienna
{
public:
bool wartosc;

void operator=(bool);
Zmienna operator+(Zmienna);
Zmienna operator*(Zmienna);
Zmienna operator~();
ostream &operator<<(ostream&);       
};



void Zmienna::operator=(bool wartosc)
{this->wartosc=wartosc;}

Zmienna Zmienna::operator+(Zmienna z)
{Zmienna wynik; wynik=this->wartosc || z.wartosc; return wynik;}

Zmienna Zmienna::operator*(Zmienna z)
{Zmienna wynik; wynik=this->wartosc && z.wartosc; return wynik;}

Zmienna Zmienna::operator~()
{Zmienna wynik; wynik=!this->wartosc; return wynik;}

ostream &operator<<(ostream &wyjscie,Zmienna z)         
{wyjscie<<z.wartosc; return wyjscie;}


int main()
{
Zmienna a,b,c;

a=1;
b=1;
c=0;
cout<<"a="<<a<<"\n";
cout<<"b="<<b<<"\n";
cout<<"c="<<c<<"\n";
cout<<"a+b="<<a+b<<"\n";
cout<<"a*b="<<a*b<<"\n";
cout<<"~c="<<~c<<"\n";
cout<<"a*~(b+c)="<<a*~(b+c)<<"\n";

cout<<"\n\n";
system("pause");
}

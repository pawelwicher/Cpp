#include <iostream>
#include <math.h>
using namespace std;

class Ulamek
{
private:
    int licznik,mianownik;
    int NWD(int,int);
    void Normalizuj();
public:
    Ulamek(int l,int m){licznik=l; mianownik=m; this->Normalizuj();}
    Ulamek(const Ulamek&);
    void Przypisz(int l,int m){licznik=l; mianownik=m; this->Normalizuj();}
    int Licznik(){return licznik;}
    int Mianownik(){return mianownik;}
    Ulamek Odwrotnosc();
    Ulamek operator+(Ulamek);
    Ulamek operator-(Ulamek);
    Ulamek operator*(Ulamek);
    Ulamek operator/(Ulamek);
    ostream &operator<<(ostream&);       
};



Ulamek::Ulamek(const Ulamek &u)
{
licznik=u.licznik;
mianownik=u.mianownik;
}


int Ulamek::NWD(int a,int b)
{
a=abs(a);
b=abs(b);
while(a!=b)
if(a>b) a-=b; else b-=a;
return a;
}


void Ulamek::Normalizuj()
{
if(!licznik || !mianownik){licznik=0; mianownik=1;}
if(mianownik<0){licznik*=-1; mianownik*=-1;}
int nwd=NWD(licznik,mianownik);
licznik/=nwd; mianownik/=nwd;
}


Ulamek Ulamek::Odwrotnosc()
{
Ulamek wynik(1,1);
wynik.licznik=this->mianownik;
wynik.mianownik=this->licznik;
return wynik;
}


Ulamek Ulamek::operator+(Ulamek u)
{
Ulamek wynik(1,1);
wynik.mianownik=this->mianownik*u.mianownik;
wynik.licznik=this->mianownik*u.licznik+u.mianownik*this->licznik;
wynik.Normalizuj();
return wynik;
}


Ulamek Ulamek::operator-(Ulamek u)
{
Ulamek wynik(1,1);
wynik.mianownik=this->mianownik*u.mianownik;
wynik.licznik=u.mianownik*this->licznik-this->mianownik*u.licznik;
wynik.Normalizuj();
return wynik;
}


Ulamek Ulamek::operator*(Ulamek u)
{
Ulamek wynik(1,1);
wynik.licznik=this->licznik*u.licznik;
wynik.mianownik=this->mianownik*u.mianownik;
wynik.Normalizuj();
return wynik;
}


Ulamek Ulamek::operator/(Ulamek u)
{
Ulamek wynik(1,1),tmp(1,1);
tmp=u.Odwrotnosc();
wynik=*this*tmp;
return wynik;      
}


ostream &operator<<(ostream &wyjscie,Ulamek u)         
{
wyjscie<<u.Licznik()<<"/"<<u.Mianownik()<<"\n";
return wyjscie;
}




int main()
{
Ulamek k(1,2),l(1,4),u(1,1);

u=k+l; cout<<u;
u=k-l; cout<<u;
u=k*l; cout<<u;
u=k/l; cout<<u;

system("pause");
}

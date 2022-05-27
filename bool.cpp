#include <iostream>
using namespace std;

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




void Zamien(int,Zmienna[4]);


int main()
{
Zmienna t[4];




for(int i=0; i<16; i++)
{
Zamien(i,t);
for(int j=0; j<4; j++)
cout<<t[j]<<" ";
cout<<"  F(abcd)="<<~(~(~(t[0]+t[1])+~t[2])+t[3])<<"\n";
}




system("pause");
}


void Zamien(int x,Zmienna t[4])
{
int i=8,p=0;
    do
    {    
    if(x>=i) {t[p]=1; x-=i; i/=2;}
    else {t[p]=0; i/=2;}
    p++;
    }
    while(i);    
}




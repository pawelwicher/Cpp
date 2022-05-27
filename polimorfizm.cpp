#include <iostream>
using namespace std;

class Rodzic
{
protected:
string imie;          
public:
//metoda wirtualna - jest zastapiona klasach potomnych innymi metodami
virtual void Pisz();
};

void Rodzic::Pisz()
{cout<<"Rodzic\n";}


class Syn : public Rodzic
{
public:
void Pisz();
};

void Syn::Pisz()
{cout<<"Syn\n";}


class Corka : public Rodzic
{
public:
void Pisz();
};

void Corka::Pisz()
{cout<<"Corka\n";}



int main()
{
Rodzic *syn=new Syn;
Rodzic *corka=new Corka;
Rodzic *tab[2];


tab[0]=syn;
tab[1]=corka;

for(int i=0;i<2;i++)
tab[i]->Pisz();

cout<<"\n\n";
system("pause");
}

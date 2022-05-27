#include <iostream>
using namespace std;


class WyjatekDzieleniaPrzezZero
{
const char* komunikat;

public:
WyjatekDzieleniaPrzezZero(): komunikat("Dzielenie przez 0"){}
const char* jaki() const{return komunikat;}
};

double iloraz(int dzielna,int dzielnik)
{
if(dzielnik==0){WyjatekDzieleniaPrzezZero ob; throw ob;}
return (double)(dzielna)/(double)(dzielnik);
}

int main()
{
int a,b;
double wynik=0;

cin>>a>>b;

try
{
wynik=iloraz(a,b);
cout<<wynik;
}
catch(WyjatekDzieleniaPrzezZero wy)
{
cout<<"Wystapil wyjatek: "<<wy.jaki();
}


system("pause");
}

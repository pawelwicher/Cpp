#include <iostream>
#include <string>
using namespace std;


class Pracownik{
public:
Pracownik(const char*,const char*);
~Pracownik();
const char *podajImie() const;
const char *podajNazwisko() const;
virtual double dochody() const=0;
virtual void drukuj() const;

private:
char *Imie;
char *Nazwisko;
};

class Kierownik : public Pracownik{
public:
Kierownik(const char*,const char*,double=0.0);
void podajPlaceTygodniowa(double);
virtual double dochody() const;
virtual void drukuj() const;

private:
double PlacaTygodniowa;
};

class PracownikP : public Pracownik{
public:
PracownikP(const char*,const char*,double=0.0,double=0.0,int=0);
void ustawPlace(double);
void ustawProwizje(double);
void ustawIlosc(int);
virtual double dochody() const;
virtual void drukuj() const;

private:
double stawka;
double prowizja;
int ilosc;
};

//**************** PRACOWNIK ********************************
Pracownik::Pracownik(const char *im,const char *nazw)
{
Imie=new char[strlen(im)+1];
strcpy(Imie,im);
Nazwisko=new char[strlen(nazw)+1];
strcpy(Nazwisko,nazw);                   
}

Pracownik::~Pracownik()
{
delete Imie;
delete Nazwisko;                       
}

const char *Pracownik::podajImie() const{return Imie;}

const char *Pracownik::podajNazwisko() const{return Nazwisko;}

void Pracownik::drukuj() const{cout<<Imie<<" "<<Nazwisko<<"\n";}

//**************** KIEROWNIK ********************************

Kierownik::Kierownik(const char *im,const char *nazw,double s) : Pracownik(im,nazw)
{podajPlaceTygodniowa(s);}

void Kierownik::podajPlaceTygodniowa(double s){PlacaTygodniowa=s>0?s:0;}

double Kierownik::dochody() const {return PlacaTygodniowa;}

void Kierownik::drukuj() const
{
cout<<"Kierownik: ";
Pracownik::drukuj();
}


//**************** PRACOWNIK PROWIZYJNY **********************

PracownikP::PracownikP(const char *im,const char *nazw,double s,double c,int q) : Pracownik(im,nazw)
{
ustawPlace(s);
ustawProwizje(c);
ustawIlosc(q);
}

void PracownikP::ustawPlace(double s){stawka=s>0?s:0;}

void PracownikP::ustawProwizje(double c){prowizja=c>0?c:0;}

void PracownikP::ustawIlosc(int q){ilosc=q>0?q:0;}

double PracownikP::dochody() const {return stawka+prowizja*ilosc;}

void PracownikP::drukuj() const
{
cout<<"Pracownik prowizyjny: ";
Pracownik::drukuj();     
}


int main()
{
Kierownik K("Piotr","Nowak");
PracownikP PP("Jan","Kowalski");


Pracownik *P;

P=&K;
P->drukuj();

P=&PP;
P->drukuj();




system("pause");
}


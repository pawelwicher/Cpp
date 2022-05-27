#include <iostream>
#include <string>
using namespace std;

class Wektor{
private:
char nazwa[10];
float *tab;
int wymiar;
public:
Wektor(){strcpy(nazwa,"1"); wymiar=1; tab=new float[wymiar]; tab[0]=0;}
Wektor(char naz[],int wym)
{strcpy(nazwa,naz); wymiar=wym; tab=new float[wymiar];
for(int i=0;i<wymiar;i++) tab[i]=0;}
~Wektor(){delete []tab;}
friend istream &operator>>(istream&,Wektor&);
friend ostream &operator<<(ostream&,Wektor&);
Wektor& operator=(Wektor&);
Wektor& operator+(Wektor&);
Wektor& operator-(Wektor&);
Wektor& operator+(float);
Wektor& operator-(float);
Wektor& operator*(Wektor&);
};


istream &operator>>(istream &in,Wektor &W)
{
for(int i=0;i<W.wymiar;i++){cout<<W.nazwa<<"["<<i+1<<"]="; in>>W.tab[i];}
return in;	
}

ostream &operator<<(ostream &out,Wektor &W)
{
out<<W.nazwa<<"=[ ";
for(int i=0;i<W.wymiar;i++) out<<W.tab[i]<<" ";
out<<"]\n";
return out;	
}

Wektor& Wektor::operator=(Wektor &W)
{
if(wymiar!=W.wymiar) cout<<"Konflikt wymiarow\n";
else for(int i=0;i<wymiar;i++) tab[i]=W.tab[i];
}

Wektor& Wektor::operator+(Wektor &W)
{
Wektor *TEMP=new Wektor("TEMP",wymiar);
if(wymiar!=W.wymiar) cout<<"Konflikt wymiarow\n";
else {for(int i=0;i<wymiar;i++) (*TEMP).tab[i]=tab[i]+W.tab[i]; return *TEMP;}
}

Wektor& Wektor::operator-(Wektor &W)
{
Wektor *TEMP=new Wektor("TEMP",wymiar);
if(wymiar!=W.wymiar) cout<<"Konflikt wymiarow\n";
else {for(int i=0;i<wymiar;i++) (*TEMP).tab[i]=tab[i]-W.tab[i]; return *TEMP;}
}

Wektor& Wektor::operator+(float liczba)
{
Wektor *TEMP=new Wektor("TEMP",wymiar);
for(int i=0;i<wymiar;i++) (*TEMP).tab[i]=liczba;
return *this+*TEMP;
}

Wektor& Wektor::operator-(float liczba)
{
Wektor *TEMP=new Wektor("TEMP",wymiar);
for(int i=0;i<wymiar;i++) (*TEMP).tab[i]=liczba;
return *this-*TEMP;
}


Wektor& Wektor::operator*(Wektor &W)
{
Wektor *TEMP=new Wektor("TEMP",wymiar);
if(wymiar!=W.wymiar) cout<<"Konflikt wymiarow\n";
else {for(int i=0;i<wymiar;i++) (*TEMP).tab[i]=tab[i]*W.tab[i]; return *TEMP;}
}

int main()
{
Wektor A("Alfa",2),B("B",2),C("C",2),Wynik("Wynik",2);

cout<<A;
cout<<B;
cout<<C;

cin>>A;
cin>>B;
cin>>C;

cout<<A;
cout<<B;
cout<<C;

Wynik=A+B+C;
cout<<Wynik;

system("pause");
}


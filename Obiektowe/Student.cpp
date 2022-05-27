#include <iostream>
#include <string>
using namespace std;

class STUDENT
{
//private:
public:
char *imie;
char *nazwisko;
int rok;
char indeks[7];

//public:
STUDENT();
STUDENT(char*,char*,int,char[]);
~STUDENT();
STUDENT(const STUDENT&);
friend istream &operator>>(istream&,STUDENT&);
friend ostream &operator<<(ostream&,STUDENT&);
//void operator=(bool);
};

STUDENT::STUDENT()
{
imie=NULL;
nazwisko=NULL;
rok=0;
strcpy(indeks,"0000000");
}

STUDENT::STUDENT(char *im,char *naz,int r,char i[])
{
imie=new char[strlen(im)+1];
strcpy(imie,im);
nazwisko=new char[strlen(naz)+1];
strcpy(nazwisko,naz);
rok=r;
strcpy(indeks,i);
}

STUDENT::~STUDENT()
{
delete []imie;
delete []nazwisko;                   
}

STUDENT::STUDENT(const STUDENT &S)
{
imie=new char[strlen(S.imie)+1];
strcpy(imie,S.imie);
nazwisko=new char[strlen(S.nazwisko)+1];
strcpy(nazwisko,S.nazwisko);
rok=S.rok;
strcpy(indeks,S.indeks);
cout<<"kopiuje\n";
}

istream &operator>>(istream &in,STUDENT &s)
{

}

ostream &operator<<(ostream &out,STUDENT &s)
{
return out<<"\n"<<s.imie<<" "<<s.nazwisko<<" rok:"<<s.rok<<" nr indeksu: "<<s.indeks;
}

int main()
{
STUDENT s("Piotr","Nowak",4,"102030"); 
STUDENT s1=s;

cout<<s1<<s;

cout<<"\n";
system("pause");
}

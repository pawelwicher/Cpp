#include <iostream.h>
#include <conio.h>

using namespace std;


struct ElementStosu
{
int liczba;      
ElementStosu* poprzedni;
};

typedef ElementStosu* Stos;


void NaStos(Stos&,int);
void ZeStosu(Stos&);


int main()
{
Stos Top=NULL;
char znak;
int liczba;

    do 
    {
    system("cls");
    cout<<"Wybierz jedna z dostepnych opcji:\n";
    cout<<"\n[1] - Na stos";
    cout<<"\n[2] - Ze stosu";
    cout<<"\n[0] - Koniec";     
    cout<<"\n\n->";
    znak=getche();
    system("cls");
        switch(znak)
        {
        case '1':
        cout<<"Podaj liczbe: "; cin>>liczba; NaStos(Top,liczba); break;
        case '2':
        ZeStosu(Top); getch(); break;        
        }
    }
    while(znak!='0');
}


void NaStos(Stos &Top,int liczba)
{
Stos E=new ElementStosu;
E->liczba=liczba;
E->poprzedni=Top;
Top=E;
}

void ZeStosu(Stos &Top)
{
Stos E;
int liczba;
    if(Top==NULL)
    {cout<<"Stos pusty";}
    else
    {
    liczba=Top->liczba;
    E=Top;
    Top=Top->poprzedni;
    delete(E);
    cout<<liczba;
    }
}

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct Wezel
{
int liczba;
int lw;
Wezel* lewy;
Wezel* prawy;
};

typedef Wezel* wsk;
int i=0;

void menu();
void Dolacz(wsk&,int);
void InOrder(wsk);
int LiczWezly(wsk);
void Klucze(wsk,int);
void Rysuj(wsk,int,int);
int Kwadrat(int,int);
void gotoxy(int x, int y);

int main()
{
char z;
wsk korzen=NULL;
int liczba;
int lw;
menu();
    while(z!='0')
    {
    cout<<"\n\n->";
    z=getche();
    system("cls");
        switch(z)
        {
        case '1':
        cout<<"Wpisz klucz wezla: "; cin>>liczba;
        Dolacz(korzen,liczba); break;
        case '2':
        InOrder(korzen);getch(); break;
        case '3':
        Rysuj(korzen,40,1);getch(); break;
        case '4':
        lw=LiczWezly(korzen); Klucze(korzen,lw);getch(); break;        
        }
    menu();
    }

}



void menu()
{
system("cls");
cout<<"Wybierz jedna z dostepnych opcji:\n";
cout<<"\n[1] - Dodaj wezel do drzewa";
cout<<"\n[2] - Wyswietl drzewo";
cout<<"\n[3] - Rysuj drzewo";
cout<<"\n[4] - Funkcja z kola";
cout<<"\n[0] - Koniec";     
}


void Dolacz(wsk &wb,int liczba)
{
    if (wb==NULL)
    {
        wb=new Wezel;
        wb->lewy=NULL;
        wb->prawy=NULL;
        wb->liczba=liczba;
    }
    else
        if(liczba<wb->liczba)
        Dolacz(wb->lewy,liczba);
        else Dolacz(wb->prawy,liczba);
}

void InOrder(wsk wb)
{
    if(wb)
    {
    InOrder(wb->lewy);
    cout<<wb->liczba<<" ";
    InOrder(wb->prawy);
    }
}

void Klucze(wsk wb,int lw)
{
    if(wb)
    {
    Klucze(wb->lewy,lw);
    i++;
    wb->lw=lw-i;
    Klucze(wb->prawy,lw);
    }
}


int LiczWezly(wsk wb)
{ 
    if(wb) return LiczWezly(wb->lewy)+LiczWezly(wb->prawy)+1;
    else return 0;
}

void Rysuj(wsk wb,int x,int poziom)
{
  int y=poziom;
  int k=80/Kwadrat(2, poziom+1);
  
  if(wb)
  {
  gotoxy(x,y);
  cout<<wb->liczba<<","<<wb->lw;
  
  
  if (wb->prawy)
  Rysuj(wb->prawy,x+k,poziom+1);
  
  if (wb->lewy)
  Rysuj(wb->lewy,x-k,poziom+1);
  }
  
}

int Kwadrat(int x, int n)
{
  if (n==1)
    return (x);
  else return (x*Kwadrat(x, n-1));
}

void gotoxy(int x, int y) 
{ 
   COORD coord; 
   coord.X = x; 
   coord.Y = y; 
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
} 

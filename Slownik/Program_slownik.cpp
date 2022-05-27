#include "Slownik.h"

/*
slownik polsko-angielski
*/


int main()
{
char znak;
wsk korzen=NULL;
OdczytajDrzewo(korzen);

    do 
    {
    system("cls");
    cout<<"Wybierz jedna z dostepnych opcji:\n";
    cout<<"\n[1] - Dodaj do slownika";
    cout<<"\n[2] - Wyswietl slownik";
    cout<<"\n[3] - Ksztalt drzewa slownika";
    cout<<"\n[4] - Szukaj slowa"; 
    cout<<"\n[5] - PreOrder";
    cout<<"\n[6] - InOrder";
    cout<<"\n[7] - PastOrder";
    cout<<"\n[8] - Parametry drzewa";
    cout<<"\n[0] - Koniec";     
    cout<<"\n\n->";
    znak=getche();
    system("cls");
        switch(znak)
        {
        case '1':
        DolaczSlowo(korzen); getch(); break;
        case '2':
        WyswietlAlfabetycznie(korzen); getch(); break;
        case '3':
        Rysuj(korzen,40,1); getch(); break;
        case '4':
        WyszukajSlowo(korzen); getch(); break;
        case '5':
        PreOrder(korzen); getch(); break;
        case '6':
        InOrder(korzen); getch(); break;   
        case '7':
        PostOrder(korzen); getch(); break;  
        case '8':
        ParametryDrzewa(korzen); getch(); break;           
        }
    }
    while(znak!='0');

ZapiszDrzewo(korzen);
}

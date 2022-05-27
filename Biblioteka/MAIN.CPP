#include "plik_tex.h"

void menu()
{
system("cls");
cout<<"Wybierz jedna z dostepnych opcji:";
cout<<"\n[1] - Dopisz rekord";
cout<<"\n[2] - Wyswietl rekordy";
cout<<"\n[3] - Aktualizuj rekord";
cout<<"\n[4] - Wyszukaj rekord";
cout<<"\n[5] - Wykaz rekordow";
cout<<"\n[6] - Histogram kategorii";
cout<<"\n[7] - Histogram liczby wypozyczen 1";
cout<<"\n[8] - Histogram liczby wypozyczen 2";
cout<<"\n[9] - Wezwanie do zwrotu";
cout<<"\n[0] - Koniec";     
}

int main()
{ 
char z;    
    menu();
    while(z!='0')
    {
    cout<<"\n\n->";
    cin>>z;
    system("cls");
        switch(z)
        {
        case '1':
        Dopisz_rekord(); break;
        case '2':
        Wyswietl_rekordy(); break;
        case '3':
        Aktualizuj(); break;
        case '4':
        Wyszukaj(); break;
        case '5':
        Wykaz(); break;
        case '6':
        Histogram_kategorii(); break;
        case '7':
        Histogram_liczby_wypozyczen1(); break;
        case '8':
        Histogram_liczby_wypozyczen2(); break;
        case '9':
        Wezwanie_do_zwrotu(); break;
        }
    menu();
    }
}

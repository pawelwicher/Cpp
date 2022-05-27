#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void menu();



int main()
{

menu();




}


void menu()
{
char z;
while(z!='0')
    {
    system("cls");
    cout<<"Menu glowne\n\n";
    cout<<"[1] - Administrator\n";
    cout<<"[2] - Student\n";
    cout<<"[3] - Pracownik\n";
    cout<<"[0] - Koniec\n";
    cout<<"\n\n->";
    z=getche();
    system("cls");
        switch(z)
        {
            case '1':
            while(z!='0')
            {
            system("cls");
            cout<<"Menu glowne->Administrator\n\n";
            cout<<"[1] - Kurs\n";
            cout<<"[2] - Student\n";
            cout<<"[3] - Pracownik\n";
            cout<<"[0] - Powrot\n";
            cout<<"\n\n->";
            z=getche();
            system("cls");
            switch(z)
            {
            case '1':
                while(z!='0')
                {
                system("cls");
                cout<<"Menu glowne->Administrator->Kurs\n\n";
                cout<<"[1] - Dodaj kurs\n";
                cout<<"[2] - Aktualizuj kurs\n";
                cout<<"[3] - Usun kurs\n";
                cout<<"[4] - Przegladaj liste kursow\n";
                cout<<"[5] - Wyszukaj kurs\n";
                cout<<"[6] - Przypisz pracownika\n";
                cout<<"[0] - Powrot\n";
                cout<<"\n\n->";
                z=getche();
                system("cls");
                switch(z)
                {
                case '1':
                break;
                case '2':
                break;
                case '3':
                break;
                case '4':
                break;
                case '5':
                break; 
                case '6':
                break;       
                }     
                }
                z='9';                      
            break;
            
            case '2':
                 while(z!='0')
                {
                system("cls");
                cout<<"Menu glowne->Administrator->Student\n\n";
                cout<<"[1] - Dodaj studenta\n";
                cout<<"[2] - Aktualizuj studenta\n";
                cout<<"[3] - Usun studenta\n";
                cout<<"[4] - Przegladaj liste studentow\n";
                cout<<"[5] - Wyszukaj studenta\n";
                cout<<"[0] - Powrot\n";
                cout<<"\n\n->";
                z=getche();
                system("cls");
                switch(z)
                {
                case '1':
                break;
                case '2':
                break;
                case '3':
                break;
                case '4':
                break;
                case '5':
                break;       
                }     
                }
                z='9';                      
            break;
            
            case '3':
                 while(z!='0')
                {
                system("cls");
                cout<<"Menu glowne->Administrator->Pracownik\n\n";
                cout<<"[1] - Dodaj pracownika\n";
                cout<<"[2] - Aktualizuj pracownika\n";
                cout<<"[3] - Usun pracownika\n";
                cout<<"[4] - Przegladaj liste pracownikow\n";
                cout<<"[5] - Wyszukaj pracownika\n";
                cout<<"[0] - Powrot\n";
                cout<<"\n\n->";
                z=getche();
                system("cls");
                switch(z)
                {
                case '1':
                break;
                case '2':
                break;
                case '3':
                break;
                case '4':
                break;
                case '5':
                break;       
                }     
                }
                z='9';      
                 
            break;      
            }     
            }
            z='9';                
            break;
            
            case '2':
            while(z!='0')
            {
            system("cls");
            cout<<"Menu glowne->Student\n\n";
            cout<<"[1] - Zapis\n";
            cout<<"[2] - Rezygnacja\n";
            cout<<"[3] - Dostepne kursy\n";
            cout<<"[4] - Kursy studenta\n";
            cout<<"[0] - Powrot\n";
            cout<<"\n\n->";
            z=getche();
            system("cls");
            switch(z)
            {
            case '1':
            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
            break;      
            }     
            }
            z='9';  
            break;
            
            case '3':
            while(z!='0')
            {
            system("cls");
            cout<<"Menu glowne->Pracownik\n\n";
            cout<<"[1] - Kursy pracownika\n";
            cout<<"[0] - Powrot\n";
            cout<<"\n\n->";
            z=getche();
            system("cls");
            switch(z)
            {
            case '1':
            break;
            case '2':
            break;     
            }     
            }
            z='9';  
            break;          
        }     
     }
}




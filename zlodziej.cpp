#include <iostream> 
#include <ctime> 
using namespace std; 


void los(int&,int&); 

int main()
{
int wrzut;
int bet;
char end,odp='t';

srand ((int) time(NULL)); 


cout<<"Ile kredytow chcesz zainwestowac? ";
cin>>wrzut;

    do
    {
    system("cls");
    cout<<"Kredyty: "<<wrzut;
    
        do
        {
        cout<<"\nZa jaka stawke chcesz zagrac? ";
        cin>>bet;
        if(bet>wrzut)
            { 
            cout<<"\nNiestety nie masz tylu kredytow, podaj nizsza stawke";
            }
        }
        while(bet>wrzut);
        
        cout<<"\n";
        
        do
        {
        los(bet,wrzut);
            if(!bet)
                {
                cout<<"Przegrales. Kredyty: "<<wrzut<<"\n";
                }
            else
                {                
                cout<<"Wygrales !!!. Nowa stawka: "<<bet<<". Kredyty: "<<wrzut<<"\nPodbijasz [t/n]? ";
                do
                {
                    cin>>odp;
                    if(odp!='t' && odp!='n') cout<<"[t/n]? ";
                    else break;
                }
                while(1);
                if(odp=='n') break;
                }
        }
        while(bet>0 && odp=='t');
           
    cout<<"\nKoniec gry - wcisnij q\n";
    cout<<"Dowolny klawisz - kontynuacja ";
    cin>>end;
    cout<<"\n";
        if(end=='q') 
            {
            if(!wrzut)
                {
                cout<<"\nKoniec gry, brak kredytow. Dziekuje.\n";
                system("pause");
                }
            else
                {
                cout<<"\nKoniec gry, Kredyty: "<<wrzut<<". Dziekuje.\n";
                system("pause");
                }
            }

        if(!wrzut && end!='q')
        {
        end='q';
        cout<<"\nKoniec gry, brak kredytow. Dziekuje.\n";
        system("pause");
        }
                        
    } 
    while(end!='q' && wrzut>0);    
}




void los(int &stawka,int &kredyty)
{
kredyty-=stawka; 
if(rand()%2) {stawka*=2; kredyty+=stawka;}
else stawka=0; 
} 


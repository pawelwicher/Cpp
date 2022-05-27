//Program tablica 2wym - tworzona dynamicznie
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

char menu();
void Kopiuj(int **,int **,int,int);

int main()
{
int **t,**t1;
int i,j,w,k,nrw,nrk;
char p;

w=5;   //poczatkowa wielkosc macierzy (3x3)
k=5;

t = new int *[w];
for(i=0; i<w; i++)
t[i] = new int[k];
for(i=0;i<w;i++)
for(j=0;j<k;j++)
t[i][j]=9;                         //poczatkowe wartosci elementow macierzy (wszystkie rowne 0)
cout<<"Utworzono macierz\n";
system("pause");
system("cls"); 


    do
    {
    p=menu();
        switch(p)
        {
            case '1':              //wyswietlanie macierzy
            {
            for(int i=0;i<w;i++)
            {   
            for(int j=0;j<k;j++)
            cout<<setw(3)<<t[i][j]; 
            cout<<"\n";   
            }
            system("pause");
            system("cls"); 
            break;
            }
            
            case '2':
            {
            system("cls");
            cout<<"Podaj numer wiersza, ktory chcesz wypelnic\n->";
            cin>>nrw;
            if(nrw>0 && nrw<w+1)        //sprawdzenie poprawnosci wczytywanej liczby
            {
            for(i=0;i<k;i++)
            {cout<<"a["<<nrw<<"]["<<i+1<<"]="; cin>>t[nrw-1][i];} //wypelnianie
            }
            else
            cout<<"Nie ma takiego wiersza.\n";
            system("pause");
            system("cls");
            break;
            }
             
            case '3':       //wszytstko analaogicznie jak w 'case 2'
            {
            system("cls");
            cout<<"Podaj numer kolumny, ktora chcesz wypelnic\n->";
            cin>>nrk;
            if(nrk>0 && nrk<k+1)
            {
            for(i=0;i<w;i++)
            {cout<<"a["<<nrk<<"]["<<i+1<<"]="; cin>>t[i][nrk-1];}
            }
            else
            cout<<"Nie ma takiej kolumny.\n";
            system("pause");
            system("cls");
 
            break;
            }
            
            case '4':
            {
                t1 = new int *[w];
                for(i=0; i<w; i++)
                t1[i] = new int[k];
                for(i=0;i<w;i++)             //tworzenie tablicy pomocniczej (kopii)
                for(j=0;j<k;j++)             //wyzerowanie macierzy (zeby nie bylo smieci) czesto powtarzana operacja
                t1[i][j]=0;
                
                Kopiuj(t1,t,w,k);            //kopiowanie tablicy glownej - t do tablicy pomocniczej t1
                for(i=0;i<w;i++)
                delete[] t[i];               //niszczenie t
                delete[] t;
                
                w++;                         //zwiekszenie licznika wierszy
                
                t = new int *[w];
                for(i=0; i<w; i++)
                t[i] = new int[k];           //tworzenie nowej macierzy t z jedym wierszem wiecej
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t[i][j]=0;
                
                Kopiuj(t,t1,w-1,k);          //kopiowanie danych zachowanych w t1 do t1
                for(i=0;i<w-1;i++)
                delete[] t1[i];
                delete[] t1;
                
                system("cls");
                cout<<"Wiersz dodany.\n";
                system("pause");
                system("cls"); 
                break;
            }

            
            case '5':
            {
                t1 = new int *[w];           //analogicznie jak poprzednio tyle ze z kolumnami
                for(i=0; i<w; i++)
                t1[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t1[i][j]=0;
                
                Kopiuj(t1,t,w,k);
                for(i=0;i<w;i++)
                delete[] t[i];
                delete[] t;
                
                k++;
                
                t = new int *[w];
                for(i=0; i<w; i++)
                t[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t[i][j]=0;
                
                Kopiuj(t,t1,w,k-1);
                for(i=0;i<w;i++)
                delete[] t1[i];
                delete[] t1;
                
                system("cls");
                cout<<"Kolumna dodana.\n";
                system("pause");
                system("cls");
                break;
            }
            
            case '6':
            {
            system("cls");
            cout<<"Podaj numer wiersza, ktory chcesz usunac\n->";
            cin>>nrw;
            if(nrw>0 && nrw<w+1)
            {
            
                t1 = new int *[w];
                for(i=0; i<w; i++)
                t1[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t1[i][j]=0;
                
                Kopiuj(t1,t,w,k);
                for(i=0;i<w;i++)
                delete[] t[i];
                delete[] t;
                
                w--;                          //zmniejszenie licznika wierszy
                
                t = new int *[w];             //utworzenie nowej, mniejszej o 1 wiersz macierzy glownej
                for(i=0; i<w; i++)
                t[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t[i][j]=0;
                                
                for(i=nrw-1;i<w-1;i++)          //przesuniecie wszystkich wiersz ponizej tego usuwanego
                for(j=0;j<k;j++)              //o poziom wyzej; wymazanie wiersza, ktory mamy usunac
                t1[i][j]=t1[i+1][j];
                
                Kopiuj(t,t1,w,k);
                for(i=0;i<w+1;i++)
                delete[] t1[i];
                delete[] t1;
            
            }
            else
            cout<<"Nie ma takiego wiersza.\n";
            system("pause");
            system("cls");
            break;
            }
            
            case '7':
            {
            system("cls");
            cout<<"Podaj numer kolumny, ktora chcesz usunac\n->";
            cin>>nrk;
            if(nrk>0 && nrk<k+1)
            {
            
                t1 = new int *[w];            //wszystko to samo tylko dla kolumny
                for(i=0; i<w; i++)
                t1[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t1[i][j]=0;
                
                Kopiuj(t1,t,w,k);
                for(i=0;i<w;i++)
                delete[] t[i];
                delete[] t;
                
                k--;
                
                t = new int *[w];
                for(i=0; i<w; i++)
                t[i] = new int[k];
                for(i=0;i<w;i++)
                for(j=0;j<k;j++)
                t[i][j]=0;                
                               
                for(i=0;i<w;i++)
                for(j=nrk-1;j<k-1;j++)
                t1[i][j]=t1[i][j+1];
                
                Kopiuj(t,t1,w,k);
                for(i=0;i<w;i++)
                delete[] t1[i];
                delete[] t1;
            
            }
            else
            cout<<"Nie ma takiej kolumny.\n";
            system("pause");
            system("cls");
 
            break;
            }            

        }
    
    }
    while(p!='0');
}

//******************************************************************************
char menu()
{
char odp;

cout<<"1 - Wyswietl tablice";
cout<<"\n2 - Wprowadz wiersz";
cout<<"\n3 - Wprowadz kolumne";
cout<<"\n4 - Dodaj wiersz";
cout<<"\n5 - Dodaj kolumne";
cout<<"\n6 - Usun wiersz";
cout<<"\n7 - Usun kolumne";
cout<<"\n0 - Zakoncz program\n\n->";

do
odp=getche();
while(odp<'0' || odp>'7');
system("cls");
return odp;
}
//******************************************************************************
void Kopiuj(int **t1,int **t2,int w,int k)
{
int i,j;
for(i=0;i<w;i++)
for(j=0;j<k;j++)
t1[i][j]=t2[i][j];
}


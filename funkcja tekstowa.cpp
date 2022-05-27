#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

void FunkcjaTekstowa(char [],int);
void Wpisz(char [],int);


int main()
{
char napis[30];

    do
    {
        system("cls");
        cout<<"Wpisz swoj tekst\n->";
        Wpisz(napis,30);
        FunkcjaTekstowa(napis,30);
        cout<<"\nWynik: "<<napis;
        cout<<"\n\nKoniec - klawisz '0'";
    }
    while(getche()!='0');

}


void FunkcjaTekstowa(char t[],int n)
{
strlwr(t);
t[0]=toupper(t[0]);
    for(int i=0;i<strlen(t);i++)
        if(t[i]==' ') t[i+1]=toupper(t[i+1]);     
}


void Wpisz(char t[],int n)
{
	do
	{
        gets(t);
        if(strlen(t)>n)
        cout<<"Wpis moze zawierac maksymalnie "<<n<<" znakow. Wpisz ponownie\n";
	}
    while(strlen(t)>n);
fflush(stdin);
}

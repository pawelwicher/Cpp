#include "lista_1kc.h"


wL1kc InicjujGloweL1kc()
{
wL1kc Glowa=new Lista1kc;
Glowa->nast=Glowa;
return Glowa;
}

void DolaczL1kc(wL1kc &Glowa)
{
wL1kc E=new Lista1kc;
int klucz;

    cout<<"Podaj ID pozycji: "; cin>>klucz;

    while(klucz<=0)
    {cout<<"Blad - Podaj ID pozycji: "; cin>>klucz;}
    
    if(!SprawdzKluczL1kc(Glowa,klucz))
    {
    Wypelnij(E->daneK,klucz);    
    E->nast=Glowa->nast;
    Glowa->nast=E;       
    }
    else
    {
    cout<<"Blad - podany identyfikator nie jest unikatowy.";
    getch();
    }
}

void PrzegladajL1kc(wL1kc Glowa,wL1k Pocz)
{
wL1kc E=Glowa->nast;
while(E!=Glowa)
    {
    Wyswietl(E->daneK);
    if(E->daneK.id_pracownika) PrzegladajZKluczemL1k(Pocz,E->daneK.id_pracownika);
    E=E->nast;
    }
getch();
}

void PrzegladajZKluczemL1kc(wL1kc Glowa,wL1k Pocz,int kluczK,int kluczP)
{

wL1kc E=Glowa->nast;
while(E!=Glowa)
    {
    if(E->daneK.id==kluczK)
    {
    Wyswietl(E->daneK);
    if(E->daneK.id_pracownika) PrzegladajZKluczemL1k(Pocz,kluczP);
    break;
    }
    E=E->nast;
    }
}

void PrzypiszPracownikaL1kc(wL1kc Glowa,wL1k Pocz)
{
wL1kc E=Glowa->nast;  
int kluczP,kluczK,znal=0;

cout<<"Podaj id pracownika: "; cin>>kluczP;
if(SprawdzKluczL1k(Pocz,kluczP))
{
PrzegladajZKluczemL1k(Pocz,kluczP);

    cout<<"\n\nPodaj id kursu: ";
    cin>>kluczK;
    if(SprawdzKluczL1kc(Glowa,kluczK))
    {
        while(E!=Glowa)
            {
                if(E->daneK.id==kluczK)
                {
                PrzegladajZKluczemL1kc(Glowa,Pocz,kluczK,kluczP);
                cout<<"\n\nPrzypisac kurs? [t/n]: ";
                if(getche()=='t') {PrzypiszPracownika(E->daneK,kluczP); getch();}
                else {cout<<"\nKursu nie przypisano."; getch();}
                break;
                }
            E=E->nast;
            } 
    }
    else{cout<<"Nie ma pozycji o podanym id."; getch();}    
     
}
else
{
cout<<"\nNie ma pozycji o podanym id.";
getch();
}
    
}


void UsunL1kc(wL1kc &Glowa,int id_kursu)
{
wL1kc E=Glowa->nast,Pop=Glowa;

while(E!=Glowa)
    {
    if(E->daneK.id==id_kursu) break;
    Pop=E;
    E=E->nast;
    }  
    
    Pop->nast=E->nast;
    delete(E);
}
    
int SprawdzKluczL1kc(wL1kc Glowa,int klucz)
{
wL1kc E=Glowa->nast;
int znal=0;
while(E!=Glowa)
    {
    if(E->daneK.id==klucz){znal=1; break;}
    E=E->nast;
    }  
return znal;    
}     
     

void AktualizujL1kc(wL1kc Glowa,wL2kc GlowaL2kc)
{
wL1kc E=Glowa->nast;
int klucz,znal=0;

cout<<"Podaj id pozycji do aktualizacji: ";
cin>>klucz;

    if(!SprawdzZapisyL2kc(GlowaL2kc,klucz))
    {
        while(E!=Glowa)
            {
            if(E->daneK.id==klucz){znal=1; Wyswietl(E->daneK); AktualizujKurs(E->daneK);break;}
            E=E->nast;
            } 
        if(!znal){cout<<"\nNie ma pozycji o podanym id."; getch();}
        
    }
    else
    {
        cout<<"\nBlad - Wybranej pozycji nie mozna aktualizowac (kurs wybrany).";
        getch();   
    }
}

void WyszukajL1kc(wL1kc Glowa)
{
wL1kc E=Glowa->nast;
char nazwa[20];
int znal=0;

cout<<"\nPodaj nazwe kursu: "<<flush;
fflush(stdin);
gets(nazwa);

    while(E!=Glowa)
    {
    if(strstr(E->daneK.nazwa,nazwa)!=NULL){znal=1; Wyswietl(E->daneK);}
    E=E->nast;
    }     
if(!znal)cout<<"\nNie znaleziono zadnej pozycji";
getch();     
}


void ZapiszL1kc(wL1kc Glowa)
{
    FILE* wp;
    wL1kc E=Glowa->nast;
    if((wp=fopen("kursy.dat","wb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku 'pracownicy.dat'";
    getch();
    }
    else
    {        
        while(E!=Glowa)
        {
        fwrite(&E->daneK,sizeof(E->daneK),1,wp);
        E=E->nast;
        }
    fclose(wp);
    }    
}



void OdczytajL1kc(wL1kc &Glowa)
{
    wL1kc E,T=Glowa;
    FILE* wp;
    if((wp=fopen("kursy.dat","rb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku";
    getch();
    }
    else
    {
        while (!feof(wp))
        {
        E=new Lista1kc;
        
            if(fread(&(E->daneK),sizeof(Kurs),1,wp)==1)
            {
            T->nast=E;
            E->nast=Glowa;
            }
        T=E;
        }
    fclose(wp);
    }    
}

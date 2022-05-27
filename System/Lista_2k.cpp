#include "lista_2k.h"

void DolaczL2k(wL2k &Pocz,wL2k &Kon)
{
wL2k E;
int klucz;
E=new Lista2k;
    cout<<"Podaj ID pozycji (numer indeksu): "; cin>>klucz;

    while(klucz<=0)
    {cout<<"Blad - Podaj ID pozycji: "; cin>>klucz;}

    if(!SprawdzKluczL2k(Pocz,klucz))
    {
    Wypelnij(E->daneS,klucz);
    
        if(Pocz==NULL)
        {Pocz=E; Kon=E; E->nast=NULL; E->pop=NULL;}   
        else if(E->daneS.indeks<Pocz->daneS.indeks)
        {E->nast=Pocz; E->pop=NULL; Pocz->pop=E; Pocz=E;}    
        else if(E->daneS.indeks>Kon->daneS.indeks)
        {Kon->nast=E; E->nast=NULL; E->pop=Kon; Kon=E;}
        else
        {
        wL2k T,L;
        T=Pocz;    
        while(E->daneS.indeks>=T->daneS.indeks)
        {L=T; T=T->nast;}    
        E->nast=L->nast;
        E->pop=L;
        L->nast->pop=E;
        L->nast=E;      
        }
    }
    else
    {
    cout<<"Blad - podany identyfikator nie jest unikatowy.";
    getch();
    }
}


void PrzegladajL2k(wL2k Pocz)
{
wL2k E=Pocz;
    while(E!=NULL)
    {
    Wyswietl(E->daneS);
    E=E->nast;
    }
getch();
}

void PrzegladajZKluczemL2k(wL2k Pocz,int klucz)
{
wL2k E=Pocz;
    while(E!=NULL)
    {
    if(E->daneS.indeks==klucz){Wyswietl(E->daneS); break;}
    E=E->nast;
    }
getch();
}


void UsunL2k(wL2k &Pocz,wL2k &Kon,int id_studenta)
{
wL2k E=Pocz,Pop=NULL;

    while(E!=NULL)
    {
    if(E->daneS.indeks==id_studenta) break;
    Pop=E;
    E=E->nast;
    }
    
    if(E==Pocz)
    Pocz=E->nast;
    else if(E==Kon)
    {Pop->nast=NULL; Kon=Pop;}
    else
    {Pop->nast=E->nast; E->nast->pop=Pop;}
    delete(E);
}


int SprawdzKluczL2k(wL2k Pocz,int klucz)
{
wL2k E=Pocz;
int znal=0;
    while(E!=NULL)
    {
    if(E->daneS.indeks==klucz){znal=1; break;}
    E=E->nast;
    }
return znal;
}


void AktualizujL2k(wL2k Pocz)
{    
wL2k E=Pocz;
int klucz,znal=0;

cout<<"Podaj id pozycji do aktualizacji (numer indeksu): ";
cin>>klucz;
    while(E!=NULL)
    {
    if(E->daneS.indeks==klucz){znal=1; Wyswietl(E->daneS); AktualizujStudenta(E->daneS);break;}
    E=E->nast;
    }
if(!znal){cout<<"\nNie ma pozycji o podanym id."; getch();}
}

void WyszukajL2k(wL2k Pocz)
{
wL2k E=Pocz;
char nazwisko[15];
int znal=0;

cout<<"\nPodaj nazwisko studenta: "<<flush;
fflush(stdin);
gets(nazwisko);

    while(E!=NULL)
    {
    if(strstr(E->daneS.nazwisko,nazwisko)!=NULL){znal=1; Wyswietl(E->daneS);}
    E=E->nast;
    }     
if(!znal)cout<<"\nNie znaleziono zadnej pozycji";
getch();     
}


void ZapiszL2k(wL2k Pocz)
{ 
    FILE* wp;
    wL2k E=Pocz;
    if((wp=fopen("studenci.dat","wb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku";
    getch();
    }
    else
    {        
        while(E!=NULL)
        {
        fwrite(&E->daneS,sizeof(E->daneS),1,wp);
        E=E->nast;
        }
    fclose(wp);
    }
}

void OdczytajL2k(wL2k &Pocz,wL2k &Kon)
{
    wL2k E;
    FILE* wp;
    Pocz=NULL;
    Kon=NULL;
    if((wp=fopen("studenci.dat","rb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku";
    getch();
    }
    else
    {
        while (!feof(wp))
        {
        E=new Lista2k;
            if(fread(&(E->daneS),sizeof(Student),1,wp)==1)
            {
            E->nast=NULL;
            if(Pocz==NULL)
            {Pocz=E; E->pop=NULL;}
            else
            {Kon->nast=E; E->pop=Kon;}
            Kon=E;
            }
        }
    fclose(wp);
    }
}


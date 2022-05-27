#include "lista_1k.h"

void DolaczL1k(wL1k &Pocz,wL1k &Kon)
{
wL1k E;
int klucz;
E=new Lista1k;
    cout<<"Podaj ID pozycji: "; cin>>klucz;

    while(klucz<=0)
    {cout<<"Blad - Podaj ID pozycji: "; cin>>klucz;}

    if(!SprawdzKluczL1k(Pocz,klucz))
    {
    Wypelnij(E->daneP,klucz);
    
        if(Pocz==NULL)
        {Pocz=E; Kon=E; E->nast=NULL;}   
        else if(E->daneP.id<Pocz->daneP.id)
        {E->nast=Pocz; Pocz=E;}    
        else if(E->daneP.id>Kon->daneP.id)
        {Kon->nast=E; E->nast=NULL; Kon=E;}
        else
        {
        wL1k T,L;
        T=Pocz;    
        while(E->daneP.id>=T->daneP.id)
        {L=T; T=T->nast;}    
        E->nast=L->nast;
        L->nast=E;
        }
    }
    else
    {
    cout<<"Blad - podany identyfikator nie jest unikatowy.";
    getch();
    }
}

void PrzegladajL1k(wL1k Pocz)
{
wL1k E=Pocz;
    while(E!=NULL)
    {
    Wyswietl(E->daneP);
    E=E->nast;
    }
getch();
}

void PrzegladajZKluczemL1k(wL1k Pocz,int klucz)
{
wL1k E=Pocz;
    while(E!=NULL)
    {
    if(E->daneP.id==klucz){Wyswietl(E->daneP); break;}
    E=E->nast;
    }
}


void UsunL1k(wL1k &Pocz,wL1k &Kon,int id_pracownika)
{
wL1k E=Pocz,Pop=NULL;

    while(E!=NULL)
    {
    if(E->daneP.id==id_pracownika) break;
    Pop=E;
    E=E->nast;
    }   

    if(E==Pocz)
    Pocz=E->nast;
    else if(E==Kon)
    {Pop->nast=NULL; Kon=Pop;}
    else
    Pop->nast=E->nast;
    delete(E);

}


int SprawdzKluczL1k(wL1k Pocz,int klucz)
{
wL1k E=Pocz;
int znal=0;
    while(E!=NULL)
    {
    if(E->daneP.id==klucz){znal=1; break;}
    E=E->nast;
    }
return znal;
}


void AktualizujL1k(wL1k Pocz)
{    
wL1k E=Pocz;
int klucz,znal=0;

cout<<"Podaj id pozycji do aktualizacji: ";
cin>>klucz;
    while(E!=NULL)
    {
    if(E->daneP.id==klucz){znal=1; Wyswietl(E->daneP); AktualizujPracownika(E->daneP);break;}
    E=E->nast;
    }
if(!znal){cout<<"\nNie ma pozycji o podanym id."; getch();}
}

void WyszukajL1k(wL1k Pocz)
{
wL1k E=Pocz;
char nazwisko[15];
int znal=0;

cout<<"\nPodaj nazwisko pracownika: "<<flush;
fflush(stdin);
gets(nazwisko);

    while(E!=NULL)
    {
    if(strstr(E->daneP.nazwisko,nazwisko)!=NULL){znal=1; Wyswietl(E->daneP);}
    E=E->nast;
    }     
if(!znal)cout<<"\nNie znaleziono zadnej pozycji";
getch();     
}


void ZapiszL1k(wL1k Pocz)
{ 
    FILE* wp;
    wL1k E=Pocz;
    if((wp=fopen("pracownicy.dat","wb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku 'pracownicy.dat'";
    getch();
    }
    else
    {        
        while(E!=NULL)
        {
        fwrite(&E->daneP,sizeof(E->daneP),1,wp);
        E=E->nast;
        }
    fclose(wp);
    }
}

void OdczytajL1k(wL1k &Pocz,wL1k &Kon)
{
    wL1k E;
    FILE* wp;
    Pocz=NULL;
    Kon=NULL;
    if((wp=fopen("pracownicy.dat","rb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku";
    getch();
    }
    else
    {
        while (!feof(wp))
        {
        E=new Lista1k;
            if(fread(&(E->daneP),sizeof(Pracownik),1,wp)==1)
            {
            E->nast=NULL;
            if(Pocz==NULL)
            Pocz=E;
            else
            Kon->nast=E;
            Kon=E;
            }
        }
    fclose(wp);
    }
}

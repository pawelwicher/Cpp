#include "Slownik.h"


void Dolacz(wsk &wb,char slowoPol[10],char slowoAng[10])
{
    if (wb==NULL)
    {
        wb=new Wezel;
        wb->lewy=NULL;
        wb->prawy=NULL;
        strcpy(wb->slownik.slowoPol,slowoPol);
        strcpy(wb->slownik.slowoAng,slowoAng);
    }
    else
        if(strcmp(slowoPol,wb->slownik.slowoPol)<0)
        Dolacz(wb->lewy,slowoPol,slowoAng);
        else Dolacz(wb->prawy,slowoPol,slowoAng);
}

void DolaczSlowo(wsk &wb)
{
int poziom=0;
char slowoPol[10],slowoAng[10];
cout<<"Po polsku: "; cin>>slowoPol;
cout<<"Po angielsku: "; cin>>slowoAng;
Dolacz(wb,slowoPol,slowoAng);
PoliczParametry(wb,poziom);
cout<<"\nWezel dodany.";   
}

void PoliczParametry(wsk wb,int &poziom)
{ 
    if(wb)
    {
    poziom++;
    wb->glebokosc=poziom;
    wb->wysokosc=Wysokosc(wb);
    PoliczParametry(wb->lewy,poziom);
    PoliczParametry(wb->prawy,poziom);
    poziom--;
    }
}

void Zapisz(wsk wb, FILE* f)
{
    if(wb)
    { 
    fwrite(&wb->slownik,sizeof(S),1,f);
    Zapisz(wb->lewy,f);
    Zapisz(wb->prawy,f);
    }
}

void ZapiszDrzewo(wsk wb)
{
FILE* f;
f=fopen("slownik.dat","wb");
Zapisz(wb,f);
fclose(f);    
}

void OdczytajDrzewo(wsk &wb)
{
S slownik;
wb=NULL;
FILE *f;
int poziom=0;

    if((f=fopen("slownik.dat","rb"))==NULL)
    {
    cout<<"Nie mozna otworzyc pliku slownik.dat ";
    getch();
    }
    else
    {
        while(!feof(f))
        {
        if(fread(&slownik,sizeof(S),1,f)==1)
        Dolacz(wb,slownik.slowoPol,slownik.slowoAng);
        }
    fclose(f);
    PoliczParametry(wb,poziom);
    }
}         

void WyswietlAlfabetycznie(wsk wb)
{
    if(wb)
    {
    WyswietlAlfabetycznie(wb->lewy);
    cout<<setw(10)<<left<<wb->slownik.slowoPol<<" - "<<setw(10)<<wb->slownik.slowoAng<<"\n";
    WyswietlAlfabetycznie(wb->prawy);
    }          
}

void PreOrder(wsk wb)
{ 
    if(wb)
    {
    cout<<setw(10)<<left<<wb->slownik.slowoPol<<" ["<<wb->glebokosc<<"|"<<wb->wysokosc<<"]\n";
    PostOrder(wb->lewy);
    PostOrder(wb->prawy);
    }
}

void InOrder(wsk wb)
{
    if(wb)
    {
    InOrder(wb->lewy);
    cout<<setw(10)<<left<<wb->slownik.slowoPol<<" ["<<wb->glebokosc<<"|"<<wb->wysokosc<<"]\n";
    InOrder(wb->prawy);
    }
}

void PostOrder(wsk wb)
{ 
    if(wb)
    { 
    PostOrder(wb->lewy);
    PostOrder(wb->prawy);
    cout<<setw(10)<<left<<wb->slownik.slowoPol<<" ["<<wb->glebokosc<<"|"<<wb->wysokosc<<"]\n";
    }
}

wsk Szukaj(wsk wb,char slowoPol[10])
{ 
int k;
    if(wb)
    { 
    k=strcmp(slowoPol,wb->slownik.slowoPol);
        if(k<0) return Szukaj(wb->lewy,slowoPol);
        if(k>0) return Szukaj(wb->prawy,slowoPol);
        if(k==0) return wb;
    }
return wb;
}

void WyszukajSlowo(wsk wb)
{
wsk W;
char slowoPol[10];
cout<<"Podaj slowo: "; cin>>slowoPol;
W=Szukaj(wb,slowoPol);
if(W==NULL) cout<<"Nie ma takiego slowa w slowniku";
else cout<<W->slownik.slowoPol<<" - "<<W->slownik.slowoAng;  
}





int Wysokosc(wsk wb)
{ 
int wl,wp;
    if(!wb)
    return 0;
    else
    { 
    wl=Wysokosc(wb->lewy);
    wp=Wysokosc(wb->prawy);
        if (wl>wp)
        return wl+1;
        else
        return wp+1;
    }
}

int LiczLiscie(wsk wb)
{ 
if(wb)
    if(wb->lewy==NULL && wb->prawy==NULL) return 1;
    else return LiczLiscie(wb->lewy)+LiczLiscie(wb->prawy);
else
    return 0;
}


int LiczWezly(wsk wb)
{ 
    if(wb) return LiczWezly(wb->lewy)+LiczWezly(wb->prawy)+1;
    else return 0;
}




//******************************************************************************
//******************************************************************************
//******************************************************************************
void ParametryDrzewa(wsk wb)
{
int w,lw,ll,ww,wz=0,jp=0,wyw=1,poziom=0;
w=Wysokosc(wb);
int *poziomy=new int[w];
lw=LiczWezly(wb);
ll=LiczLiscie(wb);
ww=WezlyWewnetrzne(wb);
WezlyZewnetrzne(wb,wz);
Wywazenie(wb,wyw);
JedenPotomek(wb,jp);
WezlyNaPoziomach(wb,poziom,poziomy);

cout<<"Wysokosc: "<<w;
cout<<"\nLiczba wezlow: "<<lw;
cout<<"\nLiczba lisci: "<<ll;
cout<<"\n\nLiczba wezlow wewnetrznych: "<<ww;
cout<<"\nLiczba wezlow zewnetrznych: "<<wz;
cout<<"\nLiczba wezlow z jednym potomkiem: "<<jp;
cout<<"\n\nWywazenie: ";
if(wyw) cout<<"TAK"; else cout<<"NIE";
cout<<"\n\nLiczby wezlow poziomami:\n";
for(int i=0;i<w;i++) cout<<"Poziom: "<<i+1<<" wezlow: "<<poziomy[i]<<"\n";   
}
//******************************************************************************
void Rysuj(wsk wb,int x,int poziom)
{
int y=poziom;
int k=80/Kwadrat(2, poziom+1);
    
    if(wb)
    {
    gotoxy(x,y);
    cout<<wb->slownik.slowoPol;
        
    if(wb->prawy)
    Rysuj(wb->prawy,x+k,poziom+1);
    
    if(wb->lewy)
    Rysuj(wb->lewy,x-k,poziom+1);
    } 
} 
//******************************************************************************
void Wywazenie(wsk wb,int &wywazenie)
{
    if(wb && wywazenie==1)
    {
    if(Abs(Wysokosc(wb->lewy)-Wysokosc(wb->prawy))>1) wywazenie=0;
    Wywazenie(wb->lewy,wywazenie);
    Wywazenie(wb->prawy,wywazenie);
    }     
}
//******************************************************************************
int WezlyWewnetrzne(wsk wb)
{ 
    if(wb && (wb->lewy!=NULL || wb->prawy!=NULL))
    return WezlyWewnetrzne(wb->lewy)+WezlyWewnetrzne(wb->prawy)+1;
    else return 0;
}
//******************************************************************************
void WezlyZewnetrzne(wsk wb,int &wz)
{
    if(wb)
    {
    if(wb->lewy==NULL) wz++;
    if(wb->prawy==NULL) wz++;
    WezlyZewnetrzne(wb->lewy,wz);
    WezlyZewnetrzne(wb->prawy,wz);
    }
}
//******************************************************************************
void JedenPotomek(wsk wb,int &jp)
{
    if(wb)
    {
    if((wb->lewy!=NULL && wb->prawy==NULL) || (wb->lewy==NULL && wb->prawy!=NULL)) jp++;
    JedenPotomek(wb->lewy,jp);
    JedenPotomek(wb->prawy,jp);
    }
}
//******************************************************************************
void WezlyNaPoziomach(wsk wb,int &poziom,int poziomy[])
{
    if(wb)
    {
    poziom++;
    poziomy[poziom-1]++;
    WezlyNaPoziomach(wb->lewy,poziom,poziomy);
    WezlyNaPoziomach(wb->prawy,poziom,poziomy);
    poziom--;
    }
    
}
//******************************************************************************
//******************************************************************************
//******************************************************************************


int Kwadrat(int x,int n)
{
    if(n==1) return x;
    else return x*Kwadrat(x,n-1);
}

int Abs(int x)
{
if(x<0) return -x;
else return x;
}

void gotoxy(int x,int y) 
{ 
    COORD coord; 
    coord.X = x; 
    coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

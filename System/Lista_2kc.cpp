#include "lista_2kc.h"

wL2kc InicjujGloweL2kc()
{
wL2kc Glowa=new Lista2kc;
Glowa->nast=Glowa;
Glowa->pop=Glowa;
return Glowa;
}

void DolaczL2kc(wL2kc &Glowa,int id_kursu, int id_studenta,char kod[7])
{
wL2kc E=new Lista2kc;
    
    if(!SprawdzZapisL2kc(Glowa,id_kursu,id_studenta))
    {
    E->daneZ.id_kursu=id_kursu;
    E->daneZ.id_studenta=id_studenta;
    strcpy(E->daneZ.kod,kod);
        
    E->nast=Glowa;
    E->pop=Glowa->pop;
    Glowa->pop->nast=E;
    Glowa->pop=E;   
    }
    else
    {
    cout<<"Blad - taki zapis juz istnieje.";
    getch();
    }
}


void Przegladaj(wL2kc Glowa)
{ wL2kc E=Glowa->pop;
  while (E!=Glowa)
  { cout<<E->daneZ.id_kursu<<" "<<E->daneZ.id_studenta<<" "<<E->daneZ.kod<<"\n";
    E=E->pop;
  }
getch();
}  



void ZapiszL2kc(wL2kc Glowa)
{
FILE* wp;
wL2kc E=Glowa->nast;
    if((wp=fopen("zapisy.dat","wb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku 'zapisy.dat'";
    getch();
    }
    else
    {        
        while(E!=Glowa)
        {
        fwrite(&E->daneZ,sizeof(E->daneZ),1,wp);
        E=E->nast;
        }
    fclose(wp);
    }       
}

void OdczytajL2kc(wL2kc Glowa)
{
wL2kc E=Glowa;
FILE* wp;
    if((wp=fopen("zapisy.dat","rb"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku";
    getch();
    }
    else
    {
        while (!feof(wp))
        {
        E=new Lista2kc;
        
            if(fread(&(E->daneZ),sizeof(Zapis),1,wp)==1)
            {
            E->nast=Glowa;
            E->pop=Glowa->pop;
            Glowa->pop->nast=E;
            Glowa->pop=E;
            }
        }
    fclose(wp);
    }      
}

void UsunZapis(wL2kc &Glowa,int id_kursu, int id_studenta)
{
wL2kc E=Glowa->nast,Pop=Glowa;

    if(id_kursu!=0 && id_studenta!=0)
    {
        while(E!=Glowa)
        {
        if(E->daneZ.id_kursu==id_kursu && E->daneZ.id_studenta==id_studenta) break;
        E=E->nast;
        }  
        E->pop->nast=E->nast;
        E->nast->pop=E->pop;
        delete(E);
    }
    
        
    if(id_kursu==0)
    {
    while(E!=Glowa)
        {
        if(E->daneZ.id_studenta==id_studenta){E->pop->nast=E->nast; E->nast->pop=E->pop; delete(E);}
        E=E->nast;
        }  
    }
    
    if(id_studenta==0)
    {
    while(E!=Glowa)
        {
        if(E->daneZ.id_kursu==id_kursu){E->pop->nast=E->nast; E->nast->pop=E->pop; delete(E);}
        E=E->nast;
        }  
    }

}

int SprawdzZapisL2kc(wL2kc Glowa,int id_kursu, int id_studenta)
{
wL2kc E=Glowa->pop;
int znal=0;
while (E!=Glowa)
{
if(E->daneZ.id_kursu==id_kursu && E->daneZ.id_studenta==id_studenta){znal=1; break;}
E=E->pop;
}
return znal; 
}

int SprawdzZapisyL2kc(wL2kc Glowa,int id_kursu)
{
wL2kc E=Glowa->pop;
int znal=0;
while (E!=Glowa)
{
if(E->daneZ.id_kursu==id_kursu){znal=1; break;}
E=E->pop;
}   
return znal;   
}

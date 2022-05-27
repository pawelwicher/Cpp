#include "plik_tex.h"

void Wykaz()
{ 
    FILE* wpt,*wp;
    ksiazka buf;
    if((wpt=fopen("wykaz.txt","wt"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku tekstowego na wykaz"<<endl;
    getch();
    }
    else
    {
    if(Sprawdz_plik(&wp))
    {
    fprintf(wpt,"\n  Wykaz pozycji\n");
    fprintf(wpt,"\n -----------------------------------------------------------------------------------");
    fprintf(wpt,"\n | ID  |               Tytul                    |          Autor          |Dostepna|");
    fprintf(wpt,"\n -----------------------------------------------------------------------------------");
    
    while(fread(&buf,sizeof(buf),1,wp)==1)
    {
    fprintf(wpt,"\n |%5d|%-40s|%-25s|%1d       |",buf.id,buf.tytul,buf.autor,buf.dostepna);
    fprintf(wpt,"\n -----------------------------------------------------------------------------------");
    }
    fclose(wp);
    cout<<"Wygenerowano plik wykazu"<<endl;
    getch();
    }
    fclose(wpt);
    }
}


void Histogram_kategorii()
{
    FILE* wpt,*wp;
    ksiazka buf;
    int t[5]={0};
    char typy[][13]={"naukowa","beletrystyka","czasopismo","slownik","poradnik"};
    if((wpt=fopen("histogram_kategorii.txt","wt"))==NULL)
    {
    cout<<"\nNie mozna otworzyc pliku tekstowego na histogram"<<endl;
    getch();
    }
    else
    {
    if(Sprawdz_plik(&wp))
    {    
    while(fread(&buf,sizeof(buf),1,wp)==1)
    t[buf.typ]++;
     
    cout<<"Histogram kategorii\n\nKategoria      Ilosc";
    fprintf(wpt,"\n  Histogram kategorii\n");
    fprintf(wpt,"\n ---------------------");
    fprintf(wpt,"\n | Kategoria  |Ilosc |");
    fprintf(wpt,"\n ---------------------");
    
    for(int i=0;i<5;i++)
    {
    cout<<"\n"<<setw(13)<<left<<typy[i]<<"  "<<t[i];
    fprintf(wpt,"\n |%-12s|%   3d   |",typy[i],t[i]);
    fprintf(wpt,"\n ---------------------");
    }
    
    fclose(wp);
    cout<<"\n\nWygenerowano plik z histogramem"<<endl;
    getch();
    }
    fclose(wpt);
    }
}


void Histogram_liczby_wypozyczen1()
{ 
    FILE* wpt,*wp;
    int i,n;
    float p,A,H,B;
    ksiazka buf;
    int hist[10]={0};

    if((wpt=fopen("histogram_liczby_wypozyczen1.txt","wt"))==NULL)
    {
        cout<<"\nNie mozna otworzyc pliku tekstowego na histogram"<<endl;
        getch();
    }
    else
    {
        if(Sprawdz_plik(&wp))
        {
        cout<<"\nPodaj liczbe przedzialow histogramu <=10: ";
        cin>>n;
        cout<<"\nPodaj dolna granice histogramu: ";
        cin>>A;
        cout<<"\nPodaj szerokosc przedzialu: ";
        cin>>H;
        
        B=A+(n-2)*H;
        
        while(fread(&buf,sizeof(buf),1,wp)==1)
        {
            p=buf.liczba_wypozyczen;
            if(p<=A)
            hist[0]++;
            else if(p>B)
            hist[n-1]++;
            else
            {
            i=(p-A)/H+1;
            if((A+(i-1)*H)==p) i--;
            hist[i]++;
            }
        }
        
        fclose(wp);
        
        cout<<"\nHistogram dla pozycji wg liczby wypozyczen (1)";
        fprintf(wpt,"\n  Histogram dla pozycji wg liczby wypozyczen (1)\n");
        
        cout<<"\nPozycji o liczbie wypozyczen <= "<<A<<" jest "<<hist[0];
        fprintf(wpt,"\nPozycji o liczbie wypozyczen <= %1f",A);
        fprintf(wpt," jest %1d",hist[0]);
        
        for(i=1;i<n-1;i++)
        {
            cout<<"\nPozycji o liczbie wypozyczen > "<<A+(i-1)*H<<" i <= "<<A+i*H<<" jest "<<hist[i];
            fprintf(wpt,"\nPozycji o liczbie wypozyczen > %1f",A+(i-1)*H);
            fprintf(wpt," i <= %1f",A+i*H);
            fprintf(wpt," jest %1d",hist[i]);
        }
        
        cout<<"\nPozycji o liczbie wypozyczen > "<<B<<" jest "<<hist[n-1]<<endl;
        fprintf(wpt,"\nPozycji o liczbie wypozyczen > %1f",B);
        fprintf(wpt," jest %1d",hist[n-1]);
                
        cout<<"\n\nWygenerowano plik z histogramem"<<endl;
        getch();
        }
        fclose(wpt);
    }    
}


void Histogram_liczby_wypozyczen2()
{
    FILE* wpt,*wp;
    int i,j=0,n,policz;
    int p,przedzialy[20];
    float suma=0;
    ksiazka buf;
    int hist[10]={0};
    
    
    if((wpt=fopen("histogram_liczby_wypozyczen2.txt","wt"))==NULL)
    {
        cout<<"\nNie mozna otworzyc pliku tekstowego na histogram"<<endl;
        getch();
    }
    else
    {      
        if (Sprawdz_plik(&wp))
        {
        cout<<"\nPodaj liczbe przedzialow histogramu <=20: ";
        cin>>n;
        cout<<"Podaj granice przedzialow: "<<endl;
        
        for (i=0; i<n-1; i++)
        {
            cout<<"O numerze  "<<i+1<<" ";
            cin>>przedzialy[i];
        }
        
        while (fread(&buf,sizeof(buf),1,wp)==1)
        {
            i=0;
            j++;
            p=buf.liczba_wypozyczen;
            suma+=p;
            policz=0;
            do
            {
                if(p<=przedzialy[i])
                {
                    hist[i]++;
                    policz=1;
                }
                else i++;
            }
            while(!policz && i<n-1);
            if(!policz)
            hist[n-1]++;
        }
        fclose(wp);
    
        cout<<"\nHistogram dla pozycji wg liczby wypozyczen (2)";
        fprintf(wpt,"\n  Histogram dla pozycji wg liczby wypozyczen (2)\n");
        
        cout<<"\nPozycji o liczbie wypozyczen <= "<<przedzialy[0]<<"  "<<hist[0];
        fprintf(wpt,"\nPozycji o liczbie wypozyczen <= %1d",przedzialy[0]);
        fprintf(wpt," jest %1d",hist[0]);
        
        for (i=1; i<n-1; i++)
        {
            cout<<"\nPozycji o liczbie wypozyczen > "<<przedzialy[i-1]<<" i <= "<<przedzialy[i]<<" jest "<<hist[i];
            fprintf(wpt,"\nPozycji o liczbie wypozyczen > %1d",przedzialy[i-1]);
            fprintf(wpt," i <= %1d",przedzialy[i]);
            fprintf(wpt," jest %1d",hist[i]);
        }
        
        cout<<"\nPozycji o liczbie wypozyczen > "<<przedzialy[n-2]<<" jest "<<hist[n-1];
        fprintf(wpt,"\nPozycji o liczbie wypozyczen > %1d",przedzialy[n-2]);
        fprintf(wpt," jest %1d",hist[n-1]);
        
        cout<<"\nSrednia liczba wypozyczen wynosi "<<suma/j;
        fprintf(wpt,"\n\nSrednia: %1f",suma/j);
        
        cout<<"\n\nWygenerowano plik z histogramem"<<endl;
        getch();
        }
        fclose(wpt);
    }
}


void Wezwanie_do_zwrotu()
{
FILE *wp,*wpf,*wpt;
int znal=0,id_rekordu,i,j=0,p=0,len;
char z,imie[20],nazwisko[20],wierszwy[128],wiersz[128],temp[128],tmp[10];
char* tekst;
ksiazka buf;
     
cout<<"Korespondencja seryjna - wezwanie do zwrotu\n\n";

cout<<"Podaj id rekordu: "; cin>>id_rekordu;

if(Sprawdz_plik(&wp))
    while(fread(&buf,sizeof(buf),1,wp)==1)
        if(buf.id==id_rekordu){znal=1; break;}

if(znal)
{
cout<<"\nPodaj dane czytelnika\n";
cout<<"Imie: "; cin>>imie;
cout<<"Nazwisko: "; cin>>nazwisko;

    if((wpf=fopen("formularz.txt","rt"))==NULL)
    cout<<"\nNie mozna otworzyc pliku formularza.";
    else
    {
        if((wpt=fopen("Korespondencja.txt","wt"))==NULL)
        cout<<"\nNie mozna otworzyc pliku formularza.";
        else
        {        
            while(fgets(wiersz,sizeof(wiersz),wpf)!=NULL)
            {
            tekst=new char[40];                                            
            p=0;
            j=0;
                    for(i=0;i<=strlen(wiersz);i++)
                    {
                    if(wiersz[i]=='@') {p=i; z=wiersz[i+1];} 
                    
                    if(p){temp[j]=wiersz[i]; j++;}
                    else wierszwy[i]=wiersz[i];
                    }
                    
                    
                    switch(z)
                    {
                    case '1':
                    {
                    itoa(buf.id,tmp,10);
                    len=strlen(tmp);
                    strcat(tekst,tmp);
                    break;
                    }
                    case '2':
                    strcat(tekst,buf.tytul);
                    len=strlen(buf.tytul);
                    break;
                    case '3':
                    strcat(tekst,buf.autor);
                    len=strlen(buf.autor);
                    break;
                    case '4':
                    {
                    itoa(buf.data_zwrotu.d,tmp,10);
                    strcat(tekst,tmp);
                    strcat(tekst,"/");
                    itoa(buf.data_zwrotu.m,tmp,10);
                    strcat(tekst,tmp);
                    strcat(tekst,"/");
                    itoa(buf.data_zwrotu.r,tmp,10);
                    strcat(tekst,tmp);
                    break;
                    }
                    case '5':
                    {
                    strcat(tekst,imie);
                    strcat(tekst," ");
                    strcat(tekst,nazwisko);
                    break;
                    }            
                    }
                    
                        
                    
                    if(p)
                    {
                    for(i=p;i<=p+strlen(tekst);i++)
                    wierszwy[i]=tekst[i-p];
                    
                    for(i=p+strlen(tekst);i<=p+strlen(tekst)+strlen(wiersz);i++)
                    wierszwy[i]=temp[i-p-strlen(tekst)+2];
                    }


            fprintf(wpt,wierszwy);                             
            delete(tekst);                                         
            }
        fclose(wpt);    
        }
    fclose(wpf);
    }        
}
else
cout<<"\nBrak rekordu o podanym ID";

getch();     
}

#include "Operacje.h"


void ZapiszStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k,wL1k PoczL1k)
{
int indeks,idkursu,numer;
int q=0,k=0,m=0,p=0,r=1;
Student student;
Kurs kurs;
char kod[7];
cout<<"Podaj numer indeksu: ";cin>>indeks;     

    if(SprawdzKluczL2k(PoczL2k,indeks))
    {
    PrzegladajZKluczemL2k(PoczL2k,indeks);    
    wL2k E=PoczL2k;
        while(E!=NULL)
        {
        if(E->daneS.indeks==indeks){student=E->daneS; break;}
        E=E->nast;
        }
    
        cout<<"\nPodaj kod kursu na ktory chcesz sie zapisac: "<<flush;
        fflush(stdin);
        gets(kod);
    
        wL2kc L=GlowaL2kc->pop;
        while(L!=GlowaL2kc)
        {
        if(strcmp(kod,L->daneZ.kod)==0 && L->daneZ.id_studenta==indeks){q=1; break;}
        L=L->pop;
        }
    
        if(q==1){cout<<"\nBlad - student jest juz zapisany na ten kurs."; getch();}
        else
        {    
            wL1kc K=GlowaL1kc->nast;    
            while(K!=GlowaL1kc)
            {
            kurs=K->daneK;
                if(strcmp(kod,K->daneK.kod)==0 && kurs.rok==student.rok && kurs.kierunek==student.kierunek)
                {
                Wyswietl(K->daneK);
                k=1;
                }                
            K=K->nast;                  
            }
        
            if(!k) {cout<<"\nBlad - podany kod kursu jest nieprawidlowy."; getch();}
            else
            {
            cout<<"\n\nPodaj id kursu na ktory chcesz sie zapisac: "; cin>>idkursu;
            
                if(SprawdzKluczL1kc(GlowaL1kc,idkursu))                 
                {          
                    wL1kc F=GlowaL1kc->nast;
                    while(F!=GlowaL1kc)
                    {
                        if(F->daneK.id==idkursu)
                        {
                            kurs=F->daneK;
        
                            if(kurs.liczba_miejsc>0) m=1;                   
                            else cout<<"\nBrak miejsc.";
                            
                            if(kurs.rok==student.rok && kurs.kierunek==student.kierunek) p=1;                   
                            else cout<<"\nNalezy wybrac kurs odpowiedni do roku studiow i kierunku.";

                            
                            wL2kc G=GlowaL2kc->pop;
                            if(G==GlowaL2kc) r=1;
                            while(G!=GlowaL2kc)
                            {
                                if(G->daneZ.id_studenta==indeks)
                                {
                                
                                numer=G->daneZ.id_kursu;
                                
                                    wL1kc H=GlowaL1kc->nast;
                                    while(H!=GlowaL1kc)
                                    {
                                    if(H->daneK.id==numer)
                                    if(kurs.dzien==H->daneK.dzien && !PorownajGodziny(H->daneK,kurs.poczatek.godzina,kurs.poczatek.minuta,kurs.koniec.godzina,kurs.koniec.minuta))
                                    {cout<<"\nKolizja terminow."; r=0;}
                                    H=H->nast;                              
                                    }                 
                                }
                            G=G->pop;
                            }                    
                        break;
                        }
                    F=F->nast;
                    }
                if(m && p && r)
                {
                DolaczL2kc(GlowaL2kc,idkursu,indeks,kod);
                    wL1kc I=GlowaL1kc->nast;
                    while(I!=GlowaL1kc)
                    {
                    if(I->daneK.id==idkursu) {I->daneK.liczba_miejsc--; break;}
                    I=I->nast;
                    }       
                cout<<"ZAPISANO NA KURS";
                }
                getch();                                                     
                }
                else
                {
                cout<<"Blad - nie ma takiego kursu.";
                getch();    
                }                    
            }
        }
    }
    else
    {
    cout<<"Blad - nie ma takiego studenta.";
    getch();    
    }
}


void ZrezygnujZKursu(wL1kc GlowaL1kc, wL2kc GlowaL2kc,wL2k PoczL2k)
{
int indeks,idkursu,znal=0;

cout<<"Podaj numer indeksu: ";cin>>indeks;     

    if(SprawdzKluczL2k(PoczL2k,indeks))
    {
        if(PokazKursyStudenta(GlowaL2kc,GlowaL1kc,PoczL2k,indeks))
        {
        cout<<"\n\nPodaj id kursu z ktorego rezygnujesz: ";cin>>idkursu;   
            wL2kc G=GlowaL2kc->pop;        
            while(G!=GlowaL2kc)
            {
                if(G->daneZ.id_kursu==idkursu && G->daneZ.id_studenta==indeks)
                {
                znal=1;
                UsunZapis(GlowaL2kc,idkursu,indeks);
                wL1kc E=GlowaL1kc->nast;
                    while(E!=GlowaL1kc)
                    {
                    if(E->daneK.id==idkursu){E->daneK.liczba_miejsc++; break;}
                    E=E->nast;
                    }
                break;
                }
            G=G->pop;
            }
            if(!znal) {cout<<"Blad - nie istnieje taki zapis"; getch();}
            else {cout<<"Rezygnacja z kursu powiodla sie"; getch();}
        }
                                                            
    }
    else
    {
    cout<<"Blad - nie ma takiego studenta.";
    getch();    
    }   
} 



int PokazKursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k,int id_studenta)
{
int p=0;
wL2kc G=GlowaL2kc->pop;
wL1kc K=GlowaL1kc->nast;
    
    PrzegladajZKluczemL2k(PoczL2k,id_studenta);     
        while(G!=GlowaL2kc)
        {
            if(G->daneZ.id_studenta==id_studenta)
            {       
            K=GlowaL1kc->nast;
                while(K!=GlowaL1kc)
                {
                if(K->daneK.id==G->daneZ.id_kursu) {Wyswietl2(K->daneK); p=1;}  
                K=K->nast;                  
                }
            }
        G=G->pop;
        }
    
    if(!p){cout<<"\nBrak zapisow."; getch(); return 0;}
    else {getch(); return 1;}
}


void DostepneKursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k)
{
int indeks,k=0;
Student student;
Kurs kurs;
cout<<"Podaj numer indeksu: ";cin>>indeks;     

    if(SprawdzKluczL2k(PoczL2k,indeks))
    {
    PrzegladajZKluczemL2k(PoczL2k,indeks);    
    wL2k E=PoczL2k;
        while(E!=NULL)
        {
        if(E->daneS.indeks==indeks){student=E->daneS; break;}
        E=E->nast;
        }
        
        wL1kc K=GlowaL1kc->nast;    
        while(K!=GlowaL1kc)
        {
        kurs=K->daneK;
            if(kurs.rok==student.rok && kurs.kierunek==student.kierunek)
            {
            Wyswietl2(K->daneK);
            k=1;
            }                
        K=K->nast;                  
        }
        if(!k) cout<<"\nBrak dostepnych kursow.";
        getch();                                   
    }     
    else
    {
    cout<<"Blad - nie ma takiego studenta.";
    getch();    
    }
}

void KursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k)
{
int indeks,p=0,k=1,i=0;
wL2k S=PoczL2k;
wL2kc G=GlowaL2kc->pop;
wL1kc K=GlowaL1kc->nast;
Kurs tablica_kursow[20];
Kurs buf;
Student std;
FILE* wpt;

cout<<"Podaj numer indeksu: ";cin>>indeks;     

    if(SprawdzKluczL2k(PoczL2k,indeks))
    {    
        while(S!=NULL)
        {
        if(S->daneS.indeks==indeks) {std=S->daneS; break;}
        S=S->nast;           
        }                                       
    
        PrzegladajZKluczemL2k(PoczL2k,indeks);    
        while(G!=GlowaL2kc)
        {
            if(G->daneZ.id_studenta==indeks)
            {
       
            K=GlowaL1kc->nast;
                while(K!=GlowaL1kc)
                {
                    if(K->daneK.id==G->daneZ.id_kursu)
                    {
                    Wyswietl2(K->daneK);
                    p=1;
                    tablica_kursow[i]=K->daneK;
                    i++;                  
                    }  
                K=K->nast;                  
                }
            }
        G=G->pop;
        }
        if(!p)cout<<"\nBrak zapisow.";
        else
        {                      
            if((wpt=fopen("kursy_studenta.txt","w"))==NULL)
            {
            cout<<"\nBlad"<<endl;
            getch();
            }
            else
            {
            fprintf(wpt,"\n   Lista kursow studenta\n");
            fprintf(wpt,"\n   Student: %s %s",std.imie,std.nazwisko);
            fprintf(wpt,"\n");
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            fprintf(wpt,"\n   |  Kod  |    Nazwa kursu     |   Godziny  |   Sala   |");
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            for(int j=0;j<i;j++)
            {
            buf=tablica_kursow[j];
            fprintf(wpt,"\n   |%-7s|%-20s|%2d:%2d -%2d:%2d|%-10s|",buf.kod,buf.nazwa,buf.poczatek.godzina,buf.poczatek.minuta,buf.koniec.godzina,buf.koniec.minuta,buf.sala);
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            }
        
            fclose(wpt);
            }          
    }
    getch();
    }
    else
    {
    cout<<"Blad - nie ma takiego studenta.";
    getch();    
    } 
}


void KursyPracownika(wL1kc GlowaL1kc,wL1k Pocz)
{
int id,p=0,i=0;
wL1k P=Pocz;
wL1kc K=GlowaL1kc->nast;
Pracownik prc;
Kurs tablica_kursow[20];
Kurs buf;
FILE* wpt;

cout<<"Podaj id pracownika: ";cin>>id;     

    if(SprawdzKluczL1k(Pocz,id))
    {
        while(P!=NULL)
        {
        if(P->daneP.id==id) {prc=P->daneP; break;}
        P=P->nast;           
        }                                           
        PrzegladajZKluczemL1k(Pocz,id);
        
        while(K!=GlowaL1kc)
        {
            if(K->daneK.id_pracownika==id)
            {
            Wyswietl2(K->daneK);
            p=1;
            tablica_kursow[i]=K->daneK;
            i++;                  
            }  
        K=K->nast;                  
        }
        if(!p)cout<<"\nBrak kursow.";
        else
        {        
            if((wpt=fopen("kursy_pracownika.txt","w"))==NULL)
            {
            cout<<"\nBlad"<<endl;
            getch();
            }
            else
            {
            fprintf(wpt,"\n   Lista kursow pracownika\n");
            fprintf(wpt,"\n   Student: %s %s",prc.imie,prc.nazwisko);
            fprintf(wpt,"\n");
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            fprintf(wpt,"\n   |  Kod  |    Nazwa kursu     |   Godziny  |   Sala   |");
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            for(int j=0;j<i;j++)
            {
            buf=tablica_kursow[j];
            fprintf(wpt,"\n   |%-7s|%-20s|%2d:%2d -%2d:%2d|%-10s|",buf.kod,buf.nazwa,buf.poczatek.godzina,buf.poczatek.minuta,buf.koniec.godzina,buf.koniec.minuta,buf.sala); 
            fprintf(wpt,"\n   +-------+--------------------+------------+----------+");
            }
            
            fclose(wpt);
            }
        }                                                                                            
    }
    else
    {
    cout<<"Blad - nie ma takiego pracownika.";
    getch();    
    } 
}



void StudenciKursu(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k)
{
int id_kursu,i=0,p=0;
wL1kc K=GlowaL1kc->nast;
wL2k S=PoczL2k;
wL2kc Z=GlowaL2kc->pop;
Student tablica_studentow[200];
Student buf;
Kurs kurs;
FILE* wpt;

cout<<"Podaj id kursu: "; cin>>id_kursu;     

    if(SprawdzKluczL1kc(GlowaL1kc,id_kursu))
    {
        while(K!=GlowaL1kc)
        {
        if(K->daneK.id==id_kursu){kurs=K->daneK; break;}
        K=K->nast;               
        }
        
        
        Wyswietl2(kurs);
        cout<<"\n\n\nLista studentow zapisanych:\n\n";
    
        while(Z!=GlowaL2kc)
        {
        S=PoczL2k;
            if(Z->daneZ.id_kursu==id_kursu)
            {            
                while(S!=NULL)
                {
                    if(Z->daneZ.id_studenta==S->daneS.indeks)
                    {
                    p=1;
                    tablica_studentow[i]=S->daneS;
                    i++;
                    }
                S=S->nast;
                }
            }
        Z=Z->pop;                   
        }
    for(int j=0;j<i;j++)
    Wyswietl(tablica_studentow[j]);
    
    if((wpt=fopen("studenci_kursu.txt","w"))==NULL)
    {
    cout<<"\nBlad"<<endl;
    getch();
    }
    else
    {
    fprintf(wpt,"\n   Lista studentow zapisanych na kurs: %s\n\n",kurs.kod);
    fprintf(wpt,"\n   +----------+--------------------------+");
    fprintf(wpt,"\n   |  Indeks  |     Imie i nazwisko      |");
    fprintf(wpt,"\n   +----------+--------------------------+");
    for(int u=0;u<i;u++)
    {
    buf=tablica_studentow[u];
    fprintf(wpt,"\n   |%-10d|%10s %15s%|",buf.indeks,buf.imie,buf.nazwisko); 
    fprintf(wpt,"\n   +----------+--------------------------+");
    }    
    fclose(wpt);
    }
                                 
    }
    else
    {
    cout<<"Blad - nie ma takiego kursu.";
    getch();    
    }   
}



void UsunKurs(wL2kc GlowaL2kc,wL1kc GlowaL1kc)
{
int id_kursu; 

wL1kc K=GlowaL1kc->nast;
wL2kc Z=GlowaL2kc->pop;

cout<<"Podaj id kursu: ";cin>>id_kursu;          
     
    if(SprawdzKluczL1kc(GlowaL1kc,id_kursu))
    {
    cout<<"\n\nCzy napewno usunac ten kurs [t/n]?";
        if(getche()=='t')
        {
            while(K!=GlowaL1kc)
            {
            if(K->daneK.id==id_kursu) UsunL1kc(GlowaL1kc,id_kursu);
            K=K->nast;
            }
            
        UsunZapis(GlowaL2kc,id_kursu,0);

                       
        cout<<"\n\nKurs usuniety.";             
        } 
    }
    else
    {
    cout<<"Blad - nie ma takiego kursu.";
    getch();    
    } 

}



void UsunStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k &Pocz,wL2k &Kon)
{
int id_studenta,id_kursu; 

wL1kc K=GlowaL1kc->nast;
wL2kc Z=GlowaL2kc->pop;

cout<<"Podaj numer indeksu: ";cin>>id_studenta;          
     
    if(SprawdzKluczL2k(Pocz,id_studenta))
    {
    PrzegladajZKluczemL2k(Pocz,id_studenta);
    cout<<"\n\nCzy napewno usunac tego studenta [t/n]?";
        if(getche()=='t')
        {
            while(Z!=GlowaL2kc)
            {                               
                if(Z->daneZ.id_studenta==id_studenta)
                {
                id_kursu=Z->daneZ.id_kursu;
                    while(K!=GlowaL1kc)
                    {
                    if(K->daneK.id==id_kursu){K->daneK.liczba_miejsc++; break;}
                    K=K->nast;
                    }
                K=GlowaL1kc->nast;
                UsunZapis(GlowaL2kc,id_kursu,id_studenta);                                                                 
                }
            Z=Z->pop;
            }
            
            UsunL2k(Pocz,Kon,id_studenta);

                       
        cout<<"\n\nStudent usuniety.";             
        }                                    
    }
    else
    {
    cout<<"Blad - nie ma takiego studenta.";
    getch();    
    } 
}

void UsunPracownika(wL1kc GlowaL1kc,wL1k &Pocz,wL1k &Kon)
{
int id_pracownika;
wL1kc K=GlowaL1kc->nast;

cout<<"Podaj id pracownika: ";cin>>id_pracownika;          
     
    if(SprawdzKluczL1k(Pocz,id_pracownika))
    {
    PrzegladajZKluczemL1k(Pocz,id_pracownika);
    cout<<"\n\nCzy napewno usunac tego pracownika [t/n]?";
        if(getche()=='t')
        {
            while(K!=GlowaL1kc)
            {
            if(K->daneK.id_pracownika==id_pracownika) K->daneK.id_pracownika=0;
            K=K->nast;                 
            }        
        UsunL1k(Pocz,Kon,id_pracownika);                  
        cout<<"\n\nPracownik usuniety.";         
        }
    }
    else
    {
    cout<<"Blad - nie ma takiego pracownika.";
    getch();    
    }      
}


void Zapisy(wL1k PoczL1k,wL2k PoczL2k,wL1k KonL1k,wL2k KonL2k,wL1kc GlowaL1kc,wL2kc GlowaL2kc)
{
char z;

OdczytajL1k(PoczL1k,KonL1k);
OdczytajL2k(PoczL2k,KonL2k);
OdczytajL1kc(GlowaL1kc);
OdczytajL2kc(GlowaL2kc);

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
                cout<<"[7] - Lista studentow zapisanych na kurs\n";
                cout<<"[0] - Powrot\n";
                cout<<"\n\n->";
                z=getche();
                system("cls");
                switch(z)
                {
                case '1':
                DolaczL1kc(GlowaL1kc); break;
                case '2':
                AktualizujL1kc(GlowaL1kc,GlowaL2kc); break;
                case '3':
                UsunKurs(GlowaL2kc,GlowaL1kc); getch(); break;
                case '4':
                PrzegladajL1kc(GlowaL1kc,PoczL1k); break;
                case '5':
                WyszukajL1kc(GlowaL1kc); break; 
                case '6':
                PrzypiszPracownikaL1kc(GlowaL1kc,PoczL1k); break;
                case '7':
                StudenciKursu(GlowaL2kc,GlowaL1kc,PoczL2k); getch(); break;
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
                DolaczL2k(PoczL2k,KonL2k); break;
                case '2':
                AktualizujL2k(PoczL2k); break;
                case '3':
                UsunStudenta(GlowaL2kc,GlowaL1kc,PoczL2k,KonL2k); getch(); break;
                case '4':
                PrzegladajL2k(PoczL2k);  break;
                case '5':
                WyszukajL2k(PoczL2k); break;                       
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
                DolaczL1k(PoczL1k,KonL1k); break;
                case '2':
                AktualizujL1k(PoczL1k); break;
                case '3':
                UsunPracownika(GlowaL1kc,PoczL1k,KonL1k); getch(); break;
                case '4':
                PrzegladajL1k(PoczL1k); break;
                case '5':
                WyszukajL1k(PoczL1k);break;                       
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
            ZapiszStudenta(GlowaL2kc,GlowaL1kc,PoczL2k,PoczL1k); break;
            case '2':
            ZrezygnujZKursu(GlowaL1kc,GlowaL2kc,PoczL2k); break;
            case '3':
            DostepneKursyStudenta(GlowaL2kc,GlowaL1kc,PoczL2k); break;
            case '4':
            KursyStudenta(GlowaL2kc,GlowaL1kc,PoczL2k); break;    
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
            KursyPracownika(GlowaL1kc,PoczL1k); getch(); break;    
            }     
            }
            z='9';  
            break;          
        }     
     }    
ZapiszL1k(PoczL1k);
ZapiszL2k(PoczL2k);
ZapiszL1kc(GlowaL1kc);
ZapiszL2kc(GlowaL2kc);     
}

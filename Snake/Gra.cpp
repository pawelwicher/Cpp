#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

bool stop;

struct punkt
{
    int x,y;
};

class Zbior
{
    public:
    vector<punkt>z;

    void Dodaj(punkt P)
        {
        punkt p;
        p.x=0;
        p.y=0;
        z.push_back(p);
        for(int i=z.size()-1;i>0;i--)
        z[i]=z[i-1];
        z[0]=P;
        }

    void Usun()
      {
      z.pop_back();
      }
};

class Plansza
{
    public:
    int plansza[16][24];

    Plansza()
        {
        for(int i=0;i<16;i++)
            for(int j=0;j<24;j++)
                if(i==0 || i==15 || j==0 || j==23)
                    plansza[i][j]=0;
                else
                    plansza[i][j]=1;
        }

    void Czysc()
        {
        for(int i=0;i<16;i++)
            for(int j=0;j<24;j++)
                if(i>0 && i<15 && j>0 && j<23)
                    if(plansza[i][j]==0)
                        plansza[i][j]=1;
        }

    void Set(int x,int y,int liczba)
        {
        plansza[15-y][x]=liczba;
        }

    int Get(int x,int y)
        {
        return plansza[15-y][x];
        }

};



class Snake
{
    public:
    Plansza plansza;
    Zbior waz;
    int kierunek;
    int wynik;
    bool zmiana;

    Snake()
        {
        kierunek=1;
        wynik=0;
        stop=false;
        zmiana=true;

        punkt p;

        for(int i=5;i>0;i--)
          {
          p.x=10+i;
          p.y=10;
          waz.Dodaj(p);
          }

        for(int i=0;i<waz.z.size();i++)
          plansza.Set(waz.z[i].x,waz.z[i].y,0);

        srand(time(0));
        LosowyPunkt();
        }

    void LosowyPunkt()
        {
        punkt p;

            do
            {
            p.x=rand()%24;
            p.y=rand()%16;
            if(plansza.Get(p.x,p.y)==1) break;
            }
            while(true);
        plansza.Set(p.x,p.y,2);
        }

    bool Kolizja()
        {
        punkt p=waz.z[0];
        if(kierunek==1) return (plansza.Get(p.x-1,p.y)==0);
        if(kierunek==2) return (plansza.Get(p.x+1,p.y)==0);
        if(kierunek==3) return (plansza.Get(p.x,p.y+1)==0);
        if(kierunek==4) return (plansza.Get(p.x,p.y-1)==0);
        }

    void Przesun()
        {
        plansza.Czysc();
        punkt p=waz.z[0];

        if(kierunek==1) p.x--;
        if(kierunek==2) p.x++;
        if(kierunek==3) p.y++;
        if(kierunek==4) p.y--;

        if(plansza.Get(p.x,p.y)==2)
            {
            plansza.Set(p.x,p.y,0);
            waz.Dodaj(p);
                for(int i=0;i<waz.z.size();i++)
                    plansza.Set(waz.z[i].x,waz.z[i].y,0);
            LosowyPunkt();
            wynik+=10;
            }
        else
            {
            waz.Dodaj(p);
            waz.Usun();
                for(int i=0;i<waz.z.size();i++)
                    plansza.Set(waz.z[i].x,waz.z[i].y,0);
            }
        }

    void Ruch()
        {
        if(Kolizja())
            stop=true;
        else
            Przesun();
        }

    void Lewo()
        {
        if(kierunek!=2 && zmiana==true)
            {kierunek=1; zmiana=false;}
        }

    void Prawo()
        {
        if(kierunek!=1 && zmiana==true)
            {kierunek=2; zmiana=false;}
        }

    void Gora()
        {
        if(kierunek!=4 && zmiana==true)
            {kierunek=3; zmiana=false;}
        }

    void Dol()
        {
        if(kierunek!=3 && zmiana==true)
            {kierunek=4; zmiana=false;}
        }
};

#include "Trojkat.h"

float a11,a12,a13,a14,a21,a22,a23,a24;
int x_tex,y_tex;

int cmp(const void *a,const void *b)
{
  Punkt2D A=*(Punkt2D*)a;
  Punkt2D B=*(Punkt2D*)b;

  if(A.y-B.y>0) return 1;
  else if(A.y-B.y<0) return -1;
  else return 0;
}

Punkt3D Trojkat::PrzejdzDo3D(Punkt2D Punkt)
{
  Punkt3D bok1=b-a;
  Punkt3D bok2=c-b;
  Punkt3D N=bok1*bok2; // wektor normalny do trojkata
  float d=odleglosc;
  float AA=N.x;  // paramentry plaszczyzny przechadzacej przez wierzcholki a,b,c trojkata
  float BB=N.y;
  float CC=N.z;
  float DD=-(N.x*b.x+N.y*b.y+N.z*b.z);
  float xx=(2*Punkt.x-X_RES+1)/(X_RES-1);               // x' (to co we wzorach z instrukcji do cwiczenia)
  float yy=(2*Punkt.y-Y_RES+1)/(Y_RES-1);               // y' (to co we wzorach z instrukcji do cwiczenia)
  float z1=-(AA*xx*d+BB*yy*d+DD*d)/(AA*xx+BB*yy+CC*d);
  float x=(xx*(z1+d))/d;
  float y=(yy*(z1+d))/d;
  float z=z1;

  return Punkt3D(x,y,z);
}

Punkt2D Trojkat::ObliczWspTekstury(Punkt3D p)
{
  Punkt2D ret;
  float u=a11*p.x+a12*p.y+a13*p.z+a14;
  float v=a21*p.x+a22*p.y+a23*p.z+a24;

  ret.x=floor(((u-floor(u))*x_tex));
  ret.y=floor(((v-floor(v))*y_tex));

  return ret;
}

bool Trojkat::CzyWidoczny()
{
  Punkt3D bok1=b-a;
  Punkt3D bok2=c-b;
  Punkt3D N=bok1*bok2;          // wektor normalny do trojkata
  Punkt3D S=a+b;                // wyznaczanie srodka trojkata
  S=S/2;
  S+=c;
  S=S/2;
  Punkt3D W(0,0,odleglosc);
  W-=S;                         // wektor od srodka trojkata do obserwatora

  return (W|N)<0;               // jezeli iloczyn skalarny jest ujemny to trojkat nie jest widoczny (return false;)
}
//---------------------------------------------------------------------------
void Trojkat::Rysuj(Obraz* scena,Obraz* tekstura)
{
   if(!CzyWidoczny()) return;           // jesli trojkat nie jest widoczny to nie jest rysowany

   Punkt2D p1,p2,p3;                    // wierzcholki trojkata (3D) sa przeksztalcane do wspolrzednych ekranu (2D)
   Punkt2D Punkt2DTab[3];
   Punkt2D p4;
   Punkt2D pocz,kon;
   Punkt2DTab[0]=a;
   Punkt2DTab[1]=b;
   Punkt2DTab[2]=c;

   qsort(Punkt2DTab,3,sizeof(Punkt2D),cmp);

   p1=Punkt2DTab[2];
   p2=Punkt2DTab[1];
   p3=Punkt2DTab[0];

   //obliczanie wspolrzednych punktu D (oznaczenie takie jak w opisie cwiczenia
   p4.y=p2.y;                   //wsporzedna y taka jak punktu A
     if(p1.x==p3.x)             //gdy nie trzeba dzielic trojkata na dwa przylegajace
        p4.x=p1.x;
     else                       //punkt przeciecia prostej y=p2.y z prosta przechodzaca przez B i C
        p4.x=(p4.y - p1.y + p1.x * ((p3.y - p1.y) / (p3.x - p1.x))) / ((p3.y - p1.y) / (p3.x - p1.x));

   for(int i = p2.y+1; i <= p1.y; i++)
   {
        pocz.y = i;
        kon.y = i;
        if(p1.x==p2.x)
           pocz.x = p1.x;
        else
        {
           float AA = (p1.y-p2.y)/(p1.x-p2.x);
           if(!AA) pocz.x = p2.x;
           else pocz.x = (pocz.y-(p2.y-p2.x*AA))/AA;
        }

        if(p4.x==p1.x)
           kon.x = p4.x;
        else
        {
           float AA = (p1.y-p4.y)/(p1.x-p4.x);
           if(!AA) kon.x = p4.x;
           else kon.x = (kon.y-(p4.y-p4.x*AA))/AA;
        }

        if(kon.x<pocz.x)
        {
           Punkt2D t = pocz;
           pocz = kon;
           kon = t;
        }

        for(int j = pocz.x; j < kon.x; j++)
        {
           Punkt2D pun2D(i,j);
           Punkt3D pun3D=PrzejdzDo3D(pun2D);
           Punkt2D pun2Dtex=ObliczWspTekstury(pun3D);
           RGBQUAD rgb=tekstura->PobierzPixel((int)pun2Dtex.x,(int)pun2Dtex.y);
           scena->UstawPixel(i,j,rgb);
        }
    }

   for(int i = p3.y+1; i <= p2.y; i++)
   {
        pocz.y = i;
        kon.y = i;
        if(p3.x==p4.x)
           pocz.x = p3.x;
        else
        {
           float AA = (p3.y-p4.y)/(p3.x-p4.x);
           if(!AA) pocz.x = p4.x;
           else pocz.x = (pocz.y-(p4.y-p4.x*AA))/AA;
        }

        if(p2.x==p3.x)
           kon.x = p2.x;
        else
        {
           float AA = (p2.y-p3.y)/(p2.x-p3.x);
           if(!AA) kon.x = p2.x;
           else kon.x = (kon.y-(p2.y-p2.x*AA))/AA;
        }

        if(kon.x<pocz.x)
        {
           Punkt2D t = pocz;
           pocz = kon;
           kon = t;
        }

        for(int j = pocz.x; j < kon.x; j++)
        {
           Punkt2D pun2D(i,j);
           Punkt3D pun3D=PrzejdzDo3D(pun2D);
           Punkt2D pun2Dtex=ObliczWspTekstury(pun3D);
           RGBQUAD rgb=tekstura->PobierzPixel((int)pun2Dtex.x,(int)pun2Dtex.y);
           scena->UstawPixel(i,j,rgb);
        }
   }
}

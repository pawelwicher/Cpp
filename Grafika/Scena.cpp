#include "Scena.h"

Scena::Scena(int x_res,int y_res,float odl,AnsiString plik)
{
  FILE *f=fopen(plik.c_str(),"rt");
  int n;
  float x,y,z;
  int a,b,c;

  X_RES=x_res;
  Y_RES=y_res;
  odleglosc=odl;

  fscanf(f,"%d",&n);
  wierzcholki=new Punkt3D[n];

  for(int i=0;i<n;i++)
  {
    fscanf(f,"%f %f %f",&x,&y,&z);
    wierzcholki[i]=Punkt3D(x,y,z);
  }

  fscanf(f,"%f",&a11);
  fscanf(f,"%f",&a12);
  fscanf(f,"%f",&a13);
  fscanf(f,"%f",&a14);
  fscanf(f,"%f",&a21);
  fscanf(f,"%f",&a22);
  fscanf(f,"%f",&a23);
  fscanf(f,"%f",&a24);

  fscanf(f,"%d",&n);
  trojkaty=new Trojkat[n];
  for(int i=0;i<n;i++)
  {
    fscanf(f,"%d %d %d",&a,&b,&c);
    trojkaty[i]=Trojkat(wierzcholki[a],wierzcholki[b],wierzcholki[c]);
  }

  fclose(f);

  RGBQUAD tlo={255,255,255};
  scena=new Obraz("scena.bmp",X_RES,Y_RES,tlo);
  tekstura=new Obraz("tex.bmp");

  x_tex=tekstura->szerokosc;
  y_tex=tekstura->wysokosc;

  for(int i=0;i<n;i++)
    trojkaty[i].Rysuj(scena,tekstura);

  scena->ZapiszObraz();
}

Scena::~Scena()
{
  delete scena;
  delete tekstura;
  delete trojkaty;
  delete wierzcholki;
}

#include "GradientDyskretny.h"

float WB(float liczba)
{
  return liczba<0 ? -liczba : liczba;
}

GradientDyskretny::GradientDyskretny(AnsiString config)
{
  FILE *f=fopen(config.c_str(),"rt");

  char plik1[32];
  char plik2[32];
  fscanf(f,"%s %s\n",&plik1,&plik2);
  AnsiString plikWe=AnsiString(plik1);
  AnsiString plikWy=AnsiString(plik2);

  fscanf(f,"%d\n",&typ);
  fscanf(f,"%f\n",&T);

  int r,g,b;

  fscanf(f,"%d %d %d\n",&r,&g,&b);
  kolor_tla.rgbRed=r;
  kolor_tla.rgbGreen=g;
  kolor_tla.rgbBlue=b;

  fscanf(f,"%d %d %d\n",&r,&g,&b);
  kolor_krawedzi.rgbRed=r;
  kolor_krawedzi.rgbGreen=g;
  kolor_krawedzi.rgbBlue=b;

  fclose(f);

  RGBQUAD tlo={255,255,255};
  imgWe=new Obraz(plikWe);
  imgWy=new Obraz(plikWy,imgWe->szerokosc,imgWe->wysokosc,tlo);
}

GradientDyskretny::~GradientDyskretny()
{
  delete imgWe;
  delete imgWy;
}

float GradientDyskretny::WyznaczJasnoscPixela(int x,int y)
{
  RGBQUAD rgb=imgWe->PobierzPixel(x,y);
  return (float)(rgb.rgbRed+rgb.rgbGreen+rgb.rgbBlue)/(3*255);
}

RGBQUAD GradientDyskretny::WyznaczKolorPixela(int x,int y,float jasnosc)
{
   RGBQUAD rgbWe=imgWe->PobierzPixel(x,y);
   RGBQUAD rgbWy;
   float jasnoscPixela=WyznaczJasnoscPixela(x,y);
   float j;
   if(!jasnoscPixela) jasnoscPixela=0.000001;
   j=jasnosc/(jasnoscPixela);
   int r,g,b;
   r=(int)rgbWe.rgbRed;
   g=(int)rgbWe.rgbGreen;
   b=(int)rgbWe.rgbBlue;

   if(r*j>255) rgbWy.rgbRed=255; else rgbWy.rgbRed=r*j;
   if(g*j>255) rgbWy.rgbGreen=255; else rgbWy.rgbGreen=r*j;
   if(b*j>255) rgbWy.rgbBlue=255; else rgbWy.rgbBlue=r*j;

   return rgbWy;
}

RGBQUAD GradientDyskretny::Gradient(int x,int y)
{
  RGBQUAD rgbWy;
  float jasnoscWe=WyznaczJasnoscPixela(x,y);
  float jasnosc_x1y0=WyznaczJasnoscPixela(x+1,y);
  float jasnosc_x0y1=WyznaczJasnoscPixela(x,y+1);
  float jasnosc_x1y1=WyznaczJasnoscPixela(x+1,y+1);
  float jasnoscWy=(float)sqrt((jasnoscWe-jasnosc_x1y1)*(jasnoscWe-jasnosc_x1y1)+
  (jasnosc_x1y0-jasnosc_x0y1)*(jasnosc_x1y0-jasnosc_x0y1));

  switch(typ)
  {
    case 1:
      if(jasnoscWy>=T) rgbWy=WyznaczKolorPixela(x,y,jasnoscWy);
      else rgbWy=imgWe->PobierzPixel(x,y);
      break;
    case 2:
      if(jasnoscWy>=T) rgbWy=kolor_krawedzi;
      else rgbWy=imgWe->PobierzPixel(x,y);
      break;
    case 3:
      if(jasnoscWy>=T) rgbWy=WyznaczKolorPixela(x,y,jasnoscWy);
      else rgbWy=kolor_tla;
      break;
    case 4:
      if(jasnoscWy>=T) rgbWy=kolor_krawedzi;
      else rgbWy=kolor_tla;
      break;
    default:
      rgbWy=WyznaczKolorPixela(x,y,jasnoscWy);
  }

  return rgbWy;
}

void GradientDyskretny::Filtruj()
{

  for(int i=0;i<imgWe->szerokosc-1;i++)
    for(int j=0;j<imgWe->wysokosc-1;j++)
      imgWy->UstawPixel(i,j,Gradient(i,j));

  imgWy->ZapiszObraz();
}

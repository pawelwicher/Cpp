#include "FiltrOkienkowy.h"


FiltrOkienkowy::FiltrOkienkowy(AnsiString config)
{
  FILE *f=fopen(config.c_str(),"rt");

  char plik1[32];
  char plik2[32];
  fscanf(f,"%s %s\n",&plik1,&plik2);
  AnsiString plikWe=AnsiString(plik1);
  AnsiString plikWy=AnsiString(plik2);

  fscanf(f,"%d %d\n",&x_size,&y_size);

  FILTR=new float*[x_size];
  for(int i=0;i<x_size;i++) FILTR[i]=new float[y_size];

  FILTR_SUMA=0;

  for(int i=0;i<x_size;i++)
  for(int j=0;j<y_size;j++)
  {
  if(j==y_size-1) fscanf(f,"%f \n",&FILTR[i][j]);
  else fscanf(f,"%f ",&FILTR[i][j]);
  FILTR_SUMA+=FILTR[i][j];
  }
  fclose(f);

  if(!FILTR_SUMA) FILTR_SUMA=1;

  RGBQUAD tlo={0,0,0};
  imgWe=new Obraz(plikWe);
  imgWy=new Obraz(plikWy,imgWe->szerokosc,imgWe->wysokosc,tlo);
}

FiltrOkienkowy::~FiltrOkienkowy()
{
  for(int i=0;i<x_size;i++) delete[] FILTR[i];
  delete[] FILTR;
  delete imgWe;
  delete imgWy;
}

float FiltrOkienkowy::Jasnosc(RGBQUAD rgb)
{
  return (float)(rgb.rgbRed+rgb.rgbGreen+rgb.rgbBlue)/(3*255);
}

void FiltrOkienkowy::Filtruj()
{
  int r,g,b;
  int mx=((x_size-1)/2),my=(y_size-1)/2;
  RGBQUAD rgb;

  for(int i=mx;i<imgWe->szerokosc-mx;i++)
    for(int j=my;j<imgWe->wysokosc-my;j++)
      {
      r=g=b=0;
      for(int x=0;x<x_size;x++)
        for(int y=0;y<y_size;y++)
          {
          rgb=imgWe->PobierzPixel(i+x-mx,j+y-my);
          r+=FILTR[x][y]*rgb.rgbRed;
          g+=FILTR[x][y]*rgb.rgbGreen;
          b+=FILTR[x][y]*rgb.rgbBlue;
          }

      r/=FILTR_SUMA;
      g/=FILTR_SUMA;
      b/=FILTR_SUMA;

      if(r>255) r=255; else if(r<0) r=0;
      if(g>255) g=255; else if(g<0) g=0;
      if(b>255) b=255; else if(b<0) b=0;

      rgb.rgbRed=r;
      rgb.rgbGreen=g;
      rgb.rgbBlue=b;

      imgWy->UstawPixel(i,j,rgb);
      }

  imgWy->ZapiszObraz();
}


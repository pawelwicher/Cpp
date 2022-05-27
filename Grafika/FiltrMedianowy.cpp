#include "FiltrMedianowy.h"

int cmp(const void *a,const void *b)
{
  return (*(int*)a-*(int*)b);
}

FiltrMedianowy::FiltrMedianowy(AnsiString config)
{
  FILE *f=fopen(config.c_str(),"rt");

  char plik1[32];
  char plik2[32];
  fscanf(f,"%s %s\n",&plik1,&plik2);
  AnsiString plikWe=AnsiString(plik1);
  AnsiString plikWy=AnsiString(plik2);

  fscanf(f,"%d %d",&x_size,&y_size);

  R=new int[x_size*y_size];
  G=new int[x_size*y_size];
  B=new int[x_size*y_size];

  fclose(f);

  RGBQUAD tlo={0,0,0};
  imgWe=new Obraz(plikWe);
  imgWy=new Obraz(plikWy,imgWe->szerokosc,imgWe->wysokosc,tlo);
}

FiltrMedianowy::~FiltrMedianowy()
{
  delete R;
  delete G;
  delete B;
  delete imgWe;
  delete imgWy;
}


int FiltrMedianowy::Mediana(int tab[],int n)
{
  qsort(tab,n,sizeof(int),cmp);
  if(n%2==0) return ((tab[n/2-1]+tab[n/2])/2);
  else return tab[n/2]; 
}

void FiltrMedianowy::Filtruj()
{
  int mx=((x_size-1)/2),my=(y_size-1)/2;
  int k;
  RGBQUAD rgb;

  for(int i=mx;i<imgWe->szerokosc-mx;i++)
    for(int j=my;j<imgWe->wysokosc-my;j++)
      {
      k=0;
      for(int x=0;x<x_size;x++)
        for(int y=0;y<y_size;y++)
          {
          rgb=imgWe->PobierzPixel(i+x-mx,j+y-my);
          R[k]=rgb.rgbRed;
          G[k]=rgb.rgbGreen;
          B[k]=rgb.rgbBlue;
          k++;
          }
      rgb.rgbRed=Mediana(R,x_size*y_size);
      rgb.rgbGreen=Mediana(G,x_size*y_size);
      rgb.rgbBlue=Mediana(B,x_size*y_size);
      imgWy->UstawPixel(i,j,rgb);
      }
  imgWy->ZapiszObraz();
}


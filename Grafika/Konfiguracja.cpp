#include "Konfiguracja.h"


Dane OdczytajKonfiguracje(AnsiString config)
{

Dane D;
char plik1[32];
char plik2[32];

float w1x,w1y,w2x,w2y,w3x,w3y;
float p1x,p1y,p2x,p2y,p3x,p3y;
int r,g,b;

FILE *f=fopen("config.txt","rt");
fscanf(f,"%s %s\n%d %d\n%f %f  %f %f  %f %f\n%f %f  %f %f  %f %f\n%d %d %d",
&plik1,&plik2,&D.Xres,&D.Yres,
&w1x,&w1y,&w2x,&w2y,&w3x,&w3y,
&p1x,&p1y,&p2x,&p2y,&p3x,&p3y,
&r,&g,&b);
fclose(f);

D.PlikWe=AnsiString(plik1);
D.PlikWy=AnsiString(plik2);
D.W1[0]=(double)w1x; D.W1[1]=(double)w1y;
D.W2[0]=(double)w2x; D.W2[1]=(double)w2y;
D.W3[0]=(double)w3x; D.W3[1]=(double)w3y;
D.P1[0]=(double)p1x; D.P1[1]=(double)p1y;
D.P2[0]=(double)p2x; D.P2[1]=(double)p2y;
D.P3[0]=(double)p3x; D.P3[1]=(double)p3y;
D.tlo.rgbRed=r;
D.tlo.rgbGreen=g;
D.tlo.rgbBlue=b;

return D;
}




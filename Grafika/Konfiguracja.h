#include <stdio.h>
#include <string>
#include <vcl.h>

struct Dane
{
AnsiString PlikWe;
AnsiString PlikWy;
int Xres;
int Yres;
double W1[2];
double W2[2];
double W3[2];
double P1[2];
double P2[2];
double P3[2];
RGBQUAD tlo;
};

Dane OdczytajKonfiguracje(AnsiString);

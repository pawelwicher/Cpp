#include "Obraz.h"
#include <stdio.h>


class GradientDyskretny
{
public:
int typ;
float T;
RGBQUAD kolor_tla,kolor_krawedzi;
Obraz* imgWe;
Obraz* imgWy;

GradientDyskretny(AnsiString);
~GradientDyskretny();
float WyznaczJasnoscPixela(int,int);
RGBQUAD WyznaczKolorPixela(int,int,float);
RGBQUAD Gradient(int,int);
void Filtruj();
};

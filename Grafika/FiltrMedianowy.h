#include "Obraz.h"
#include <stdio.h>

int cmp(const void*,const void*);

class FiltrMedianowy
{
public:
Obraz* imgWe;
Obraz* imgWy;
int x_size,y_size;
int *R,*G,*B;

FiltrMedianowy(AnsiString);
~FiltrMedianowy();
Mediana(int[],int);
void Filtruj();
};

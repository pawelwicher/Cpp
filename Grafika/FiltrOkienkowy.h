#include "Obraz.h"
#include <stdio.h>

class FiltrOkienkowy
{
public:
Obraz* imgWe;
Obraz* imgWy;
int x_size,y_size;
float** FILTR;
float FILTR_SUMA;

FiltrOkienkowy(AnsiString);
~FiltrOkienkowy();
float Jasnosc(RGBQUAD);
void Filtruj();
};

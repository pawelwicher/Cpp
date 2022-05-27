#include <vcl.h>
#include "..\cximage\ximage.h"

class Obraz
{
public:
    AnsiString nazwa;
    CxImage* img;
    int szerokosc;
    int wysokosc;

    Obraz(AnsiString);
    Obraz(AnsiString,int,int,RGBQUAD);
    ~Obraz();
    UstawPixel(int,int,RGBQUAD);
    RGBQUAD PobierzPixel(int,int);
    void ZapiszObraz();
};

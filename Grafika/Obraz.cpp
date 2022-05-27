#include "Obraz.h"

Obraz::Obraz(AnsiString nazwa)
{
    img=new CxImage(CXIMAGE_FORMAT_BMP);
    img->Load(nazwa.c_str(),CXIMAGE_FORMAT_BMP);

    this->nazwa=nazwa;
    this->szerokosc=img->GetWidth();
    this->wysokosc=img->GetHeight();
}

Obraz::Obraz(AnsiString nazwa,int szerokosc,int wysokosc,RGBQUAD tlo)
{
    img=new CxImage(szerokosc,wysokosc,24,CXIMAGE_FORMAT_BMP);

    this->nazwa=nazwa;
    this->szerokosc=szerokosc;
    this->wysokosc=wysokosc;

    for(int i=0;i<this->szerokosc;i++)
      for(int j=0;j<this->wysokosc;j++)
        UstawPixel(i,j,tlo);
}

Obraz::~Obraz()
{
    delete img;
}

Obraz::UstawPixel(int x,int y,RGBQUAD rgb)
{
    img->SetPixelColor(x,y,rgb);
}

RGBQUAD Obraz::PobierzPixel(int x,int y)
{
    return img->GetPixelColor(x,y);
}

void Obraz::ZapiszObraz()
{
    img->SetJpegQuality(200);
    img->Save(nazwa.c_str(),CXIMAGE_FORMAT_BMP);
}



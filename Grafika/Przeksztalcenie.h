#include "Obraz.h"
#include "Konfiguracja.h"

struct MTR2x2
{
double a11,a12,a21,a22;
};

struct VECT2
{
double b1,b2;
};

class Przeksztalcenie
{
public:
    Obraz* ImgWe;
    Obraz* ImgWy;
    MTR2x2 A;
    VECT2 B;

    Przeksztalcenie(Dane);
    ~Przeksztalcenie();
    int WyliczTransform(double[],double[],double[],double[],double[],double[],MTR2x2&,VECT2&);
    void Funkcja();
};

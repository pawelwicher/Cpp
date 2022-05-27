#include "Obraz.h"

//zmienne globalne
extern int X_RES,Y_RES;
extern float odleglosc;

class Punkt2D;
class Punkt3D;

class Punkt2D
{
  public:
  float x,y;

  //konstruktory
  Punkt2D() : x(0),y(0) {}
  Punkt2D(float X ,float Y) : x(X), y(Y) {}
  //konstruktor konwertujacy - pozwala na transformacje punktu3D na punkt2D
  Punkt2D(Punkt3D);
};

class Punkt3D
{
  public:
  float x,y,z;

  //konstrukotry
  Punkt3D() : x(0), y(0), z(0) {}
  Punkt3D(float X,float Y,float Z) : x(X),y(Y),z(Z) {}
  //grupa przeciazonych operatorów do operacji wektorowych
  Punkt3D operator+(Punkt3D);
  Punkt3D operator-(Punkt3D);
  Punkt3D operator+=(Punkt3D);
  Punkt3D operator-=(Punkt3D);
  Punkt3D operator*(Punkt3D);
  Punkt3D operator*=(Punkt3D);
  Punkt3D operator*(float);
  Punkt3D operator/(float);
  //iloczyn skalarny
  float operator|(Punkt3D);
};


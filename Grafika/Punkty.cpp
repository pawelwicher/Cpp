#include "Punkty.h"

//zmienne globalne
int X_RES,Y_RES;
float odleglosc;

Punkt2D::Punkt2D(Punkt3D p)
{
  x=(((p.x*odleglosc)/(odleglosc+p.z)+1)*(X_RES-1))/2;
  y=(((p.y*odleglosc)/(odleglosc+p.z)+1)*(Y_RES-1))/2;
}

Punkt3D Punkt3D::operator+(Punkt3D p)
{
  return Punkt3D(x+p.x,y+p.y,z+p.z);
}

Punkt3D Punkt3D::operator-(Punkt3D p)
{
  return Punkt3D(x-p.x,y-p.y,z-p.z);
}

Punkt3D Punkt3D::operator+=(Punkt3D p)
{
  return *this=*this+p;
}

Punkt3D Punkt3D::operator-=(Punkt3D p)
{
  return *this=*this-p;
}

Punkt3D Punkt3D::operator*(Punkt3D p)
{
  return Punkt3D(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
}

Punkt3D Punkt3D::operator*=(Punkt3D p)
{
  return *this=*this*p;
}

Punkt3D Punkt3D::operator*(float p)
{
  return Punkt3D(x*p,y*p,z*p);
}

Punkt3D Punkt3D::operator/(float p)
{
  return Punkt3D(x/p,y/p,z/p);
}

float Punkt3D::operator|(Punkt3D p)
{
  return x*p.x+y*p.y+z*p.z;
}

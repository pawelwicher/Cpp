#include "Punkty.h"

//zmienne globalne - do przeksztalcenia wspolrzednych tekstury
extern float a11,a12,a13,a14,a21,a22,a23,a24;
extern int x_tex,y_tex;

class Trojkat
{
  public:
  //wierzcholki trojkata
  Punkt3D a,b,c;

  //konstruktory
  Trojkat() : a(Punkt3D(0,0,0)), b(Punkt3D(0,0,0)), c(Punkt3D(0,0,0)) {}
  Trojkat(Punkt3D a,Punkt3D b,Punkt3D c) : a(a), b(b), c(c) {}

  //funkcja badajaca czy dany trojkat jest widoczny - czyli czy nalezy do rysowac
  bool CzyWidoczny();

  //funkcja, ktora pozwala na podstawie punktu w przestrzeni obrazu (2D) przejsc do odpowiedniego punktu 3D
  Punkt3D PrzejdzDo3D(Punkt2D Punkt);

  //funkcja wyliczajaca wpolrzedne tekstury na podstawie zadanego przeksztalcenia
  Punkt2D ObliczWspTekstury(Punkt3D Punkt);

  //funkcja rysujaca i nakladajaca teksture
  void Rysuj(Obraz* scena,Obraz* tekstura);
};

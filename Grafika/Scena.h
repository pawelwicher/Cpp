#include "Trojkat.h"

class Scena
{
public:
  Obraz* scena;
  Obraz* tekstura;
  Trojkat* trojkaty;
  Punkt3D* wierzcholki;

  Scena(int,int,float,AnsiString);
  ~Scena();
};


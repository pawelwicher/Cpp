//---------------------------------------------------------------------------
#include "WSort.h"
//---------------------------------------------------------------------------
int SzukajBinarnie(TabItem Tab[],int lewy,int prawy,int liczba,SortStatistics* lpSS)
{
int srodek;
lpSS->Cmp++;

if(lewy==prawy) return lewy;

srodek=lewy+((prawy-lewy)/2);

if(liczba>Tab[srodek]) return SzukajBinarnie(Tab,srodek+1,prawy,liczba,lpSS);
else if(liczba<Tab[srodek]) return SzukajBinarnie(Tab,lewy,srodek,liczba,lpSS);

return srodek;
}


bool extern "C"__declspec(dllexport) SortTab(TabItem* Tab, int N, SortStatistics* lpSS)
{
lpSS->BeginProc();

int i,j,szukany,tmp;
for (i=1;i<N;i++)
{
   szukany=SzukajBinarnie(Tab,0,i,Tab[i],lpSS);
   tmp=Tab[i];

   for(j=i-1;j>=szukany;j--)
      {Tab[j+1]=Tab[j]; lpSS->Exch++;}

   lpSS->Exch++;
   Tab[szukany]=tmp;
}

lpSS->EndProc();
return false;
}
//---------------------------------------------------------------------------

/*
  Parametry:
    Tab   - wska�nik do N elementowej tablicy.
            Uwaga! Zmienne pomocnicze musz� by� typu TabItem, sizeof(TabItem) = 8;
		   Typ TabItem jest kompatybilny z typem int.
    N     - liczba element�w.
    lpSS  - wska�nik do struktury statystyki, zawiera:

      UINT TabSize;       - wy�wietlana liczba element�w tablicy.
      UINT Cmp;           - licznik por�wna�.
      UINT Exch;          - licznik zamian.
      void BeginProc();
      void EndProc();     - funkcje, kt�re nale�y umie�ci� na pocz�tku i na ko�cu ka�dej
			    funkcji rekurencyjnej lub w�a�ciwej funkcji sortuj�cej (alg. bez rekurencji).
      void GetStackSize() - Nale�y umie�ci� na pocz�tku najg��biej wywo�ywanych funkcji w przypadku,
			    gdy nie wyst�puje w nich funkcja BeginProc().
			    (Np.: w funkcjach pomocniczych u�ywanych przez funkcje rekurencyjne)
      void UpdateDemo(int Flags, int a, int b = -1) - Uaktualnia wykres w tryb demo, funkcj� nale�y wywo�a�
                            ka�dorazowo po por�wnaniu lub modyfikacji tablicy (wymagane tylko dla trybu demo),
			    Flags: UDF_CMP - wyst�pi�o por�wnanie, UDF_EXCH - wyst�pi�a zamiana,
                            a,b - indeks/indeksy u�ywanych element�w tablicy.
*/

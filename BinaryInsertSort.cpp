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
    Tab   - wskaŸnik do N elementowej tablicy.
            Uwaga! Zmienne pomocnicze musz¹ byæ typu TabItem, sizeof(TabItem) = 8;
		   Typ TabItem jest kompatybilny z typem int.
    N     - liczba elementów.
    lpSS  - wskaŸnik do struktury statystyki, zawiera:

      UINT TabSize;       - wyœwietlana liczba elementów tablicy.
      UINT Cmp;           - licznik porównañ.
      UINT Exch;          - licznik zamian.
      void BeginProc();
      void EndProc();     - funkcje, które nale¿y umieœciæ na pocz¹tku i na koñcu ka¿dej
			    funkcji rekurencyjnej lub w³aœciwej funkcji sortuj¹cej (alg. bez rekurencji).
      void GetStackSize() - Nale¿y umieœciæ na pocz¹tku najg³êbiej wywo³ywanych funkcji w przypadku,
			    gdy nie wystêpuje w nich funkcja BeginProc().
			    (Np.: w funkcjach pomocniczych u¿ywanych przez funkcje rekurencyjne)
      void UpdateDemo(int Flags, int a, int b = -1) - Uaktualnia wykres w tryb demo, funkcjê nale¿y wywo³aæ
                            ka¿dorazowo po porównaniu lub modyfikacji tablicy (wymagane tylko dla trybu demo),
			    Flags: UDF_CMP - wyst¹pi³o porównanie, UDF_EXCH - wyst¹pi³a zamiana,
                            a,b - indeks/indeksy u¿ywanych elementów tablicy.
*/

#ifndef Operacje
#define Operacje

#include "Lista_1kc.h"
void ZapiszStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL1k,wL1k PoczL1k);
void ZrezygnujZKursu(wL1kc GlowaL1kc, wL2kc GlowaL2kc,wL2k PoczL2k);
int PokazKursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k,int id_studenta);
void DostepneKursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k);
void KursyStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k);
void KursyPracownika(wL1kc GlowaL1kc,wL1k Pocz);
void StudenciKursu(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k PoczL2k);
void UsunKurs(wL2kc GlowaL2kc,wL1kc GlowaL1kc);
void UsunStudenta(wL2kc GlowaL2kc,wL1kc GlowaL1kc,wL2k &Pocz,wL2k &Kon);
void UsunPracownika(wL1kc GlowaL1kc,wL1k &Pocz,wL1k &Kon);
void Zapisy(wL1k PoczL1k,wL2k PoczL2k,wL1k KonL1k,wL2k KonL2k,wL1kc GlowaL1kc,wL2kc GlowaL2kc);
#endif

#include <windows.h>
#include <ddraw.h>

#ifndef GRAFIKA
#define GRAFIKA


extern HWND hOkno;
extern LPDIRECTDRAW lpDD;
extern LPDIRECTDRAWSURFACE lpDDEkran;
extern LPDIRECTDRAWSURFACE lpDDBufory[10][10];
extern LPDIRECTDRAWSURFACE lpDDKwadraty[10][10];
extern RECT Src[10][10];
extern RECT Dst[10][10];

LRESULT CALLBACK ObslugaOkna(HWND,UINT,WPARAM,LPARAM);
void UtworzOknoDlaDD(HWND*);
void UtworzObiektyDD();
void SprzatanieDD();
LPDIRECTDRAWSURFACE NowaPowierzchnia(LPSTR);
void Animacja(LPDIRECTDRAWSURFACE,LPDIRECTDRAWSURFACE[10][10],LPDIRECTDRAWSURFACE[10][10],RECT[10][10],RECT[10][10],int[10][10]);
#endif

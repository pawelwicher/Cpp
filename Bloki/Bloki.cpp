#include "Grafika.h"
#include "Logika.h"


int WINAPI WinMain(HINSTANCE hProgram,HINSTANCE,LPSTR,int n)
{
    UtworzOknoDlaDD(&hOkno);
    ShowWindow(hOkno,n);
    UtworzObiektyDD();
    
    MSG msg;
    while (msg.message!=WM_QUIT)
    {
        if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }    
    SprzatanieDD();
    return msg.wParam;
}


LRESULT CALLBACK ObslugaOkna(HWND hOkno,UINT uMsg,WPARAM wPar,LPARAM lPar)
{
    switch(uMsg)
    {
    case WM_KEYDOWN:
    if(wPar==VK_ESCAPE) DestroyWindow(hOkno);
    if(wPar==VK_SPACE) {TAB(Plansza); Animacja(lpDDEkran,lpDDKwadraty,lpDDBufory,Src,Dst,Plansza);}
    break;
    case WM_DESTROY:
    PostQuitMessage(0);
    break;
    };
    
    return DefWindowProc(hOkno,uMsg,wPar,lPar);
}

#include "Grafika.h"

HWND hOkno;
LPDIRECTDRAW lpDD=NULL;
LPDIRECTDRAWSURFACE lpDDEkran=NULL;
LPDIRECTDRAWSURFACE lpDDBufory[10][10]={NULL};
LPDIRECTDRAWSURFACE lpDDKwadraty[10][10]={NULL};
RECT Src[10][10];
RECT Dst[10][10];

void UtworzOknoDlaDD(HWND *hOkno)
{
    HINSTANCE hProg = GetModuleHandle(NULL);
    
    WNDCLASS wc;
    wc.lpszClassName="Gra";
    wc.hInstance=hProg;
    wc.lpfnWndProc=ObslugaOkna;
    wc.style=0;
    wc.hIcon=LoadIcon(NULL,IDI_WINLOGO);
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName=NULL;
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    
    RegisterClass(&wc);
    
    *hOkno = CreateWindowEx(0,"Gra","Gra",WS_POPUP,50,50,300,200,NULL,NULL,hProg,NULL);
}


void UtworzObiektyDD()
{
    DirectDrawCreate(NULL,&lpDD,NULL);
    lpDD->SetCooperativeLevel(hOkno, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
    lpDD->SetDisplayMode(1280,1024,32);
    
    DDSURFACEDESC ddsd;
    ddsd.dwSize=sizeof(ddsd);
    ddsd.dwFlags=DDSD_CAPS|DDSD_BACKBUFFERCOUNT;
    ddsd.ddsCaps.dwCaps=DDSCAPS_PRIMARYSURFACE|DDSCAPS_COMPLEX|DDSCAPS_FLIP;
    ddsd.dwBackBufferCount=1;
    
    lpDD->CreateSurface(&ddsd,&lpDDEkran,NULL);
    ddsd.ddsCaps.dwCaps=DDSCAPS_BACKBUFFER;
    
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            lpDDEkran->GetAttachedSurface(&ddsd.ddsCaps,&lpDDBufory[i][j]);
    
    
    DDCOLORKEY ddck;
    ddck.dwColorSpaceLowValue=0;
    ddck.dwColorSpaceHighValue=0;
    
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            lpDDKwadraty[i][j]=NowaPowierzchnia("Grafika\\Kwadrat.bmp");
            lpDDKwadraty[i][j]->SetColorKey(DDCKEY_SRCBLT,&ddck);
        }
}


void SprzatanieDD()
{     
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            if(lpDDKwadraty[i][j]!=NULL) lpDDKwadraty[i][j]->Release();
            lpDDKwadraty[i][j]=NULL;
        }
    
    if(lpDDEkran!=NULL) lpDDEkran->Release();
    lpDDEkran = NULL;
    
    if(lpDD!=NULL) lpDD->Release();
    lpDD = NULL;
}


LPDIRECTDRAWSURFACE NowaPowierzchnia(LPSTR nazwa)
{
    LPDIRECTDRAWSURFACE lpDDNowa;
    DDSURFACEDESC ddsd;
    HBITMAP bitmapa;
    BITMAP bmp;
    HDC pomoc;
    HDC hdc;
    
    bitmapa = (HBITMAP) LoadImage(NULL,nazwa,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    if(bitmapa==NULL) return NULL;
    pomoc = CreateCompatibleDC(NULL);
    SelectObject(pomoc,bitmapa);
    
    GetObject(bitmapa,sizeof(bmp),&bmp);
    ddsd.dwSize=sizeof(ddsd);
    ddsd.dwFlags=DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    ddsd.ddsCaps.dwCaps=DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
    ddsd.dwWidth=bmp.bmWidth;  ddsd.dwHeight = bmp.bmHeight;
    
    lpDD->CreateSurface(&ddsd,&lpDDNowa,NULL);
    
    lpDDNowa->GetDC(&hdc);
    BitBlt(hdc,0,0, bmp.bmWidth, bmp.bmHeight, pomoc,0,0,SRCCOPY);
    lpDDNowa->ReleaseDC(hdc);
    
    DeleteDC(pomoc);
    DeleteObject(bitmapa);
    
    return lpDDNowa;
}


void Animacja(LPDIRECTDRAWSURFACE lpDDEkran,LPDIRECTDRAWSURFACE lpDDKwadraty[10][10],
LPDIRECTDRAWSURFACE lpDDBufory[10][10],RECT src[10][10],RECT dst[10][10],int Tab[10][10])
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            SetRect(&src[i][j],Tab[i][j]*50,0,Tab[i][j]*50+50,50);
            SetRect(&dst[i][j],0+50*i,0+50*j,50+50*i,50+50*j);
            lpDDBufory[i][j]->Blt(&dst[i][j],lpDDKwadraty[i][j],&src[i][j],DDBLT_KEYSRC|DDBLT_WAIT,NULL);
        }
    lpDDEkran->Flip(NULL,DDFLIP_WAIT);                    
}

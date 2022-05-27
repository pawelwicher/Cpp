//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Gra.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Snake* S;

//---------------------------------------------------------------------------

void Rysuj(TImage* Image1,Snake* S)
{
    TRect Rect(0,0,600,400);
    Image1->Canvas->Brush->Color=clWhite;
    Image1->Canvas->FillRect(Rect);

    for(int i=0;i<16;i++)
        for(int j=0;j<24;j++)
        {
        if(S->plansza.plansza[i][j]==0)
            {
            int x=j,y=i;
            TRect Rect(x*25,y*25,(x+1)*25,(y+1)*25);
            Image1->Canvas->Brush->Color=clBlue;
            Image1->Canvas->FillRect(Rect);
            }
        if(S->plansza.plansza[i][j]==2)
            {
            int x=j,y=i;
            TRect Rect(x*25,y*25,(x+1)*25,(y+1)*25);
            Image1->Canvas->Brush->Color=clRed;
            Image1->Canvas->FillRect(Rect);
            }
        }
}
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
DoubleBuffered=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Klawisz(TObject *Sender, char &Key)
{
    switch(Key)
    {
    case 'j': S->Lewo(); break;
    case 'i': S->Gora(); break;
    case 'l': S->Prawo(); break;
    case 'k': S->Dol(); break;

    case 13:
        S=new Snake;
        int i=0;

        while(stop==false)
        {
        Application->ProcessMessages();
            if(i==100)
            {
            Form1->Caption="Wynik: "+AnsiString(S->wynik);
            S->Ruch();
            S->zmiana=true;
            Rysuj(Image1,S);
            i=0;
            }
            else i++;
        Sleep(1);
        }
        Form1->Caption="GAME OVER - Wynik: "+AnsiString(S->wynik);
        delete S;

    break;
    }
}
//---------------------------------------------------------------------------


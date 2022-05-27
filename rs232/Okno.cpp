#pragma hdrstop
#include "Okno.h"
#include "Polaczenie.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
Polaczenie* P=new Polaczenie();
bool nasluch,nadawanie;
int wyslane=0,odebrane=0;
int nr=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
  nasluch=false;
  nadawanie=false;
  Memo1->ReadOnly=true;
  status->Caption="NIE PO£¥CZONY";
  status->Font->Color=clRed;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
  char znak;
  
  if(nadawanie)
  {
    P->SendChar(Key);
    if(Key==27)
    {
      Transmisja_Stop();
    }
    else
    {
      wyslane++;
    }
    Label1->Caption="znaki wys³ane: "+AnsiString(wyslane);
  }
  else
  {
    if(Key==13)
    {
      nasluch=true;
      status->Caption="oczekuje na nawi¹zanie po³¹czenia...";
      status->Caption=status->Caption.UpperCase();
      status->Font->Color=clYellow;
      while(nasluch)
      {
        Application->ProcessMessages();
        P->SendChar('~');
        P->GetChar(znak);
        if(znak=='~')
        {
          nasluch=false;
          nadawanie=true;
        }
      }
      Transmisja_Start();
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  Memo1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Transmisja_Start()
{
  char c;
  AnsiString text;
  status->Caption="PO£¥CZONY";
  status->Font->Color=clGreen;
  Memo1->ReadOnly=false;
  Memo1->SetFocus();

  while(nadawanie)
  {
    if(P->GetChar(c) && c!='~')
    {
      if(c==13)
      {
        Memo2->Lines->Add("");
        odebrane++;
      }
      else if(c==8)
      {
        text=Memo2->Text;
        Memo2->Text=text.SubString(0,text.Length()-1);
        odebrane++;
      }
      else if(c==27)
      {
        Transmisja_Stop();
      }
      else
      {
        Memo2->Text=Memo2->Text+AnsiString(c);
        Memo2->SelStart=Memo2->Text.Length();
        Memo2->SelLength=Memo2->Text.Length();
        odebrane++;
      }
      Label2->Caption="znaki odebrane: "+AnsiString(odebrane);
    }
    Application->ProcessMessages();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Transmisja_Stop()
{
  nasluch=false;
  nadawanie=false;
  Memo1->ReadOnly=true;
  status->Caption="NIE PO£¥CZONY";
  status->Font->Color=clRed;
  Memo2->Lines->Add("znaki odebrane: "+AnsiString(odebrane)); 
  Memo2->Lines->SaveToFile(AnsiString(++nr)+".txt");
  Label1->Caption="znaki wys³ane: "+AnsiString(wyslane=0);
  Label2->Caption="znaki odebrane: "+AnsiString(odebrane=0);
  Memo1->Clear();
  Memo2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(!nadawanie)
  {
    Transmisja_Stop();
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#ifndef OknoH
#define OknoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TLabel *Label2;
        TMemo *Memo2;
        TLabel *status;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall Memo1KeyPress(TObject *Sender, char &Key);
        void __fastcall Memo2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall Transmisja_Start();
        void __fastcall Transmisja_Stop();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

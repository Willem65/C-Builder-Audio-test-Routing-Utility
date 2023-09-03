//---------------------------------------------------------------------------

#ifndef WillemFormCodeH
#define WillemFormCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>



//---------------------------------------------------------------------------
class TWillemForm1 : public TForm
{

__published:	// IDE-managed Components
        TMemo *memLog;
        TEdit *UDPEdit;
        TButton *btnOpen;
        TTimer *RefreshTimer;
        TComboBox *lstInterfaces;
        TLabel *Label2;
        TLabel *Label22;
        TProgressBar *ProgressBar1;
    TButton *Button1;
	TLabel *Label1;
	TLabel *Label3;
	TTrackBar *TrackBar1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnOpenClick(TObject *Sender);
        void __fastcall RefreshTimerTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
         struct mbn_handler *mbn;
         struct mbn_if_ethernet *iflist;
        __fastcall TWillemForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWillemForm1 *WillemForm1;
//---------------------------------------------------------------------------
#endif

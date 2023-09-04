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
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TProgressBar *ProgressBar4;
	TTrackBar *TrackBar2;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button2;
	TLabel *Label6;
	TButton *Button3;
	TLabel *Label7;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TTrackBar *TrackBar3;
	TTrackBar *TrackBar4;
	TTrackBar *TrackBar5;
	TTrackBar *TrackBar6;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TMemo *Memo1;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TProgressBar *ProgressBar5;
	TProgressBar *ProgressBar6;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TProgressBar *ProgressBar7;
	TLabel *Label35;
	TProgressBar *ProgressBar8;
	TProgressBar *ProgressBar9;
	TProgressBar *ProgressBar10;
	TLabel *Label37;
	TProgressBar *ProgressBar11;
	TProgressBar *ProgressBar12;
	TProgressBar *ProgressBar13;
	TProgressBar *ProgressBar14;
	TProgressBar *ProgressBar15;
	TProgressBar *ProgressBar16;
	TLabel *Label36;
	TLabel *Label38;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
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

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
#include <Vcl.Graphics.hpp>



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
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TProgressBar *ProgressBar4;
	TTrackBar *TrackBar2;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button3;
	TLabel *LCD1line1;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
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
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TMemo *memLog2;
	TLabel *Label27;
	TLabel *Label28;
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
	TProgressBar *ProgressBar15;
	TProgressBar *ProgressBar16;
	TLabel *Label36;
	TLabel *Label38;
	TLabel *Label39;
	TCheckBox *CheckBox1;
	TLabel *LCD1line2;
	TLabel *LCD2line1;
	TLabel *LCD2line2;
	TLabel *SourceLabel;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label20;
	TLabel *Label21;
	TGroupBox *GroupBox7;
	TLabel *Label57;
	TGroupBox *GroupBox5;
	TGroupBox *GroupBox6;
	TLabel *Label25;
	TLabel *Label29;
	TLabel *Label40;
	TLabel *Label42;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label43;
	TLabel *Label44;
	TTrackBar *TrackBar3;
	TTrackBar *TrackBar4;
	TTrackBar *TrackBar5;
	TTrackBar *TrackBar6;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox9;
	TGroupBox *GroupBox10;
	TGroupBox *GroupBox11;
	TLabel *Label45;
	TLabel *Label41;
	TTrackBar *TrackBar1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label46;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label50;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TLabel *Label56;
	TLabel *Label58;
	TGroupBox *GroupBox1;
	TLabel *Label60;
	TLabel *Label61;
	TButton *Button2;
	TTimer *TimerStartDelay;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TTimer *OnlineDetectTimer;
	TLabel *Label26;
	TLabel *Label59;
	TLabel *Label62;
	TLabel *Label63;
	TLabel *Label64;
	TLabel *Label65;
	TLabel *Label66;
	TLabel *Label67;
	TLabel *Label68;
	TLabel *Label69;
	TLabel *Label70;
	TLabel *Label71;
	TLabel *Label72;
	TLabel *Label73;
	TLabel *Label74;
	TLabel *Label75;
	TButton *Button13;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *Label79;
	TLabel *Label78;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TLabel *Label83;
	TLabel *Label84;
	TLabel *Label85;
	TLabel *Label86;
	TLabel *Label87;
	TLabel *Label88;
	TLabel *Label89;
	TLabel *Label90;
	TLabel *Label91;
	TLabel *Label92;
	TLabel *Label93;
	TLabel *Label94;
	TLabel *Label95;
	TLabel *Label96;
	TLabel *Label97;
	TLabel *Label98;
	TLabel *Label99;
	TLabel *Label100;
	TLabel *Label101;
	TLabel *Label102;
	TLabel *Label103;
	TLabel *Label104;
	TLabel *Label105;
	TLabel *Label106;
	TLabel *Label107;
	TLabel *Label108;
	TLabel *Label109;
	TLabel *Label110;
	TLabel *Label111;
	TLabel *Label112;
	TLabel *Label113;
	TLabel *Label114;
	TLabel *Label115;
	TLabel *Label116;
	TLabel *Label117;
	TLabel *Label118;
	TLabel *Label119;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnOpenClick(TObject *Sender);
	void __fastcall RefreshTimerTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall SourceLabelClick(TObject *Sender);
	void __fastcall Label6Click(TObject *Sender);
	void __fastcall Label20Click(TObject *Sender);
	void __fastcall Label21Click(TObject *Sender);
	void __fastcall Label25Click(TObject *Sender);
	void __fastcall Label40Click(TObject *Sender);
	void __fastcall Label42Click(TObject *Sender);
	void __fastcall Label29Click(TObject *Sender);
	void __fastcall Label23Click(TObject *Sender);
	void __fastcall Label43Click(TObject *Sender);
	void __fastcall Label44Click(TObject *Sender);
	void __fastcall Label24Click(TObject *Sender);
	void __fastcall Label45Click(TObject *Sender);
	void __fastcall Label41Click(TObject *Sender);
    void __fastcall Label7Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall TrackBar4Change(TObject *Sender);
	void __fastcall TrackBar5Change(TObject *Sender);
	void __fastcall TrackBar6Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TimerStartDelayTimer(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall OnlineDetectTimerTimer(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	//void __fastcall Label76Click(TObject *Sender);

	void __fastcall Label76MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Label76MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

	//void __fastcall Label77Click(TObject *Sender);

	void __fastcall Label77MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Label77MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

	//void __fastcall Label78Click(TObject *Sender);

	void __fastcall Label78MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Label78MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

	//void __fastcall Label79Click(TObject *Sender);

	void __fastcall Label79MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Label79MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

private:	// User declarations
public:		// User declarations

		 struct mbn_handler *mbn;
		 struct mbn_if_ethernet *iflist;
        __fastcall TWillemForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWillemForm1 *WillemForm1;
extern   int uniqueidval;
//---------------------------------------------------------------------------
#endif

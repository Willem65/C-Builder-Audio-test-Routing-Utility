//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#define MBN_VARARG

#include "WillemFormCode.h"

//----------Hieronder mijn toegevoegde include files----------------------------------
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "mbn.h"

unsigned int trackBar3Position, faderPosition;
unsigned int count, count1, count2, toestand;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TWillemForm1 *WillemForm1;

static int online = 0;
int checkBox1;


//  Callback functies
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid)
{
	if( valid )
		online = (int)valid;

}

float vuValueL, vuValueR, vuValueL2, vuValueR2, vuValueL3, vuValueR3, vuValueL4, vuValueR4, vuValueL5, vuValueR5, vuValueL6, vuValueR6;
char bufferVuMeter[32];



int mSensorDataChanged(struct mbn_handler *mbn, struct mbn_message *msg, unsigned short obj, unsigned char type, union mbn_data dat)
{
	return 0;
}




//---------------------------------------------------------------------------
__fastcall TWillemForm1::TWillemForm1(TComponent* Owner)
		: TForm(Owner)
{
	iflist = 0;
}
//---------------------------------------------------------------------------



void __fastcall TWillemForm1::FormCreate(TObject *Sender)
{
	char err[MBN_ERRSIZE], ifdesc[512];
	struct mbn_if_ethernet *n;

	if((iflist = mbnEthernetIFList(err)) == 0)
	{
        //addlog(LF_APP, "Error getting interface list: %s", err);
		UDPEdit->Text = "Willem";
	}
    else
	{
        lstInterfaces->Items->Clear();
		
		for(n=iflist; n!=0; n=n->next)
        {
            sprintf(ifdesc, "%02X:%02X:%02X:%02X:%02X:%02X", n->addr[0], n->addr[1], n->addr[2], n->addr[3], n->addr[4], n->addr[5]);
            lstInterfaces->Items->AddObject(ifdesc, (TObject *)n->name);
        }

		lstInterfaces->ItemIndex = 0;

	}


	// iterate through all controls on Form1  TWillemForm1->ControlCount, Disable all Controls
	for (int i = 0; i < WillemForm1->ControlCount ; i++)
	{
		// disable the control by setting Enabled property to false
		WillemForm1->Controls[i]->Enabled = false;
	}

	CheckBox1->Checked = true;

		checkBox1=1;


	btnOpen->Enabled = true;
	UDPEdit->Enabled = true;
	Button2->Enabled = true;
	Button9->Enabled = true;
	Button10->Enabled = true;
	Button11->Enabled = true;
    Button12->Enabled = true;

	//----------------------------------------------------- Read from file
	std::string fileContent;
	std::ifstream file;
	//std::ifstream inputFile;
	std::string ipString;
	std::string crmStdPot;
	std::string	faders;

	char Temp[16];

   file.open("settings.txt");


   if (file.is_open())
   {
		std::string line;

		while (std::getline(file, line))
		{
			if (line.find("ip address  = ") != std::string::npos)
			{
				ipString = line.c_str();
			}
			if (line.find("monitorPots = ") != std::string::npos)
			{
				crmStdPot = line.c_str();
			}
			if (line.find("faders      = ") != std::string::npos)
			{
				faders = line.c_str();
			}
		}

		file.close();
	}
	else
	{
		std::cout << "Unable to open file ip.txt" << std::endl;
	}

	String s = ipString.c_str();
	int text = s.Length();
	StrPCopy(Temp, s.SubString1( 15 , text-2 ));
	UDPEdit->Text = Temp;
	memLog->Text = online;

	String s2 = ipString.c_str();
	int text2 = s2.Length();
	StrPCopy(Temp, s2.SubString1( 15 , text2-2 ));
	memLog->Lines->Add(Temp);

	String s3 = crmStdPot.c_str();
	int text3 = s3.Length();
	StrPCopy(Temp, s3.SubString1( 15 , text3-2 ));
	memLog->Lines->Add(Temp);
	trackBar3Position = StrToInt(Temp);

	String s4 = faders.c_str();
	int text4 = s4.Length();
	StrPCopy(Temp, s4.SubString1( 15 , text4-2 ));
	memLog->Lines->Add(Temp);
	faderPosition = StrToInt(Temp);
}







int oldOnline, started;
static int oldtst, oldtstR, oldtst2, oldtstR2, newtst;

//----------------------- De VU meters -------------------------------------
void __fastcall TWillemForm1::RefreshTimerTimer(TObject *Sender)
{
        if ( online != oldOnline)
        {
			memLog->Lines->Add(online);
			started=1;
			//WillemForm1->Label7->Click();
			TimerStartDelay->Enabled = true;

		}

		online = oldOnline;


		if ( started )
		{


			if (oldtst > 0)         oldtst = oldtst - 3;
			if (oldtst < 0)         oldtst = vuValueL;
			if (oldtst < vuValueL)  oldtst = vuValueL;


		   if (oldtstR > 0)         oldtstR = oldtstR - 3;
		   if (oldtstR < 0)         oldtstR = vuValueR;
		   if (oldtstR < vuValueR)  oldtstR = vuValueR;



		   if (oldtst2 > 0)         oldtst2 = oldtst2 - 3;
		   if (oldtst2 < 0)         oldtst2 = vuValueL2;
		   if (oldtst2 < vuValueL2)  oldtst2 = vuValueL2;


		   if (oldtstR2 > 0)         oldtstR2 = oldtstR2 - 3;
		   if (oldtstR2 < 0)         oldtstR2 = vuValueR2;
		   if (oldtstR2 < vuValueR2)  oldtstR2 = vuValueR2;



		   ProgressBar1->Position = oldtst;
		   ProgressBar2->Position = oldtstR;

		   ProgressBar3->Position = oldtst2;
		   ProgressBar4->Position = oldtstR2;

		   ProgressBar5->Position = vuValueL4;
		   ProgressBar6->Position = vuValueR4;

		   ProgressBar7->Position = vuValueL5;
		   ProgressBar8->Position = vuValueR5;

		   ProgressBar9->Position = vuValueL6;
		   ProgressBar10->Position = vuValueR6;

		   ProgressBar15->Position = vuValueL3;
		   ProgressBar16->Position = vuValueR3;

//			if (checkBox1 == 1 )
//			{
//				char Temp[32];
//				sprintf(Temp, "#%04d_%04d #%04d_%04d", 1088, (int)vuValueL, 1089, (int)vuValueR);
//				memLog->Lines->Add(Temp);
//			}

		}
		double tst=1;
}


//--------------- Moving the Faders ------------------------------------------------
void __fastcall TWillemForm1::Button1Click(TObject *Sender)
{
	count = count1 = count2 = toestand = 0;
	TimerStartDelay->Enabled = true;

}
//---------------------------------------------------------------------------


//---------------- Debug Checkbox ---------------------------------------------
void __fastcall TWillemForm1::CheckBox1Click(TObject *Sender)
{

	if ( CheckBox1->Checked == True )
	{
		checkBox1=1;
	}
	else
	{
	  checkBox1=0;
	}
	//memLog->Lines->Add(plus10dB);
}




//------------------- Start external programs --------------------------------------------------------
void __fastcall TWillemForm1::Button2Click(TObject *Sender)
{
	// Execute the Notepad application
	system("notepad.exe settings.txt");

}
//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Button9Click(TObject *Sender)
{
	//system("Call PUTTY.EXE");
	ShellExecute(0, L"open", L"PUTTY.EXE", 0, 0, SW_SHOW);

}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button10Click(TObject *Sender)
{
	//system("filezilla\\filezilla.exe");
	ShellExecute(0, L"open", L"filezilla\\filezilla.exe", 0, 0, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button11Click(TObject *Sender)
{
	  //system("ADVIPSCN\\advanced_ip_scanner.exe");
	  ShellExecute(0, L"open", L"ADVIPSCN\\advanced_ip_scanner.exe", 0, 0, SW_SHOW);
}
//-----------ADVIPSCN------------advanced_ip_scanner.exe----------------------------------------------------

void __fastcall TWillemForm1::Button12Click(TObject *Sender)
{
	  system("notepad.exe info.txt");
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::OnlineDetectTimerTimer(TObject *Sender)
{
   		if ( started == 0 )
		{
			ShowMessage("Wrong IP address, or axum server is not running");
			OnlineDetectTimer->Enabled = false;
		}
		OnlineDetectTimer->Enabled = false;

}
//---------------------------------------------------------------------------


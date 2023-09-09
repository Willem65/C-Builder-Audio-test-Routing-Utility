//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#define MBN_VARARG

#include <stdio.h>
#include <iostream>
#include <fstream>


#include <string>
//#include <sstream>
//#include <stdarg.h>
//#include <string.h>
 

#include "mbn.h" 
#include "WillemFormCode.h"
#include "MonitorPotentials.h"

int trackBar3Position, faderPosition;
unsigned int count, count1, count2, toestand;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


#define LF_APP 1
#define LF_CB  2
#define LF_OBJ 3
#define LF_ADR 4

TWillemForm1 *WillemForm1;

static int online = 0;
int checkBox1;
//extern unsigned int count, count1, count2, toestand;
//int trackBar3Position, faderPosition;


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


int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat)
{
	if ( obj > 1047 )                // Logger
	{
		if (checkBox1 == 1 )
		{
			char Temp[32];
			sprintf(Temp, "#%04d_%04d", obj,  (int)dat.UInt);
			WillemForm1->memLog2->Lines->Add(Temp);
		}
	}



	//------------------------------------- Vu Meters 1  Links
	if ( obj == 1036 )
	{

		int ValueL = (int)dat.Float;
		if ( ValueL > -50 )
		{

			vuValueL = 50+dat.Float;
			vuValueL = ((vuValueL)*10);

		}
		else
		{
			vuValueL = 0;
		}


	}
	else if ( obj == 1037 )
	{

		int ValueR = (int)dat.Float;             // Rechts
		if ( ValueR > -50 )
		{

			vuValueR = 50+dat.Float;
			vuValueR = ((vuValueR)*10);

		}
		else
		{
			vuValueR = 0;
		}
	}
	//------------------------------------------ Vu Meters 2    Links
	if ( obj == 1038 )
	{

		int ValueL2 = (int)dat.Float;
		if ( ValueL2 > -50 )
		{

			vuValueL2 = 50+dat.Float;
			vuValueL2 = ((vuValueL2)*10);

		}
		else
		{
			vuValueL2 = 0;
		}


	}
	else if ( obj == 1039 )
	{

		int ValueR2 = (int)dat.Float;         // Rechts
		if ( ValueR2 > -50 )
		{

			vuValueR2 = 50+dat.Float;
			vuValueR2 = ((vuValueR2)*10);

		}
		else
		{
			vuValueR2 = 0;
		}
	}

	//------------------------------------------ Vu Meters 3    Links
	if ( obj == 1040 )
	{

		int ValueL3 = (int)dat.Float;
		if ( ValueL3 > -50 )
		{

			vuValueL3 = 50+dat.Float;
			vuValueL3 = ((vuValueL3)*10);

		}
		else
		{
			vuValueL3 = 0;
		}


	}
	else if ( obj == 1041 )
	{

		int ValueR3 = (int)dat.Float;         // Rechts
		if ( ValueR3 > -50 )
		{

			vuValueR3 = 50+dat.Float;
			vuValueR3 = ((vuValueR3)*10);

		}
		else
		{
			vuValueR3 = 0;
		}
	}

	//------------------------------------------ Vu Meters 4    Links
	if ( obj == 1042 )
	{

		int ValueL4 = (int)dat.Float;
		if ( ValueL4 > -50 )
		{

			vuValueL4 = 50+dat.Float;
			vuValueL4 = ((vuValueL4)*10);

		}
		else
		{
			vuValueL4 = 0;
		}


	}
	else if ( obj == 1043 )
	{

		int ValueR4 = (int)dat.Float;         // Rechts
		if ( ValueR4 > -50 )
		{

			vuValueR4 = 50+dat.Float;
			vuValueR4 = ((vuValueR4)*10);

		}
		else
		{
			vuValueR4 = 0;
		}
	}

	//------------------------------------------ Vu Meters 5    Links
	if ( obj == 1044 )
	{

		int ValueL5 = (int)dat.Float;
		if ( ValueL5 > -50 )
		{

			vuValueL5 = 50+dat.Float;
			vuValueL5 = ((vuValueL5)*10);

		}
		else
		{
			vuValueL5 = 0;
		}


	}
	else if ( obj == 1045 )
	{

		int ValueR5 = (int)dat.Float;         // Rechts
		if ( ValueR5 > -50 )
		{

			vuValueR5 = 50+dat.Float;
			vuValueR5 = ((vuValueR5)*10);

		}
		else
		{
			vuValueR5 = 0;
		}
	}


	//------------------------------------------ Vu Meters 6    Links
	if ( obj == 1046 )
	{

		int ValueL6 = (int)dat.Float;
		if ( ValueL6 > -50 )
		{

			vuValueL6 = 50+dat.Float;
			vuValueL6 = ((vuValueL6)*10);

		}
		else
		{
			vuValueL6 = 0;
		}


	}
	else if ( obj == 1047 )
	{

		int ValueR6 = (int)dat.Float;         // Rechts
		if ( ValueR6 > -50 )
		{

			vuValueR6 = 50+dat.Float;
			vuValueR6 = ((vuValueR6)*10);

		}
		else
		{
			vuValueR6 = 0;
		}
	}




// ---------------------------- Oled Display Text -------------------------------------------
	if (obj == 1024)
	{
		char buf[16];
		sprintf(buf, "%s", dat.Octets);
		WillemForm1->LCD1line1->Caption = buf;
	}
	else if (obj == 1030)
	{
		char buf[16];
		sprintf(buf, "%s", dat.Octets);
		WillemForm1->LCD1line2->Caption = buf;
	}
	else if (obj == 1025)
	{
		char buf[16];
		sprintf(buf, "%s", dat.Octets);
		WillemForm1->LCD2line1->Caption = buf;
	}
	else if (obj == 1031)
	{
		char buf[16];
		sprintf(buf, "%s", dat.Octets);
		WillemForm1->LCD2line2->Caption = buf;
	}

	//else if (obje >= 1138 && obje <= 1191)
//
//	else if (obj == 1138 )
//	{
//		//PGM label
//		if (dat.State)
//		{
//			WillemForm1->Label1->Caption="PGM";
//		}
//		else
//		{
//			WillemForm1->Label1->Caption="";
//		}
//	}
//
//	else if (obj == 1144 )
//	{
//		if (dat.State)
//			WillemForm1->Label3->Caption="SUB";
//		else
//			WillemForm1->Label3->Caption="";
//	}
//	else if (obj == 1144 )
//	{
//		if (dat.State)
//			WillemForm1->Label46->Caption="SUB";
//		else
//			WillemForm1->Label46->Caption="";
//	}

	//---------------------------------------------------------------------------
	// labels als knoppen

	else if (obj == 1195)      //source
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->SourceLabel->Color = clLime;
		else
		  WillemForm1->SourceLabel->Color = clInactiveCaption;

	}
	else if (obj == 1192)    //prog
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label6->Color = clLime;
		else
		  WillemForm1->Label6->Color = clInactiveCaption;

	}
	else if (obj == 1193)    //sub
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label20->Color = clLime;
		else
		  WillemForm1->Label20->Color = clInactiveCaption;

	}
	else if (obj == 1194)    //dump
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label21->Color = clLime;
		else
		  WillemForm1->Label21->Color = clInactiveCaption;

	}

	else if (obj == 1072)    //pfl mod1
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label7->Color = clLime;
		else
		  WillemForm1->Label7->Color = clInactiveCaption;

	}
	else if (obj == 1197)    //aux
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label45->Color = clLime;
		else
		  WillemForm1->Label45->Color = clInactiveCaption;

	}
		else if (obj == 1073)    //pfl mod2
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label41->Color = clLime;
		else
		  WillemForm1->Label41->Color = clInactiveCaption;

	}






	// labels als knoppen
	else if (obj == 1230)    //prog mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label25->Color = clLime;
		else
		  WillemForm1->Label25->Color = clInactiveCaption;

	}
	else if (obj == 1232)    //sub mon1 crm
	{

		int t=(int)dat.UInt;
		if( t > 0 )
		  WillemForm1->Label40->Color = clLime;
		else
		  WillemForm1->Label40->Color = clInactiveCaption;
	}
	else if (obj == 1234)    //aux mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label42->Color = clLime;
		else
		  WillemForm1->Label42->Color = clInactiveCaption;

	}
		else if (obj == 1236)    //pfl mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label29->Color = clLime;
		else
		  WillemForm1->Label29->Color = clInactiveCaption;

	}











	// labels als knoppen
	else if (obj == 1231)    //prog mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label23->Color = clLime;
		else
		  WillemForm1->Label23->Color = clInactiveCaption;

	}
	else if (obj == 1233)    //sub mon1 crm
	{

		int t=(int)dat.UInt;
		if( t > 0 )
		  WillemForm1->Label43->Color = clLime;
		else
		  WillemForm1->Label43->Color = clInactiveCaption;
	}
	else if (obj == 1235)    //aux mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label44->Color = clLime;
		else
		  WillemForm1->Label44->Color = clInactiveCaption;

	}
		else if (obj == 1237)    //pfl mon1 crm
	{

		int t=dat.UInt;
		if( t > 0 )
		  WillemForm1->Label24->Color = clLime;
		else
		  WillemForm1->Label24->Color = clInactiveCaption;

	}









   // ---------------------------- Oled Log Data to memLog2 -------------------------------------------
//	if (obj >= 1036 && obj <= 1047)
//	{
//		char Temp[32];
//		unsigned int Value = 132+((unsigned int)dat.Float);
//		Value = ((Value)*7);
//		sprintf(Temp, "#%04d_%04d", obj,  Value);
//		WillemForm1->memLog2->Lines->Add(Temp);
//	}
//	else if (obj > 1047)
//	{
//		char Temp[32];
//		sprintf(Temp, "%04d_%04d", obj, (int)dat.UInt);
//		WillemForm1->memLog2->Lines->Add(Temp);
//	}



	return 0;
}

//---------------------------------------------------------------------------
__fastcall TWillemForm1::TWillemForm1(TComponent* Owner)
        : TForm(Owner)
{
	iflist = NULL;
}
//---------------------------------------------------------------------------



void __fastcall TWillemForm1::FormCreate(TObject *Sender)
{
	char err[MBN_ERRSIZE], ifdesc[512];
	struct mbn_if_ethernet *n;
	
    if((iflist = mbnEthernetIFList(err)) == NULL)
	{
        //addlog(LF_APP, "Error getting interface list: %s", err);
		UDPEdit->Text = "Willem";
	}
    else
	{
        lstInterfaces->Items->Clear();
		
		for(n=iflist; n!=NULL; n=n->next)
        {
            sprintf(ifdesc, "%02X:%02X:%02X:%02X:%02X:%02X", n->addr[0], n->addr[1], n->addr[2], n->addr[3], n->addr[4], n->addr[5]);
            lstInterfaces->Items->AddObject(ifdesc, (TObject *)n->name);
        }

		lstInterfaces->ItemIndex = 0;

	}


	// iterate through all controls on Form1  TWillemForm1->ControlCount

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
	//--------------------------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::btnOpenClick(TObject *Sender)
{


 	for (int i = 0; i < WillemForm1->ControlCount ; i++)
	{
		// disable the control by setting Enabled property to false
		WillemForm1->Controls[i]->Enabled = true;
	}


	int cnt;
	int cntvu_busses;
	struct mbn_interface *itf;
	char error[MBN_ERRSIZE];

	char Temp[16];
	//char *url;
	//char *port_found;
	char url[256];
	char port[16];
	char obj_desc[32];
	struct mbn_node_info thisnodeB;
	int cntSwitch;
	struct mbn_object objects[370];
	//struct mbn_object objects[350];
	int cntObject = 0;


 
	String s = UDPEdit->Text;

	//AnsiString s = UDPEdit->Text;

	//UnicodeString s = UDPEdit->Text;

	StrPCopy(Temp, s);



	//AnsiString udpText = "192.168.1.76";

	//UnicodeString udpText = UDPEdit->Text;

	//int text = s.Length();

	//StrPCopy(Temp, s.SubString1( 2 , text-1 ));



//	//------------------------------------------- write to file
//	std::ofstream outputFile;
//	outputFile.open("ip.txt");
//
//	if (outputFile.is_open())
//	{
//		outputFile << Temp << std::endl;
//		outputFile.close();
//	}
//	else
//		std::cout << "Unable to open the file." << std::endl;
//	//----------------------------------------------------------------


   itf = mbnUDPOpen(Temp, strdup("34848"), NULL, error);  // Maak verbinding met ethernet  // strdup( ) handige functie



	if( itf == NULL )
	{
		memLog->Lines->Add( "EthernetOpen failed: %s" );
		return;
	}

	//thisnodeB.UniqueIDPerProduct = 8;


	thisnodeB.MambaNetAddr = 0;
	thisnodeB.Services = 0;
	sprintf(thisnodeB.Description, "Axite Control Surface 6 Faders + CRM");
	sprintf(thisnodeB.Name, "Test Node D&R");
	thisnodeB.ManufacturerID = 0x0001;
	thisnodeB.ProductID = 0x0022;
	thisnodeB.UniqueIDPerProduct = 0x110;   //UniqueIDPerProduct
	thisnodeB.HardwareMajorRevision = 0;
	thisnodeB.HardwareMinorRevision = 0;
	thisnodeB.FirmwareMajorRevision = 1;
	thisnodeB.FirmwareMinorRevision = 3;
	thisnodeB.FPGAFirmwareMajorRevision = 0;
	thisnodeB.FPGAFirmwareMinorRevision = 0;
	thisnodeB.NumberOfObjects = 0;
	thisnodeB.DefaultEngineAddr = 0;
	thisnodeB.HardwareParent[0] = 0;
	thisnodeB.HardwareParent[1] = 0;
	thisnodeB.HardwareParent[2] = 0;
	thisnodeB.ServiceRequest = 0;
	/* 1024 - 1035: OLED Display lines */
	for (cnt=0; cnt<6; cnt++)
	{
		sprintf(obj_desc, "Display %d Line 1", cnt+1);
		
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
		
		//objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 0, 2 , 0, 512, 256, MBN_DATATYPE_NODATA);
	}
	for (cnt=0; cnt<6; cnt++) 
	{
		sprintf(obj_desc, "Display %d Line 2", cnt+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
	}
	
	/* 1036 - 1047: Stereo Audio level metering */
	for (cnt=0; cnt<6; cnt++) 
	{
		sprintf(obj_desc, "Display Meter %d Left dB", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
		sprintf(obj_desc, "Display Meter %d Right dB", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
	}
	
	/* 1048 - 1053: Encoder rotation */
	for (cnt=0; cnt<6; cnt++) 
	{
		sprintf(obj_desc, "Encoder %d", cnt+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_SINT, 1, 1, -128, 127, 0, MBN_DATATYPE_NODATA);
	}
	
	/* 1054 - 1059: Encoder switch */
	for (cnt=0; cnt<6; cnt++) 
	{
		sprintf(obj_desc, "Encoder %d Switch", cnt+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_NODATA);
	}
	
	
	
	/* 1060 - 1083: Module switches (TB, INP B, CUE/PFL, START/STOP) */
	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
	{
		for (cnt=0; cnt<6; cnt++) 
		{
			sprintf(obj_desc, "Switch %d.%d", cnt+1, cntSwitch+1);
			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
		}	
	}
	
	/* 1084 - 1089: Fader (also actuator[A] to store actual value set by other node) */
	for (cnt=0; cnt<6; cnt++) 
	{
		sprintf(obj_desc, "Fader %d", cnt+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 1, 2, 0, 1023, 0, MBN_DATATYPE_UINT, 2, 0, 1023, 0, 0);
	}
	
	/* 1090 - 1113: Module switches ON color */
	for (cntSwitch=0; cntSwitch<4; cntSwitch++) 
	{
		for (cnt=0; cnt<6; cnt++) 
		{
			sprintf(obj_desc, "Switch %d.%d on color", cnt+1, cntSwitch+1);
			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 2, 2);
		}
	}
	
	/* 1114 - 1137: Module switches OFF color */
	for (cntSwitch=0; cntSwitch<4; cntSwitch++) 
	{ /*cntSwitch == switchID */
		for (cnt=0; cnt<6; cnt++)  /* cnt == module */
		{
			sprintf(obj_desc, "Switch %d.%d off color", cnt+1, cntSwitch+1);
			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 0, 0);
		}
	}
	
	/* 1138 - 1143: PGM on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) 
	{
		sprintf(obj_desc, "PGM %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	/* 1144 - 1149: SUB on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "SUB %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1150 - 1155: EQ on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "EQ %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1156 - 1161: DYN on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Dynamics %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1162 - 1167: AUX1 on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Aux1 %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1168 - 1173: AUX2 on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Aux2 %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1174 - 1179: AUX3 on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Aux3 %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1180 - 1185: AUX4 on/off */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Aux4 %d on/off", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	
	/* 1186 - 1191: Peak Indicator (ppm) */
	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
		sprintf(obj_desc, "Peak %d", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}  

	/* 1192 - 1240: CRM Switches */
	for (cntSwitch=0; cntSwitch<49; cntSwitch++) 
	{
		sprintf(obj_desc, "Switch %d", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
	}
	/* 1241 - 1289: CRM switches ON color */
	for (cntSwitch=0; cntSwitch<49; cntSwitch++) 
	{
		sprintf(obj_desc, "Switch %d on color", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 2, 2);
	}
	/* 1290 - 1338: CRM switches OFF color */
	for (cntSwitch=0; cntSwitch<49; cntSwitch++) 
	{
		sprintf(obj_desc, "Switch %d off color", cntSwitch+1); 
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 0, 0);
	}
	/* 1339 - 1342: Potmeters, also actuator to internally save current value set by other nodes (not in sync status) */
	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
	{
		sprintf(obj_desc, "Potential Meter %d", cntSwitch+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 1, 2, 0, 1023, 0, MBN_DATATYPE_UINT, 2, 0, 1023, 0, 0);
	}

	// -------------toegevoegde level meter voor mix en monitor bussen----------------

//	/* 1043 - 1063: Stereo Audio level metering for mix or monitor busses */
//	for (cntvu_busses=0; cntvu_busses<20; cntvu_busses++)
//	{
//		sprintf(obj_desc, "Mix or Mon Bus Meter %d Left dB", cntvu_busses+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//		sprintf(obj_desc, "Mix or Mon Bus Meter %d Right dB", cntvu_busses+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//	}

	
	
	// // //------------------------------------------------------------------------------------------------
    thisnodeB.NumberOfObjects = cntObject;


	if((mbn = mbnInit(&thisnodeB, objects, itf, error)) == NULL)
	{
		return; // memLog(LF_APP, "Init failed: %s", error);
	}

    // Callbacks
	mbnSetSensorDataChangedCallback(mbn, mSensorDataChanged);
	mbnSetSetActuatorDataCallback(mbn, mSetActuatorData);
    //mbnSetErrorCallback(mbn, mError);
    mbnSetOnlineStatusCallback(mbn, mOnlineStatus);


	mbnStartInterface(itf, error);

    lstInterfaces->Enabled = false;
    UDPEdit->Enabled = false;
    //TCPEdit->Enabled = false;
    //cseUniqueID->Enabled = false;
    btnOpen->Enabled = false;
    //btnClose->Enabled = true;

    mbnSendPingRequest(mbn, MBN_BROADCAST_ADDRESS);



}
//------------------------- Not used --------------------------------------------------
int CorrTabel(double tst)
{
	double rtst = 0, corrected=1, corrected2=1;

		 if ( (tst / corrected) > 147 ) rtst = corrected2 * 40;
	else if ( (tst / corrected) > 146 ) rtst = corrected2 * 39;
	else if ( (tst / corrected) > 145 ) rtst = corrected2 * 38;
	else if ( (tst / corrected) > 144 ) rtst = corrected2 * 36;
	else if ( (tst / corrected) > 143 ) rtst = corrected2 * 34;
	else if ( (tst / corrected) > 142 ) rtst = corrected2 * 33;
	else if ( (tst / corrected) > 141 ) rtst = corrected2 * 32;   //7
	else if ( (tst / corrected) > 140 ) rtst = corrected2 * 31;
	else if ( (tst / corrected) > 139 ) rtst = corrected2 * 30;
	else if ( (tst / corrected) > 138 ) rtst = corrected2 * 29;
	else if ( (tst / corrected) > 137 ) rtst = corrected2 * 28;
	else if ( (tst / corrected) > 136 ) rtst = corrected2 * 27;   //6
	else if ( (tst / corrected) > 136 ) rtst = corrected2 * 26;
	else if ( (tst / corrected) > 135 ) rtst = corrected2 * 25;
	else if ( (tst / corrected) > 134 ) rtst = corrected2 * 24;
	else if ( (tst / corrected) > 133 ) rtst = corrected2 * 23;   //4
	else if ( (tst / corrected) > 132 ) rtst = corrected2 * 22;
	else if ( (tst / corrected) > 131 ) rtst = corrected2 * 21;
	else if ( (tst / corrected) > 130 ) rtst = corrected2 * 19;
	else if ( (tst / corrected) > 129 ) rtst = corrected2 * 18;   //5
	else if ( (tst / corrected) > 127 ) rtst = corrected2 * 16;
	else if ( (tst / corrected) > 125 ) rtst = corrected2 * 14;   //5
	else if ( (tst / corrected) > 123 ) rtst = corrected2 * 13;
	else if ( (tst / corrected) > 121 ) rtst = corrected2 * 12;
	else if ( (tst / corrected) > 120 ) rtst = corrected2 * 11;
	else if ( (tst / corrected) > 119 ) rtst = corrected2 * 10;   //4
	else if ( (tst / corrected) > 117 ) rtst = corrected2 * 9;
	else if ( (tst / corrected) > 116 ) rtst = corrected2 * 8;
	else if ( (tst / corrected) > 114 ) rtst = corrected2 * 7;
	else if ( (tst / corrected) > 111 ) rtst = corrected2 * 6;
	else if ( (tst / corrected) > 103 ) rtst = corrected2 * 5;
	else if ( (tst / corrected) > 92  ) rtst = corrected2 * 4;
	else if ( (tst / corrected) > 76  ) rtst = corrected2 * 3;
	else if ( (tst / corrected) > 57  ) rtst = corrected2 * 2;
	else if ( (tst / corrected) >= 35 ) rtst = corrected2 * 1;
	else if ( (tst / corrected) < 17  ) rtst = corrected2 * 0;

	return (int)rtst;
}

int oldOnline, started;
static int oldtst, oldtstR, oldtst2, oldtstR2, newtst;

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
			//RefreshTimer->Enabled = false;

			if (oldtst > 0)         oldtst = oldtst - 3;
			if (oldtst < 0)         oldtst = vuValueL;
			if (oldtst < vuValueL)  oldtst = vuValueL;


		   if (oldtstR > 0)         oldtstR = oldtstR - 3;
		   if (oldtstR < 0)         oldtstR = vuValueR;
		   if (oldtstR < vuValueR)  oldtstR = vuValueR;

		   //oldtst = CorrTabel( oldtst );

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
//
		   ProgressBar5->Position = vuValueL4;
		   ProgressBar6->Position = vuValueR4;
//
		   ProgressBar7->Position = vuValueL5;
		   ProgressBar8->Position = vuValueR5;
//
		   ProgressBar9->Position = vuValueL6;
		   ProgressBar10->Position = vuValueR6;
//
//		   ProgressBar11->Position = oldtst;
//		   ProgressBar12->Position = oldtstR;
//
//		   ProgressBar13->Position = oldtst;
//		   ProgressBar14->Position = oldtstR;
//
		   ProgressBar15->Position = vuValueL3;
		   ProgressBar16->Position = vuValueR3;

//			char Temp[32];
//			sprintf(Temp, "#%04d_%04d\n\r #%04d_%04d", 1088, vuValueL, 1089, vuValueR);
//			memLog->Lines->Add(Temp);




//			if (checkBox1 == 1 )
//			{
//				char Temp[32];
//				sprintf(Temp, "#%04d_%04d #%04d_%04d", 1088, (int)vuValueL, 1089, (int)vuValueR);
//				memLog->Lines->Add(Temp);
//			}



		}



		double tst=1;
}









//---------------------------------------------------------------------------



void __fastcall TWillemForm1::Button1Click(TObject *Sender)
{
	count = count1 = count2 = toestand = 0;
	TimerStartDelay->Enabled = true;
//	static int toggle;
//
//	if( toggle )
//		WillemForm1->RefreshTimer->Enabled = false;
//	else
//		WillemForm1->RefreshTimer->Enabled = true;
//	toggle = !toggle;
}
//---------------------------------------------------------------------------



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







//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label25Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1230, d);    // Prog mon1 crm
}
//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label40Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1232, d);    // sub mon1 crm
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label42Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1234, d);    // aux mon1 crm
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label29Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1236, d);    // pfl mon1 crm
}
//---------------------------------------------------------------------------










//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label23Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1231, d);    // Prog mon2 studio
}
//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label43Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1233, d);    // sub mon2 studio
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label44Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1235, d);    // aux mon2 studio
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label24Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1237, d);    // pfl mon2 studio
}
//---------------------------------------------------------------------------








//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label7Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1072, d);    // PFL
}
//---------------------------------------------------------------------------
void __fastcall TWillemForm1::Label21Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1194, d);    // dump
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label20Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1193, d);    // sub
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label6Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1192, d);    // prog
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::SourceLabelClick(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1195, d);   // Source
}

//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label45Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 1;
	mbnUpdateSensorData(mbn, 1197, d);   // Source
}

//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Label41Click(TObject *Sender)
{
	union mbn_data d;
	d.SInt = 0;
	mbnUpdateSensorData(mbn, 1073, d);   // Source
}

//---------------------------------------------------------------------------




void __fastcall TWillemForm1::Button7Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = 1;
	 mbnUpdateSensorData(mbn, 1054, d);    //<---------------------- Contact encoder switch
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button5Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = 1;
	 mbnUpdateSensorData(mbn, 1048, d);    //<---------------------- Contact encoder plus
	 d.SInt = 0;
	 mbnUpdateSensorData(mbn, 1048, d);
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button3Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = -1;
	 mbnUpdateSensorData(mbn, 1048, d);    //<---------------------- Contact encoder min
	 d.SInt = 0;
	 mbnUpdateSensorData(mbn, 1048, d);
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button8Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = 1;
	 mbnUpdateSensorData(mbn, 1055, d);    //<---------------------- Contact encoder switch
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button6Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = 1;
	 mbnUpdateSensorData(mbn, 1049, d);    //<---------------------- Contact encoder plus
	 d.SInt = 0;
	 mbnUpdateSensorData(mbn, 1049, d);
}
//---------------------------------------------------------------------------

void __fastcall TWillemForm1::Button4Click(TObject *Sender)
{
	 union mbn_data d;
	 d.SInt = -1;
	 mbnUpdateSensorData(mbn, 1049, d);    //<---------------------- Contact encoder min
	 d.SInt = 0;
	 mbnUpdateSensorData(mbn, 1049, d);
}
//---------------------------------------------------------------------------


void __fastcall TWillemForm1::TrackBar1Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar1->Position;
	value = 1023 - value;
	d.UInt = value;

	mbnUpdateSensorData(mbn, 1084, d);         // Fader module 1
}

//---------------------------------------------------------------------------

void __fastcall TWillemForm1::TrackBar2Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar2->Position;
	value = 0;
	d.UInt = value;

	mbnUpdateSensorData(mbn, 1085, d);     // Fader module 2
}

//---------------------------------------------------------------------------








void __fastcall TWillemForm1::Button2Click(TObject *Sender)
{
	// Execute the Notepad application
	system("notepad.exe settings.txt");

	//ShellExecute(0, 0, L"notepad.exe | ip.txt", 0, 0, SW_SHOW);
}


//---------------------------------------------------------------------------


//int count;

//void sendToTrackBar(unsigned int fdrObject, unsigned int putInt)
//{
//	union mbn_data d;
//	unsigned int valueT = 1023 - putInt;
//	d.UInt = valueT;
//	mbnUpdateSensorData(WillemForm1->mbn, fdrObject, d);         // Fader module 1
//	WillemForm1->memLog->Lines->Add(putInt);
//}


void __fastcall TWillemForm1::TimerStartDelayTimer(TObject *Sender)
{

	if ( toestand == 0 )
	{
		TrackBar1->Position = count1;

		//sendToTrackBar(1084, count1);

		count1 = count1 + 40;

		if ( count1 > faderPosition )
		{
			toestand++;
			count1=faderPosition;
		}
	}

	else if ( toestand == 1 )
	{
		TrackBar1->Position = count1;

		//sendToTrackBar(1084, count1);

		count1 = count1 - 40;

		if ( count1 < 80 )
		{
			toestand++;
			count1=0;
		}
	}

   //--------------------------------------------------------------------------------
	else if ( toestand == 2 )
	{
		TrackBar3->Position = count1;

		//sendToTrackBar(1339, count1);

		count1 = count1 + 40;

		if ( count1 > trackBar3Position )
		{
			toestand++;
			count1=0;
		}
	}

	//---------------------------
	else if ( toestand == 3 )
	{
		TrackBar4->Position = count1;

		//sendToTrackBar(1340, count1);

		count1 = count1 + 40;

		if ( count1 > trackBar3Position )
		{
			toestand++;
			count1=0;
		}
	}

   //---------------------------------------------------------------
	else if ( toestand == 4 )
	{
		TrackBar5->Position = count1;

		//sendToTrackBar(1341, count1);

		count1 = count1 + 40;

		if ( count1 > trackBar3Position )
		{
			toestand++;
			count1=0;
		}
	}

	//---------------------------
	else if ( toestand == 5 )
	{
		TrackBar6->Position = count1;

		//sendToTrackBar(1341, count1);

		count1 = count1 + 40;

		if ( count1 > trackBar3Position )
		{
			toestand++;
			count1=0;
		}
	}


//-----------------------------------------------------------------------------------------------------------
	if ( toestand == 6 )
	{
		TrackBar2->Position = -1000;
	}



	count+=20;

	if ( count > 6022)
	{
		TimerStartDelay->Enabled = false;
		memLog->Lines->Add("TimerStartDelay = false");
		//memLog->Lines->Add(count2);
	}
}








//---------------------------------------------------------------------------


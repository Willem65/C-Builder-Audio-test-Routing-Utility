﻿
#include "SetActuatorData.h"


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




  //---------------------------------------------------------------------------
//----------------------------- GPO SIGNALES------------------------------------
//---------------------------------------------------------------------------




	else if (obj == 1214)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label26->Color = clRed;
		else
		  WillemForm1->Label26->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1215)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label59->Color = clRed;
		else
		  WillemForm1->Label59->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1216)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label62->Color = clRed;
		else
		  WillemForm1->Label62->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1217)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label63->Color = clRed;
		else
		  WillemForm1->Label63->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------


	else if (obj == 1218)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label64->Color = clRed;
		else
		  WillemForm1->Label64->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------


	else if (obj == 1219)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label65->Color = clRed;
		else
		  WillemForm1->Label65->Color = clInactiveCaption;
	}

//---------------------------------------------------------------------------


	else if (obj == 1220)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label66->Color = clRed;
		else
		  WillemForm1->Label66->Color = clInactiveCaption;
	}

//----------------1058-------1237----------------------------------------------------


	else if (obj == 1221)
	{
		int t=dat.SInt;

		if( t == 1 )
		  WillemForm1->Label67->Color = clRed;
		else
		  WillemForm1->Label67->Color = clInactiveCaption;
	}

//---------------------------------------------------------------------------





// ---------------------------- Oled Log Data to memLog2 -------------------------------------------
//
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


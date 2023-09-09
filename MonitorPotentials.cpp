
#include "WillemFormCode.h"
#include "mbn.h"
#include "MonitorPotentials.h"

//int trackBar3Position, faderPosition;
//unsigned int count, count1, count2, toestand;

void __fastcall TWillemForm1::TrackBar3Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar3->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1339, d);            // potential crm phone
}

void __fastcall TWillemForm1::TrackBar5Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar5->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1340, d);        // potential crm speakers
}

void __fastcall TWillemForm1::TrackBar4Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar4->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1341, d);        // potential studio phone
}



void __fastcall TWillemForm1::TrackBar6Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar6->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1342, d);        // potential studio speakers
}



////--------------- Hier onder staat Code om de faders en Potentials heen en weer te bewegen tijdens het opstarten van het programma----
//
//
////int count;
//
////void sendToTrackBar(unsigned int fdrObject, unsigned int putInt)
////{
////	union mbn_data d;
////	unsigned int valueT = 1023 - putInt;
////	d.UInt = valueT;
////	mbnUpdateSensorData(WillemForm1->mbn, fdrObject, d);         // Fader module 1
////	WillemForm1->memLog->Lines->Add(putInt);
////}//
//
//
//void __fastcall TWillemForm1::TimerStartDelayTimer(TObject *Sender)
//{
//
//	if ( toestand == 0 )
//	{
//		TrackBar1->Position = count1;
//
//		//sendToTrackBar(1084, count1);
//
//		count1 = count1 + 40;
//
//		if ( count1 > faderPosition )
//		{
//			toestand++;
//			count1=faderPosition;
//		}
//	}
//
//	else if ( toestand == 1 )
//	{
//		TrackBar1->Position = count1;
//
//		//sendToTrackBar(1084, count1);
//
//		count1 = count1 - 40;
//
//		if ( count1 < 80 )
//		{
//			toestand++;
//			count1=0;
//		}
//	}
//
//   //--------------------------------------------------------------------------------
//	else if ( toestand == 2 )
//	{
//		TrackBar3->Position = count1;
//
//		//sendToTrackBar(1339, count1);
//
//		count1 = count1 + 40;
//
//		if ( count1 > trackBar3Position )
//		{
//			toestand++;
//			count1=0;
//		}
//	}
//
//	//---------------------------
//	else if ( toestand == 3 )
//	{
//		TrackBar4->Position = count1;
//
//		//sendToTrackBar(1340, count1);
//
//		count1 = count1 + 40;
//
//		if ( count1 > trackBar3Position )
//		{
//			toestand++;
//			count1=0;
//		}
//	}
//
//   //---------------------------------------------------------------
//	else if ( toestand == 4 )
//	{
//		TrackBar5->Position = count1;
//
//		//sendToTrackBar(1341, count1);
//
//		count1 = count1 + 40;
//
//		if ( count1 > trackBar3Position )
//		{
//			toestand++;
//			count1=0;
//		}
//	}
//
//	//---------------------------
//	else if ( toestand == 5 )
//	{
//		TrackBar6->Position = count1;
//
//		//sendToTrackBar(1341, count1);
//
//		count1 = count1 + 40;
//
//		if ( count1 > trackBar3Position )
//		{
//			toestand++;
//			count1=0;
//		}
//	}
//
//
////-----------------------------------------------------------------------------------------------------------
//	if ( toestand == 6 )
//	{
//		TrackBar2->Position = -1000;
//	}
//
//
//
//	count+=20;
//
//	if ( count > 6022)
//	{
//		TimerStartDelay->Enabled = false;
//		memLog->Lines->Add("TimerStartDelay = false");
//		//memLog->Lines->Add(count2);
//	}
//}
//
//
//
//
//
//
//
//
////---------------------------------------------------------------------------


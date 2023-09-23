

#include "StartMoving.h"



////--------------- Hier onder staat Code om de faders en Potentials heen en weer te bewegen tijdens het opstarten van het programma----
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
////---------------------------------------------------------------------------
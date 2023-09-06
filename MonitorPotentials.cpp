
#include "WillemFormCode.h"
#include "mbn.h"


void __fastcall TWillemForm1::TrackBar3Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar3->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1339, d);            // potential crm phone
}


void __fastcall TWillemForm1::TrackBar4Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar4->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1341, d);        // potential studio phone
}
void __fastcall TWillemForm1::TrackBar5Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar5->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1340, d);        // potential crm speakers
}


void __fastcall TWillemForm1::TrackBar6Change(TObject *Sender)
{
	union mbn_data d;
	int value = WillemForm1->TrackBar6->Position;
	//value = 1023 - value;
	d.SInt = value;

	mbnUpdateSensorData(mbn, 1342, d);        // potential studio speakers
}
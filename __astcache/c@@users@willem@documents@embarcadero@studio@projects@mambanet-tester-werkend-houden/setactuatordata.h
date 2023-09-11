#ifndef SetActuatorDataH
#define SetActuatorDataH

#include "WillemFormCode.h"
#include "mbn.h"

extern float vuValueL, vuValueR, vuValueL2, vuValueR2, vuValueL3, vuValueR3, vuValueL4, vuValueR4, vuValueL5, vuValueR5, vuValueL6, vuValueR6;
extern int checkBox1;

int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat);

#endif

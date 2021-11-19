#ifndef SUN_POSITION_H
#define SUN_POSITION_H

#include <Arduino.h>
#include <RTClib.h>

struct DT {
    int yy;
    int mm;
    int dd;
    int h;
    int m;
};

float days_passed(DT t);
float localTime(DT t);
int LSTM (int offset);
float EOT (DT t);
float TC(int offset, DT t, float longitude);
float LST(int offset, DT t, float longitude);
float HRA(int offset, DT t, float longitude);
float DA(DT t);
float EA(DT t, float offset, float latitude, float longitude);
float AA(DT t, float offset, float latitude, float longitude);

#endif

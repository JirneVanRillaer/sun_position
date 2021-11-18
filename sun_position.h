#ifndef SUN_POSITION_H
#define SUN_POSITION_H

#include <Arduino.h>
#include <RTClib.h>

float days_passed(DateTime t);
float localTime(DateTime t);
int LSTM (int offset);
float EOT (DateTime t);
float TC(int offset, DateTime t, float longitude);
float LST(int offset, DateTime t, float longitude);
float HRA(int offset, DateTime t, float longitude);
float DA(DateTime t);
float EA(DateTime t, float latitude);
float AA(DateTime t, float offset, float latitude, float longitude);

#endif
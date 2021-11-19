/* created by Jirne Van Rillaer */

#include "sun_position.h";

// total of days passed since the start of the year
float days_passed(DateTime t) {
  int daysInMonth[12] = {31, (t.year() % 4 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //if (t.year() % 4 == 0) daysInMonth[1] = 29; // schrikkeljaar
  float DP = 0;
  for (int i = 0; i < t.month() - 1; i++) DP += daysInMonth[i];  
  DP += t.day();
  DP += t.hour() / 24;
  DP += t.minute() / (24 * 60);
  return DP;
}

// convert DateTime to LT
float localTime(DateTime t) {
  return (float)(t.hour() * 60 + t.minute());
}

// local solar time meridian
int LSTM (int offset) {
  return 15 * offset;
}

// equation of time
float EOT(DateTime t) {
  float d = days_passed(t);
  float B = (360.0 / 365.0) * (d - 81.0);
  B = radians(B);
  return 9.87 * sin(2.0 * B) - (7.53 * cos(B)) - (1.5 * sin(B));
}

// time correction
float TC(int offset, DateTime t, float longitude) {
  return 4 * (longitude - (float)LSTM(offset)) + EOT(t);
}

// local solar time
float LST(int offset, DateTime t, float longitude) {
  return localTime(t) + (TC(offset, t, longitude) / 60);
}

// hour angle
float HRA(int offset, DateTime t, float longitude) {
  return 15 + (LST(offset, t, longitude) - 12);
}

// declination angle
float DA(DateTime t) {
  float d = days_passed(t);
  return 23.45 * sin(radians((360/365) * (d - 81)));
}


// ==================================================================

// elevation angle
float EA(DateTime t, float offset, float latitude, float longitude) {
  return degrees(asin(sin(radians(DA(t))) * sin(radians(latitude)) + cos(radians(DA(t))) * cos(radians(latitude)) * cos(radians(HRA(offset, t, longitude)))));
}

// azimuth angle
float AA(DateTime t, float offset, float latitude, float longitude) {
  float azan = degrees(acos((sin(radians(DA(t))) * cos(radians(latitude)) - cos(radians(DA(t))) * sin(radians(latitude)) * cos(radians(HRA(offset, t, longitude)))) / cos(radians(EA(t, offset, latitude, longitude)))));
  return (LST(offset, t, longitude) < 0 || HRA(offset, t, longitude) < 0) ? azan : (360 - azan);
}

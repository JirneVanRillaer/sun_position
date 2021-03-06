/* created by Jirne Van Rillaer */

#include "sun_position.h";

// total of days passed since the start of the year
float days_passed(DT t) {
  float daysInMonth[12] = {31.0, (t.yy % 4 == 0) ? 29.0 : 28.0, 31.0, 30.0, 31.0, 30.0, 31.0, 31.0, 30.0, 31.0, 30.0, 31.0}; //if (t.yy % 4 == 0) daysInMonth[1] = 29; // leap year
  float DP = 0;
  for (int i = 0; i < t.mm - 1; i++) DP += daysInMonth[i];  
  DP += (float)t.dd;
  DP += (float)t.h / 24.0;
  DP += (float)t.m / (24.0 * 60.0);
  return DP;
}

// convert DateTime to LT
float localTime(DT t) {
  return (float)t.h * 60.0 + (float)t.m;
}

// local solar time meridian
float LSTM (int offset) {
  return 15.0 * (float)offset;
}

// equation of time
float EOT(DT t) {
  float d = days_passed(t);
  float B = (360.0 / 365.0) * (d - 81.0);
  B = radians(B);
  return 9.87 * sin(2.0 * B) - (7.53 * cos(B)) - (1.5 * sin(B));
}

// time correction
float TC(int offset, DT t, float longitude) {
  return 4.0 * (longitude - (float)LSTM(offset)) + EOT(t);
}

// local solar time
float LST(int offset, DT t, float longitude) {
  return localTime(t) + (TC(offset, t, longitude) / 60.0);
}

// hour angle
float HRA(int offset, DT t, float longitude) {
  return 15.0 * ((LST(offset, t, longitude) / 60.0) - 12.0);
}

// declination angle
float DA(DT t) {
  float d = days_passed(t);
  return 23.45 * sin(radians((360.0/365.0) * (d - 81.0)));
}





// elevation angle
float EA(DT t, float offset, float latitude, float longitude) {
  return degrees(asin(sin(radians(DA(t))) * sin(radians(latitude)) + cos(radians(DA(t))) * cos(radians(latitude)) * cos(radians(HRA(offset, t, longitude)))));
}

// azimuth angle
float AA(DT t, float offset, float latitude, float longitude) {
  float azan = degrees(acos((sin(radians(DA(t))) * cos(radians(latitude)) - cos(radians(DA(t))) * sin(radians(latitude)) * cos(radians(HRA(offset, t, longitude)))) / cos(radians(EA(t, offset, latitude, longitude)))));
  return (LST(offset, t, longitude) < 12 || HRA(offset, t, longitude) < 0) ? azan : (360 - azan);
}

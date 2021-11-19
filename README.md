# sun_position
calculate the elevation and azimuth angle of the sun based on a coördinate, a the local date &amp; time and the UTC offset

## Requirements
None

## Documentation
Parameters: 
* DT t: the local date and time with DST correction
* int offset: UTC offset
* float longitude: longitude of the location (in degrees)
* float latitude: latitude of the location (in degrees)

### struct DT(int yy, int mm, int dd, int h, int m)
create an object of the date and time  
Ex usage: `DT now = {t.year(), t.month(), t.day(), t.hour(), t.minute()};`

### float days_passed(DT t)
returns the amount of days passed since the start of the year

### float localTime(DT t)
converts the DateTime to the amount of minutes passed since the start of the day

### int LSTM(int offset)
returns the local standard time meridian in degrees

### float EOT(DT t)
returns the equation of time in minutes

### float TC(int offset, DT t, float longitude)
returns the actual time correction based on LSTM en EOT and the location in minutes

### float LST(int offset, DT t, float longitude)
returns the local solar time in minutes

### float HRA(int offset, DT t, float longitude)
returns the hour angle in degrees

### float DA(DT t)
returns the declination angle in degrees

<br/>

### float EA(DT t, float offset, float latitude, float longitude)
returns the elevation angle in degrees

### float AA(DT t, float offset, float latitude, float longitude)
returns the azimuth angle in degrees

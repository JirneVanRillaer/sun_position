# sun_position
calculate the elevation and azimuth angle of the sun based on a coördinate, a the local date &amp; time and the UTC offset

## Requirements
RTCLib - DateTime class: you can install it in the Library Manager in your IDE or [here](https://github.com/adafruit/RTClib)

## Documentation
Parameters: 
* DateTime t: the local date and time with DST correction
* int offset: UTC offset
* float longitude: longitude of the location
* float latitude: latitude of the location

### float days_passed(DateTime t)
returns the amount of days passed since the start of the year

### float localTime(DateTime t)
converts the DateTime to the amount of minutes passed since the start of the day

### int LSTM(int offset)
returns the local standard time meridian in degrees

### float EOT(DateTime t)
returns the equation of time in minutes

### float TC(int offset, DateTime t, float longitude)
returns the actual time correction based on LSTM en EOT and the location in minutes

### float LST(int offset, DateTime t, float longitude)
returns the local solar time in minutes

### float HRA(int offset, DateTime t, float longitude)
returns the hour angle in degrees

### float DA(DateTime t)
returns the declination angle in degrees

<br/>

### float EA(DateTime t, float latitude)
returns the elevation angle in degrees

### float AA(DateTime t, float offset, float latitude, float longitude)
returns the azimuth angle in degrees

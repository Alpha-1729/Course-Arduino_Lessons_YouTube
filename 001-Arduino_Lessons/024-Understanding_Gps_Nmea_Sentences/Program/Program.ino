// Understanding Gps Nmea Sentences

/*

>>>> For plotting path in the google earth we need the KML file of the latitude and longitude. (Conditions for KMl file is below.)
        Seconds in the latitude or longitude should be converted to degrees.
            Eg: 30 51.8007  -> 30 + (51.8007/60) -> 30.86335 degrees
        For latitude (N or S).
            If you have N -> Make latitude positive.
            If you have S -> Make latitude negative.
        For longitude (E or W).
            If you have E -> Make longitude positive.
            If you have W -> Make longitude negative.
        Longitude should be first and latitude should be second.
>>>> There are different types of NMEA sentences.
        We are concerned about two types of NMEA sentences:
        They are $GPGGA and $GPRMC sentences.
>>>> Reading RMS sentences.
        1st: 174530.000
                17 hr 45 minute 30 second
                UTC time
                Universal Coordinated Time
        2nd: A or V
                Active or Void
                Indicate that GPS is active or not.
        3rd: 3052.8007
                Latitude
                30 degree and 52.8007 minutes
                Degree can be 2 or 3 digit.
        4th: N or S
                North or Southern hemisphere
        5th: 10052.4233:
                Longitude
                100 degree 52.4233 minutes
        6th: E/W
                East or Western hemisphere
        7th: 1.49
                Is the speed of the gps moving (in knots).
        8th: Track Angle
                Not necessary value
                Search google for more details.
        9th: Date
                DD/MM/YY
>>>> Reading GGA sentence:
        All other first details are same as RMC.
        6th: Fix
            1 or 0
            Fix means you are in sync with satellite
    7th: 4
            The no of satellite locked with GPS
    8th:
            Horizontal dilution of postion
    9th:
            The height from the mean sea level
    10th: M
            The unit of height from the mean sea level.
*/

void setup()
{
}

void loop()
{
}

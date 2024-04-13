// Advanced Software Techniques For Reading Serial Data

/*
>>>> download the advanced timerone library from github:
    link: https://github.com/PaulStoffregen/TimerOne
>>>>
>>>>
>>>>
>>>>
>>>>
*/

#include <TimerOne.h>
#include <SoftwareSerial.h>

bool flag = false;
int redLedPin = 9;
char c;
long tmr;
String NMEA = "";
String UPDATE_10_sec = "$PMTK220,10000*2F\r\n";                              // Report data every 10 sec
String GPRMC_ONLY = "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"; // Sent only rmc nmea sentences.
SoftwareSerial GPSSerial(2, 3);                                              // New RX TX in arduino.

void setup()
{
    Serial.begin(115200);
    pinMode(redLedPin, OUTPUT);
    GPSSerial.begin(9600);
    delay(100);
    GPSSerial.print(GPRMC_ONLY); // Command to GPS Module.
    delay(100);
    GPSSerial.print(UPDATE_10_sec); // Command to GPS Module.
    Timer.initialize(1000);         // 1 millisecond
    Timer.attachInterrupt(readGPS);
}

void loop()
{

    digitalWrite(redLedPin, HIGH);
    delay(1000);
    digitalWrite(redLedPin, LOW);
    delay(1000);

    if (flag == true)
    {

        Timer1.stop();
        NMEA.trim();
        Serial.println(NMEA);
        NMEA = "";
        flag = false;
        Timer1.restart();
    }
}

void readGPS()
{
    if (GPSSerial.available() > 0)
    {
        c = GPSSerial.read();
        NMEA.concat(c);
    }
    if (c == '\r')
    {
        flag = true;
    }
}

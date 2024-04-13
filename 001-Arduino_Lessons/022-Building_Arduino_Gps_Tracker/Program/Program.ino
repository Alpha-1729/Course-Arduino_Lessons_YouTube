// Building Arduino Gps Tracker

/*
>>>> Gps Tracker
        Use Adafruit Ultimate GPS Module.
        This module can work on altitude above 60k feet.
        The product link is on toptechboy.com website.

>>>> Installing GPS library.
        Download adafruit gps library from the toptechboy.com website.
        Method 1:
            Unzip the zip file.
            Rename the folder if required.
            Move the folder to the arduino libraries folder.
            Library folder can be accessed from Arduino IDE.
                File -> Preferences -> Sketchbook location.
        Method 2:
            Open arduino IDE
            Sketch -> Include library -> Add .ZIP library.

>>>> How to view the data from the GPS module.
        Wire up the GPS module to arduino.
        Upload a blank arduino script to the Arduino.
        Open the serial monitor and set baud rate to 9600.
        Then you can see the NMEA sentence from the GPS module.
        It contains all the information about the location.

        There are many data shown in the  serial monitor like GPRMC, GPGGA... (We can set this in the GPS module, which one to show.)

>>>> Software Serial library allows you to choose other pins as RX and TX pin.
>>>> When we have a lot of delay in code, We may not get the NMEA1 and NMEA2 in proper order.
        Also on the we may get proper data from the GPS due to the delay(1000) in the void setup() block.
        To tackle this problem, we introduced the clearGPS function to avoid the invalid data.
>>>> NMEA (National Marine Electronics Association)
*/

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // New RX TX in arduino.
Adafruit_GPS GPS(&mySerial);   // GPS module is connected though the new serial port.
String NMEA1;                  // For reading the first NMEA sentence.
String NMEA2;                  // For reading the second NMEA sentence.

void setup()
{
    Serial.begin(115200);
    GPS.begin(9600);

    GPS.sentCommand("$PGCMD,33,0*6D");            // Turn off antenna update message (GPS module update the status of the antenna connected GPS module.)
    GPS.sentCommand(PMTK_SET_NMEA_UPDATE_10HZ);   // Set update rate to 10hz.
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // Tell GPS we want only $GPRMC and $GPGGA NMEA sentences.
    delay(1000);
}

void loop()
{
    readGPS(); // This function reads the two NMEA sentences from the GPS module.
    delay(2000);
}
void readGPS()
{
    clearGPS(); // Serial port probably has old or corrupt data, so begin by clearing it all out

    //  Loop until you get a good NMEA sentence.
    while (!GPS.newNMEAreceived())
    {
    }
    GPS.parse(GPS.lastNMEA()); // This parses that NMEA sentence, allowing you to access GPS data like longitude and latitude. (GPS.latitude, GPS.longitude)
    NMEA1 = GPS.lastNMEA();

    //  Loop until you get a good NMEA sentence.
    while (!GPS.newNMEAreceived())
    {
    }
    GPS.parse(GPS.lastNMEA());
    NMEA2 = GPS.lastNMEA();

    Serial.println(NMEA1);
    Serial.println(NMEA2);
    Serial.println();
}
void clearGPS()
{
    // Since between GPS reads, we still have data streaming in, we need to clear the old data by reading a few sentences, and discarding these.
    for (int i = 0; i < 4; i++)
    {
        while (!GPS.newNMEAreceived())
        {
        }
        GPS.parse(GPS.lastNMEA());
    }
}
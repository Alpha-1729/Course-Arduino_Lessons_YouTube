// Displaying Gps Nmea Sentence In Google Earth

/*
>>>> This code will help to store longitude, latitude, altitude in sdcard delimited with spaces..
>>>> How to view the coordinates in Google Earth.
        There is a wrapper available in toptechboy.com website. (Attached in the current directory)
        Copy all data in the sdcard between the coordinate tag of the wrapper and save it with .kml extension.
        Open the file.kml with google earth, then you can see your path with altitude in 3d view.
>>>>
>>>>
>>>>
>>>>
*/

#include <SD.h>
#include <SPI.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // New RX TX in arduino.
Adafruit_GPS GPS(&mySerial);   // GPS module is connected though the new serial port.
String NMEA1;                  // For reading the first NMEA sentence
String NMEA2;                  // For reading the second NMEA sentence.

float degFull;        // Variable for storing the position value in degrees.
float degWholePart;   // Variable to store the whole number part of the degree.
float degDecimalPart; // Variable for decimal part of the degree.

int chipSelect = 4;
File mySensorData;

void setup()
{
    Serial.begin(115200);
    GPS.begin(9600);
    GPS.sentCommand("$PGCMD,33,0*6D");            // Turn off antenna update message (GPS module update the status of the antenna connected GPS module.)
    GPS.sentCommand(PMTK_SET_NMEA_UPDATE_10HZ);   // Set update rate to 10hz.
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // Tell GPS we want only $GPRMC and $GPGGA NMEA sentences.
    pinMode(10, OUTPUT);                          // Reserve pin 10 for SD card reader.
    SD.begin(chipSelect);

    // Remove old txt files
    if (SD.exists("NMEA.txt"))
    {
        SD.remove("NMEA.txt");
        if (SD.exists("GPSData.txt"))
    }
    {
        SD.remove("GPSData.txt");
    }
}

void loop()
{
    readGPS(); // This function reads the two NMEA sentences from the GPS module.

    // Write data to SD card, if we have valid data.
    // If there is no valid data GPS.fix will be 0.
    if (GPS.fix == 1)
    {
        // For storing the complete NMEA sentences.
        mySensorData = SD.open("NMEA.txt", FILE_WRITE);
        mySensorData.println(NMEA1);
        mySensorData.println(NMEA2);
        mySensorData.close();

        // For storing the latitude, longitude and altitude.
        mySensorData = SD.open("GPSData.txt", FILE_WRITE);

        // Writing longitude.
        degWholePart = float(int(GPS.longitude / 100));
        degDecimalPart = (GPS.longitude - degWholePart * 100) / 60;
        degFull = degWholePart + degDecimalPart;

        if (GPS.long == 'W') // If you are in Western hemisphere, latitude degrees should be negative.
        {
            degFull = (-1) * degFull;
        }
        mySensorData.print(degFull, 4); // Write longitude with 4 values after the decimal point.
        mySensorData.print(",");

        // Writing the latitude.
        degWholePart = float(int(GPS.latitude / 100));
        degDecimalPart = (GPS.latitude - degWholePart * 100) / 60;
        degFull = degWholePart + degDecimalPart;

        if (GPS.lat == 'S') // If you are in Southern hemisphere, latitude degrees should be negative.
        {
            degFull = (-1) * degFull;
        }
        mySensorData.print(degFull, 4); // Write latitude with 4 values after the decimal point.
        mySensorData.print(",");

        // Writing the altitude.
        mySensorData.print(GPS.altitude);
        mySensorData.print(" "); // Space

        mySensorData.close();
    }
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
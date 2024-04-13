// Arduino Gps With Data Logger

/*
>>>> To see the location in the google earth.
        Copy the latitude and longitude from the GPSData.txt file and search in the google earth.
        Format to check in the google earth.
            30 51.801N,100 36.0253W (This will be read as 30 degrees and 51.801 seconds)
>>>>
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
        mySensorData.print(GPS.latitude, 4); // Read latitude and take the 4 decimal place after the decimal place.
        mySensorData.print(GPS.lat);         // Which hemisphere N or S
        mySensorData.print(",");
        mySensorData.print(GPS.longitude, 4); // Read longitude and take the 4 decimal place after the decimal place.
        mySensorData.print(GPS.lon);          // Which Hemisphere E or W
        mySensorData.print(",");
        mySensorData.println(GPS.altitude);
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
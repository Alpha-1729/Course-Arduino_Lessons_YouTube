// Data Logging From Arduino To Sdcard

/*
>>>> After running the script in arduino, plug out the sd card and open the file in excel and plot the data using the inbuilt scattered chart in the excel.
        Click the Insert tab, and then click Insert Scatter (X, Y) or Bubble Chart.
>>>> SdCard Reader
        Buy Virtuabotix SD Card Reader.
>>>> Pressure Sensor
        Use BMP 180 sensor.
>>>> SPI (Serial Peripheral Interface)
>>>> MOSI and MISO are the protocol/technique by which components can talk each other
        micro controller talks to another micro controller.
        OR
        micro controller talks to advanced components.
>>>>
>>>>
*/

#include <SD.h> // SD Card Library.
#include <SPI.h>

#include "Wire.h"            // Wire library for talking over I2C.
#include "Adafruit_BMP085.h" // Pressure Sensor Library - Version1.
Adafruit_BMP085 mySensor;    // Create sensor object.

float tempInCelsius;    // Variable for holding temp in C.
float tempInFahrenheit; // Variable for holding temp in F.
float pressure;         // Variable for holding pressure reading.

int chipSelect = 4;
File mySensorData; // Variable for working with file object.

void setup()
{
        Serial.begin(9600);
        mySensor.begin(); // Initialize the sensor.

        // Leave pin 10 free in arduino for sdcard to work.
        pinMode(10, OUTPUT);  // Reserve pin 10 as an output.
        SD.begin(chipSelect); // Initialize the sd card.
}

void loop()
{
        tempInCelsius = mySensor.readTemperature();   //  Read Temperature
        tempInFahrenheit = tempInCelsius * 1.8 + 32.; // Convert degrees C to F
        pressure = mySensor.readPressure();           // Read Pressure

        // Always use a short file name.
        mySensorData = SD.open("data.txt", FILE_WRITE);

        // If file is not there new file will be created.
        // If file is opened mySensorData will have True value.
        if (mySensorData)
        {
                // Show the data in the serial monitor.
                Serial.print("The Temp is: ");
                Serial.print(tempInFahrenheit);
                Serial.println(" degrees F");
                Serial.print("The Pressure is: ");
                Serial.print(pressure);
                Serial.println(" Pa.");
                Serial.println("");
                delay(250);

                // Save file like a CSV file.
                mySensorData.print(tempInFahrenheit);
                mySensorData.print(",");
                mySensorData.println(pressure);
                mySensorData.close();
        }
}
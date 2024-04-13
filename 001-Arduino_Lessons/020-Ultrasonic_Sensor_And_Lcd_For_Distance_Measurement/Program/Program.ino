// Ultrasonic Sensor And Lcd For Distance Measurement

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

#include <LiquidCrystal.h>

// Creating a LCD Object.
LiquidCrystal LCD(10, 9, 5, 4, 3, 2); // RS, E, DB4, DB5, DB6, DB7

int trigPin = 13;
int echoPin = 11;
float pingTime;
float targetDistance;
float speedOfSound = 776.5; // Miles per hour.

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    LCD.begin(16, 2);
    LCD.setCursor(0, 0);
    LCD.print("Target Distance:");
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);

    pingTime = pulseIn(echoPin, HIGH);
    pingTime = pingTime / 1000000.0; // Convert microseconds to seconds.
    pingTime = pingTime / 3600.0;    // Convert seconds to hour.

    targetDistance = speedOfSound * pingTime;
    targetDistance = targetDistance / 2;
    targetDistance = targetDistance * 63360; // Convert miles to inches.

    LCD.setCursor(0, 1);
    LCD.print("                "); // Clear the screen.
    LCD.setCursor(0, 1);
    LCD.print(targetDistance);
    LCD.print(" inches");
    delay(250);
}

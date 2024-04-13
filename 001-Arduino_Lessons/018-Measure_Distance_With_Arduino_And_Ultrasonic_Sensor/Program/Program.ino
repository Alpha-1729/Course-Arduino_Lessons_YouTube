// Measure Distance With Arduino And Ultrasonic Sensor

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

#include <Servo.h>

int trigPin = 13;
int echoPin = 11;
int servoPin = 9;

float speedOfSound = 765.6; // Miles per hour.
float pingTime;
float targetDistance;

float servoAngle;
Servo myServo;

void setup()
{
    Serial.begin(9600);
    myServo.attach(servoPin);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pingTime = pulseIn(echoPin, HIGH);
    pingTime = pingTime / 1000000.0; // Convert from microseconds to seconds.
    pingTime = pingTime / 3600.0;    // Convert from seconds to hour.

    targetDistance = speedOfSound * pingTime;
    targetDistance = targetDistance / 2;
    targetDistance = targetDistance * 63360; // Convert from miles to inches.

    Serial.print("The target distance is ");
    Serial.print(targetDistance);
    Serial.println(" inches");
    delay(100);

    // Based on the calculation.
    servoAngle = (106.0 / 7.0) * targetDistance + 37;
    myServo.write(servoAngle);
}
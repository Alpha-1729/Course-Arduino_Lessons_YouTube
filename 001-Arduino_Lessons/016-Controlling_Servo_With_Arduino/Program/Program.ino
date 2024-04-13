// Controlling Servo With Arduino

/*
>>>> First fin the safe angle of rotation of the servo.
        The minimum angle and maximum angle.
        Eg: lowest angle = 15 and maximum angle = 170;
        Map the 0-1023 of potentiometer to the min and max angle of the servo.
        Then control the position of the servo with the potentiometer.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

#include <Servo.h> // Adding the servo library

int pos = 0;
int servoPin = 9;
int servoDelay = 10;
int servoMinAngle = 15;
int servoMaxAngle = 170;

int potReading;
int potPin = A0;

// Servo object.
Servo myServo;

void setup()
{
    Serial.begin(9600);
    pinMode(potPin, INPUT);
    myServo.attach(servoPin);
}

void loop()
{
    potReading = analogRead(potPin);
    pos = ((servoMaxAngle - servoMinAngle) / 1023.0) * potReading + servoMinAngle;
    myServo.write(pos);
    delay(servoDelay);
}

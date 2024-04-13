// Arduino Color Sensor And Rgb Led

/*
>>>> We are using Virtuabotix Color Sensor.
        It has 7 pins VCC, GND,OUT, S0, S1, S2, S3.
        Connection image is added in the image folder.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

// RGB pins.
int redLedPin = 9;
int blueLedPin = 10;
int greenLedPin = 11;

// Color sensor pins.
int S2 = 8;
int S3 = 7;
int outPin = 4;

unsigned int pulseWidth;
int rColorStrength, bColorStrength, gColorStrength;

void setup()
{
    Serial.begin(9600);

    pinMode(redLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(outPin, INPUT);
}

void loop()
{
    // Read Red Color.
    // S2 LOW, S3 LOW
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    pulseWidth = pulseIn(outPin, LOW);
    rColorStrength = (pulseWidth / 400.0) - 1;
    rColorStrength = (255 - rColorStrength);

    // Read Blue Color.
    // S2 LOW, S3 HIGH
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    pulseWidth = pulseIn(outPin, LOW);
    bColorStrength = (pulseWidth / 400.0) - 1;
    bColorStrength = (255 - bColorStrength);

    // Read Green Color.
    // S2 HIGH, S3 HIGH
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    pulseWidth = pulseIn(outPin, LOW);
    gColorStrength = (pulseWidth / 400.0) - 1;
    gColorStrength = (255 - gColorStrength);

    // Eliminating intensity of some color.
    bColorStrength = bColorStrength * 0.5;
    gColorStrength = gColorStrength * 0.75;

    // Some color correction.
    // Set max value in RGB to 255.
    // Set min value in RGB to 0.
    // Set middle value in RGB to half.

    if (rColorStrength > gColorStrength && gColorStrength > bColorStrength)
    {
        rColorStrength = 255;
        gColorStrength = gColorStrength / 2;
        bColorStrength = 0;
    }

    if (rColorStrength > bColorStrength && bColorStrength > gColorStrength)
    {
        rColorStrength = 255;
        bColorStrength = bColorStrength / 2;
        gColorStrength = 0;
    }

    if (bColorStrength > gColorStrength && gColorStrength > rColorStrength)
    {
        bColorStrength = 255;
        gColorStrength = gColorStrength / 2;
        rColorStrength = 0;
    }

    if (bColorStrength > rColorStrength && rColorStrength > gColorStrength)
    {
        bColorStrength = 255;
        rColorStrength = rColorStrength / 2;
        gColorStrength = 0;
    }

    if (gColorStrength > bColorStrength && bColorStrength > rColorStrength)
    {
        gColorStrength = 255;
        bColorStrength = bColorStrength / 2;
        rColorStrength = 0;
    }

    if (gColorStrength > rColorStrength && rColorStrength > bColorStrength)
    {
        gColorStrength = 255;
        rColorStrength = rColorStrength / 2;
        bColorStrength = 0;
    }

    // Writing to RGB LED.
    analogWrite(redLedPin, rColorStrength);
    analogWrite(greenLedPin, gColorStrength);
    analogWrite(blueLedPin, bColorStrength);
    delay(250);
}
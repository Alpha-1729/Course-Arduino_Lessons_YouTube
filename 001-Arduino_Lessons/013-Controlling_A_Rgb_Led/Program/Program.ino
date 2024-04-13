// Controlling A Rgb Led

/*
>>>> Types of RGB LED.
        Common Cathode RGB LED.
            Longest Pin -> GND -> Second Pin
            First Pin -> Red
            Third Pin -> Green
            Fourth Pin -> Blue
        Common Anode RGB LED.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

int redLedPin = 9;
int blueLedPin = 10;
int greenLedPin = 11;
int redBrightness = 75;
int blueBrightness = 75;
int greenBrightness = 75;
void setup()
{
    pinMode(redLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
}

void loop()
{
    // Red
    analogWrite(redLedPin, redBrightness);
    analogWrite(blueLedPin, 0);
    analogWrite(greenLedPin, 0);
    delay(1000);

    // Green
    analogWrite(redLedPin, 0);
    analogWrite(blueLedPin, 0);
    analogWrite(greenLedPin, greenBrightness);
    delay(1000);

    // Blue
    analogWrite(redLedPin, 0);
    analogWrite(blueLedPin, blueBrightness);
    analogWrite(greenLedPin, 0);
    delay(1000);
}

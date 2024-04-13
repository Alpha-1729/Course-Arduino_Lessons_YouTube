// Write Analog Voltages

/*
>>>> Analog Write:
        Reference Link: https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
>>>> Equation for writing analog value in the pin.
        0-5V is mapped to 0-255 Analog value.
        AnalogValue = DesiredVoltage * 51;
>>>> Analog Write will work only with the pins with the ~ symbol.
>>>>
>>>>
>>>>
*/

int redLedPin = 9;
void setup()
{
    pinMode(redLedPin, OUTPUT);
}

void loop()
{
    analogWrite(redLedPin, 125); // Applying 2.5V to led.
    delay(500);
    analogWrite(redLedPin, 0); // Turn off the led.
    delay(500);
}
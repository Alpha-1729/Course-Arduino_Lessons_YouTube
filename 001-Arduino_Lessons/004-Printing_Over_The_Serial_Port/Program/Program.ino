// Printing Over The Serial Port

/*
>>>> Baud rate
        Baud rate is the speed at which the arduino is talking via the serial port.
        Baud rate must be same in code and serial monitor.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

int redLedPin = 9;
int redOnTime = 250;
int redOffTime = 250;

int yellowLedPin = 10;
int yellowOnTime = 250;
int yellowOffTime = 250;

int redLedBlinkCount = 3;
int yellowLedBlinkCount = 5;

void setup()
{
    // Turn on the serial port.
    Serial.begin(9600);

    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
}

void loop()
{
    // Blink red led.
    Serial.println("The red led is blinking.");
    for (int j = 1; j <= redLedBlinkCount; j = j + 1)
    {
        // Printing the string and number.
        Serial.print("   You are on Blink #: ");
        Serial.println(j);

        digitalWrite(redLedPin, HIGH);
        delay(redOnTime);
        digitalWrite(redLedPin, LOW);
        delay(redOffTime);
    }
    Serial.println(); // Printing an empty line.

    // Blinking of yellow led
    Serial.println("The yellow led is blinking. ");
    for (int j = 1; j <= yellowLedBlinkCount; j = j + 1)
    {
        // Printing the string and number.
        Serial.print("   You are on Blink #: ");
        Serial.println(j);

        digitalWrite(yellowLedPin, HIGH);
        delay(yellowOnTime);
        digitalWrite(yellowLedPin, LOW);
        delay(yellowOffTime);
    }
    Serial.println(); // Printing an empty line.
}

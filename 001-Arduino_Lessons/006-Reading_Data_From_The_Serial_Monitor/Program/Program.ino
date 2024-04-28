// Reading Data From The Serial Monitor

/*
>>>> Getting user input from the Serial Monitor.
        Serial.available() will be 0, if there is no input available.
        Else, it will be 1.

>>>> Converting the data read from the Serial Monitor:
        Serial.parseInt()
        Serial.parseFloat()
        Serial.readString()
>>>>
>>>>
>>>>
>>>>
*/

// Declaring string in arduino.
String redLedMessage = "The red led is blinking";
String yellowLedMessage = "The yellow led is blinking";

int redLedPin = 9;
int redOnTime = 250;
int redOffTime = 250;

int yellowLedPin = 10;
int yellowOnTime = 250;
int yellowOffTime = 250;

int redLedBlinkCount;
int yellowLedBlinkCount;

void setup()
{

    Serial.begin(9600);

    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);

    // Getting the red blink count from user.
    Serial.print("Enter the red blink count: ");
    while (Serial.available() == 0)
    {
    }
    redLedBlinkCount = Serial.parseInt(); // Converting string into int.

    // Getting the yellow blink count from user.
    Serial.print("Enter the yellow blink count: ");
    while (Serial.available() == 0)
    {
    }
    yellowLedBlinkCount = Serial.parseInt(); // Converting string into int.
}

void loop()
{

    // Blinking of red led.
    Serial.println(redLedMessage);
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

    // Blinking of yellow led.
    Serial.println(yellowLedMessage);
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

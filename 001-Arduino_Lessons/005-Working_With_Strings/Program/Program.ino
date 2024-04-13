// Working With Strings

/*
>>>> Please look at the void setup. Some string work is done there.
>>>>
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

int redLedBlinkCount = 3;
int yellowLedBlinkCount = 5;

void setup()
{
    Serial.begin(9600);

    // Printing the welcome message.
    // Creating a local variable.
    String msg1 = "Welcome to my "; // Initialize a variable.
    String msg2 = "Program!!!";     // Initialize a variable.
    String fullMessage;             // Declaring a string variable.

    fullMessage = msg1 + msg2;   // String concatenation.
    Serial.println(fullMessage); // Printing the message on the serial monitor.

    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
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

// Arduino If Statements And Conditionals

/*
>>>> Logical operators.
        ==, !=, >=, <=, <, >
>>>> Comparison operators.
        &&, ||
>>>>
>>>>
>>>>
>>>>
*/

int redLedPin = 9;
int blueLedPin = 10;
int greenLedPin = 11;
int brightness = 255;
String color;

void setup()
{
    Serial.begin(9600);
    pinMode(redLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
}

void loop()
{

    Serial.println("Enter a color (red/green/blue): ");
    while (Serial.available() == 0)
    {
    }
    color = Serial.readString();

    // Red
    if (color == "red")
    {
        analogWrite(redLedPin, brightness);
        analogWrite(blueLedPin, 0);
        analogWrite(greenLedPin, 0);
    }

    // Green
    if (color == "green")
    {
        analogWrite(redLedPin, 0);
        analogWrite(blueLedPin, 0);
        analogWrite(greenLedPin, brightness);
    }

    // Blue
    if (color == "blue")
    {
        analogWrite(redLedPin, 0);
        analogWrite(blueLedPin, brightness);
        analogWrite(greenLedPin, 0);
    }

    if (color != "red" && color != "blue" && color != "green")
    {
        Serial.println();
        Serial.println("Enter a valid color red/green/blue)");
        Serial.println();
    }
}

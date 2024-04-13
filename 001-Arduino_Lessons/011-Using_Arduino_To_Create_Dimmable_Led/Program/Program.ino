// Using Arduino To Create Dimmable Led

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

int potPin = A0;
int redLedPin = 2;
int readValue;
int writeValue;

void setup()
{
    pinMode(potPin, INPUT);
    pinMode(redLedPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    readValue = analogRead(potPin);
    writeValue = (255.0 / 1023.0) * readValue;
    analogWrite(redLedPin, writeValue);
    Serial.println(writeValue);
}
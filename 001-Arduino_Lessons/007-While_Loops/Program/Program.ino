// While Loops

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int j = 1;
    while (j <= 10)
    {
        Serial.print("You are on loop: ");
        Serial.println(j);
        j = j + 1;
    }
    Serial.println(); // Empty line.
}
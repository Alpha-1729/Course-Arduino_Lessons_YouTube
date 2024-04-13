// Using Lcd Display With Arduino

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

#include <LiquidCrystal.h>

// Creating a LCD Object.
LiquidCrystal LCD(10, 9, 5, 4, 3, 2); // RS, E, DB4, DB5, DB6, DB7
int counter;

void setup()
{
    Serial.begin(9600);
    LCD.begin(16, 2);
    LCD.setCursor(0, 0); // Column, Row
    LCD.print("My Timer:");
}

void loop()
{

    for (counter = 1; counter <= 10; counter++)
    {
        LCD.setCursor(0, 1);
        LCD.print("                "); // Clear the screen.
        LCD.setCursor(0, 1);
        LCD.print(counter);
        LCD.print(" Seconds");
        delay(1000);
    }

    for (counter = 10; counter >= 0; counter--)
    {
        LCD.setCursor(0, 1);
        LCD.print("                "); // Clear the screen.
        LCD.setCursor(0, 1);
        LCD.setCursor(0, 1);
        LCD.print(counter);
        LCD.print(" Seconds");
        delay(1000);
    }
}

// Arduino Breadboard Tutorial

/*
>>>> 330 Ohm resistor should be used to limiting current.
		Color code: Orange, Orange, Brown.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

int redLedPin = 9;
int onTime = 1000;
int offTime = 500;

void setup()
{
	pinMode(redLedPin, OUTPUT);
}

void loop()
{
	digitalWrite(redLedPin, HIGH);
	delay(onTime);
	digitalWrite(redLedPin, LOW);
	delay(offTime);
}

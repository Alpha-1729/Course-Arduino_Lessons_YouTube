// For Loops And Led Circuit

/*
>>>>
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
	pinMode(redLedPin, OUTPUT);
	pinMode(yellowLedPin, OUTPUT);
}

void loop()
{
	// Blink red led.
	for (int j = 1; j <= redLedBlinkCount; j = j + 1)
	{
		digitalWrite(redLedPin, HIGH);
		delay(redOnTime);
		digitalWrite(redLedPin, LOW);
		delay(redOffTime);
	}

	// Blink yellow led.
	for (int j = 1; j <= yellowLedBlinkCount; j = j + 1)
	{
		digitalWrite(yellowLedPin, HIGH);
		delay(yellowOnTime);
		digitalWrite(yellowLedPin, LOW);
		delay(yellowOffTime);
	}
}

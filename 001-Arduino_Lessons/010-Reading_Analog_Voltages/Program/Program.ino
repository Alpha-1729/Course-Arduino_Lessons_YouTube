// Reading Analog Voltages

/*
>>>> Circuit setup.
        Connect one leg of potentiometer to 5V and other to GND.
        Connect centre pin of potentiometer to A0.
>>>> Range of analogRead is in between 0-1023.
>>>> A0- A6 in Arduino UNO can only be used for analog read.
>>>> ~ can be used to analogWrite and digitalWrite
>>>> Other pins can be only used for only digitalWrite.
>>>>
*/

int potPin = A0;
int readValue;
float actualVoltage;

void setup()
{
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop()
{
  readValue = analogRead(potPin);
  actualVoltage = (5.0 / 1023.0) * readValue;
  Serial.println(actualVoltage);
  delay(250);
}

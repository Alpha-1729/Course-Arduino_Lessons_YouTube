// Measure Speed Of Sound With Arduino And Ultrasonic Sensor.

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

// Ultrasonic sensor pins.
int trigPin = 13;
int echoPin = 11;

float speedOfSound;
float targetDistance = 6; // 6 inches.
float pingTime;

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    // Measuring the ping time
    // Generate a high pulse.
    digitalWrite(trigPin, 0);
    delayMicroseconds(2000); // Wait for 2 milliseconds.
    digitalWrite(trigPin, 1);
    delayMicroseconds(10);    // Wait for 10 microseconds.
    digitalWrite(trigPin, 0); // Ping has been released.

    pingTime = pulseIn(echoPin, HIGH);

    speedOfSound = (2 * targetDistance) / pingTime;         // Speed in inches/microseconds.
    speedOfSound = speedOfSound / (63360 * 1000000 * 3600); // Speed in miles per hour.

    Serial.print("The speed of sound is: ");
    Serial.print(speedOfSound);
    Serial.println(" miles per hour.");
    delay(1000);
}
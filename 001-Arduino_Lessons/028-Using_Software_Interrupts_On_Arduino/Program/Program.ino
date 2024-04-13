// Using Software Interrupts On Arduino

/*
>>>> Arduino Interrupts.
        In Arduino, interrupts are used to trigger a specific function or piece of code in response to an event. They allow the microcontroller to pause its current task and handle a higher-priority task immediately. Interrupts are crucial for handling real-time events and ensuring timely responses in embedded systems.

        There are two types of interrupts in Arduino and similar microcontroller environments:

        Hardware Interrupts:
            Hardware interrupts are triggered by external signals, such as a change in voltage level or a pulse from a sensor.
            Arduino boards have specific pins labeled as interrupt pins (e.g., interrupt 0, interrupt 1, etc.), which can be used to trigger hardware interrupts.
            When a hardware interrupt occurs, the microcontroller temporarily stops its current task, executes the interrupt service routine (ISR), and then resumes the interrupted task.
            Hardware interrupts are commonly used for handling real-time events like button presses, sensor readings, or external triggers.

        Software Interrupts:
            Software interrupts are triggered by software instructions within the code.
            Arduino provides the interrupt() function (also known as attachInterrupt()), which allows you to define a software interrupt that triggers an ISR.
            Unlike hardware interrupts, software interrupts are triggered by specific code instructions and do not require external signals.
            Software interrupts can be useful for creating periodic tasks, time-sensitive operations, or custom event handling within your Arduino sketch.
>>>> TimerOne library.
        Download interrupt library from toptechboy.com website.
        Library Download Link: https://code.google.com/archive/p/arduino-timerone/downloads
        Zip file for the library is also attached in the current folder.
>>>>
>>>>
>>>>
>>>>
*/

#include <Timerone.h>

int redLedPin = 9;
int yellowLedPin = 10;
String ledStatus = "OFF";

void setup()
{
    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);

    // Timer will be activated every 1 second.
    Timer1.initialize(1000000); // 1 million microsecond(1 Second)
    Timer1.attachInterrupt(blinkYellow);
}

void loop()
{
    digitalWrite(redLedPin, HIGH);
    delay(250);
    digitalWrite(redLedPin, LOW);
    delay(250);
}

void blinkYellow()
{
    if (ledStatus == "ON")
    {
        digitalWrite(yellowLedPin, LOW);
        ledStatus = "OFF";
    }
    else
    {
        digitalWrite(yellowLedPin, HIGH);
        ledStatus = "ON";
    }
}
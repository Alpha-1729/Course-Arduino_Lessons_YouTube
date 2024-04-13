// Introduction

/*
>>>> Author's website
		Reference Link: www.toptechboy.com
>>>> An advantage of arduino.
		Arduino based system can be sent to space and sent back photo from there.
>>>> Arduino Installation
		Download Arduino and Install
			Reference Link: https://www.arduino.cc/en/software
		Install the necessary drivers.
		Connect the board using a standard usb cable.
		Choose the board.
			Tools -> Board -> Arduino Uno
		Choose the serial port.
			Tools -> Ports.
>>>> Void Setup and Void Loop
		Void Setup:
			Used to setup the pinMode.
			One time configuration fall under this category.
		Void Loop:
			Things that need to be done over and over again.
>>>> Pin 13 is the onboard led pin in Arduino Uno R3
>>>> Some arduino uno need the ch340 driver.
		Which can be downloaded and installed.
		OR
		Update the driver in the device manager.
>>>> Download arduino previous versions.
		 Reference Link: https://www.arduino.cc/en/Main/OldSoftwareReleases#previous
>>>> Compilation
		Compilation means converting code into the binary(or hex) file.
		We can find error in code by clicking on the verify button on the arduino IDE.
>>>> Arduino shortcuts.
		Ctrl+N	        New Sketch
		Ctrl+O	        Open Existing Sketch
		Ctrl+S	        Save Sketch
		Ctrl+R	        Verify
		Ctrl+U	        Upload Sketch
		Ctrl+F	        Find
		Ctrl+T	        Adjust Alignment and Space
		Ctrl+/	        Comment
		Ctrl+Q	        Quit
		Ctrl+W	        Close
		Ctrl+P	        Print
		Ctrl+,	        Preferences
		Ctrl+C	        Copy
		Ctrl+X	        Cut
		Ctrl+V	        Paste
		Ctrl+L	        Go to Line
		Ctrl+A	        Select All
		Ctrl+G	        Find Next
		Ctrl+K	        Open Sketch Folder
		Ctrl+T	        Auto Format
		Tab	            Increase Indent
		Shift+Tab	    Decrease Indent
		Ctrl+Shift+G	Find Previous
		Ctrl+Shift+U	Upload using Programmer
		Ctrl+Shift+S	Save As Sketch
		Ctrl+Shift+M	Open Serial Monitor
		Ctrl+Shift+P	Page SetUp
		Ctrl+Shift+L	Serial Plotter
		Ctrl+Shift+F	Find in Reference
*/

int ledPin = 13;
int waitTimeOn = 1000;
int waitTimeOff = 1000;

void setup()
{
	pinMode(ledPin, OUTPUT);
}

void loop()
{
	digitalWrite(ledPin, HIGH);
	delay(waitTimeOn);
	digitalWrite(ledPin, LOW);
	delay(waitTimeOff);
}

// Read String Float And Ints Over The Serial Port

/*
>>>> Read name, age, height and print in the serial monitor.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

int age;
String name;
float height;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // Name
    Serial.println("Enter your name: ");
    while (Serial.available() == 0)
    {
    }
    name = Serial.readString();

    // Age
    Serial.println("Enter your age: ");
    while (Serial.available() == 0)
    {
    }
    age = Serial.parseInt();

    // Height
    Serial.println("Enter your height: ");
    while (Serial.available() == 0)
    {
    }
    height = Serial.parseFloat();

    Serial.println();

    // Formatted output.
    Serial.print("Hello, ");
    Serial.print(name);
    Serial.print(", You are ");
    Serial.print(age);
    Serial.print(" year's old and you are ");
    Serial.print(height);
    Serial.print(" inch tall.");
    Serial.println();
}
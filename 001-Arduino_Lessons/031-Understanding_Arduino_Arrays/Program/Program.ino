// Understanding Arduino Arrays

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

float grades[25];
int gradeCount;
float avg;
float gradeSum;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    gradeSum = 0;
    Serial.println("How many Grade? ");
    while (Serial.available() == 0)
    {
    }
    gradeCount = Serial.parseInt();
    for (int i = 0; i < gradeCount; i++)
    {
        Serial.println("Enter your Grade: ");
        while (Serial.available() == 0)
        {
        }
        grades[i] = Serial.parseFloat();
    }

    for (int i = 0; i < gradeCount; i++)
    {
        gradeSum = gradeSum + grades[i];
    }
    avg = gradeSum / gradeCount;
    Serial.print("Your average is ");
    Serial.println(avg);
}
// Passing Parameters And Variables By Reference In Arduino Functions

/*
>>>> Call by reference.
        We are passing variables to a function and accepting the variables after function do its task.
        There by we can return multiple values from function.
        We can use instead of return.
>>>>
>>>>
>>>>
>>>>
>>>>
*/

void setup()
{
}

void loop()
{
    float a, b, c, d;

    a = 25;
    b = 30;

    tally(a, b, c, d);
    Serial.print("The sum of your numbers is: ");
    Serial.println(c);

    Serial.print("The difference of your numbers is: ");
    Serial.println(d);
}

// Call by reference is happening here.
// The value of the sum and the difference is returned to it's corresponding variables.
void tally(float firstNum, float secondNum, float &sum, float &difference)
{
    sum = firstNum + secondNum;
    difference = firstNum - secondNum;
}

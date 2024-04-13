// Returning A Variable From A Function

/*
>>>>
>>>>
>>>>
>>>>
>>>>
>>>>
*/

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    float num = 2.0;
    float result = findSquare(x);
    Serial.println(result);
}

float findSquare(float num)
{
    float result;
    result = num * num;
    return result;
}
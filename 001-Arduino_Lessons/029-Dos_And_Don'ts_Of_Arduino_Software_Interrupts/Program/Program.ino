// Dos And Don'ts Of Arduino Software Interrupts

/*
>>>> Dos
        Do things quickly in interrupt function.
>>>> Don'ts
        Don't use delay in interrupt function.
        If you use delay in interrupt function, arduino will ignore it.
        Don't use print function, it is also a delay.
        Don't use user input in interrupt function.
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
}

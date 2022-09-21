#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float input; // declare the float
    do
    {
        input = get_float("Change owed: "); //ask for an input

    }//while(input < 0 || input == -0); //keep asking if the input is below 0, but -0 is working
    while (input <= 0); //is the same while like while above

    //printf("The output: %.2f\n", input); //they appear only 2 digits after .

    int cents = round(input * 100);
    //printf("Input in cents: %i\n", cents);

    int quarter = 25; //declaring and assigning in case of change of cents
    int dime = 10;  //declaring and assigning in case of change of cents
    int nickel = 5;  //declaring and assigning in case of change of cents
    int penny = 1;  //declaring and assigning in case of change of cents

    int count = 0;
    while (cents >= quarter) //check the cents whether are higher or equal to quarter
    {
        count++; //count coins
        cents = cents - quarter; //remainder
    }

    //printf("What is the number of coins after quarters: %i\n", count);
    //printf("What is the remainder: %i\n", cents);

    while (cents >= dime) //check the cents whether are higher or equal to dime
    {
        count++; // count coins - increment to the previous coins
        cents = cents - dime; // remainder
    }

    //printf("What is the number of coins after dimes: %i\n", count);
    //printf("What is the remainder: %i\n", cents);


    while (cents >= nickel) //check the cents whether are higher or equal to nickel
    {
        count++; // count coins - increment to the previous coins
        cents = cents - nickel;  // remainder
    }

    //printf("What is the number of coins after nickles: %i\n", count);
    //printf("What is the remainder: %i\n", cents);

    while (cents >= penny) // check the cents whether are higher or equal to penny
    {
        count++; // count coins - increment to the previous coins
        cents = cents - penny; // remainder
    }

    printf("%i\n", count);
    //printf("What is the remainder: %i\n", cents);
    return 0;
}
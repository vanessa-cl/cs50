#include <cs50.h>
#include <stdio.h>
#include <math.h>

float getAmountOfChange(void);
int totalCoins(int cents);

int main(void)
{
    //converts the change to int
    int cash = round(getAmountOfChange() * 100);
    //prints the total number of coins needed for the change
    printf("%i\n", totalCoins(cash));
}

float getAmountOfChange(void)
{
    float change = 0;
    do
    {
        //asks the change value in cents
        change = get_float("Amount of change: $");
    }
    while (change < 0.00);
    return change;
}

int totalCoins(int cents)
{
    //the initial amount of coins
    int change = 0;
    do
    {
        //verifies if cents is divisible by the highest coin (25)
        //then subtracts the coin from the cents
        //while increases the number of coins necessary for the change
        if (cents / 25)
        {
            cents -= 25;
            change++;
        }
        else if (cents / 10)
        {
            cents -= 10;
            change++;
        }
        else if (cents / 5)
        {
            cents -= 5;
            change++;
        }
        else
        {
            cents -= 1;
            change++;
        }
    }
    while (cents > 0);
    return change;
}

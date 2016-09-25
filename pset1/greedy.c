/* 
ask the user how much change is owed and then spits out the minimum nmbr of coins
use: GetFloat and printf
user input: GetFloat + check for non-negative
from float to integer to avoid mistakes; round pennies; one dollar equals 100c
coins available: 25c, 10c, 5c and 1c

pset1_3
Ann Peeters
*/

#include <stdio.h>
#include <cs50.h>

float GetChange();
int ToCents(float f);
int CalculateHowManyCoins(int c);

int main(void)
{
    float change = GetChange(); 
    int cents = ToCents(change);
    int howManyCoins = CalculateHowManyCoins(cents);
    printf("Change can be given in %i coins.", howManyCoins);
}

int CalculateHowManyCoins(int c)
// input is integer in cents
// output is integer, number of coins the cents are min made up of
{
    int howManyCoins = 0;
    
    // 25c coins
    int howMany25c = c / 25;
    //printf("25cents: %i\n", howMany25c);
    c = c % 25;
    //printf("return money left: %i\n", c);
    howManyCoins = howManyCoins + howMany25c;
    //printf("coins uptil now: %i\n", howManyCoins);
    
    // 10c
    int howMany10c = c / 10;
    c = c % 10;
    howManyCoins = howManyCoins + howMany10c;
    
    // 5c
    int howMany5c = c / 5;
    c = c % 5;
    howManyCoins = howManyCoins + howMany5c;
    
    // 1c
    howManyCoins = howManyCoins + c;
    
    return howManyCoins;
}


int ToCents(float f)
// takes float (dollars)
// gives int (cents)
{
    // from dollars to cents  *100
    f = f * 100;
    int c;
    c = (int) f;
    return c;
}

float GetChange(void)
// takes user input
// gives float
{
    float c;
    do
    {
        //prompt for the change
        //non-negative number
        printf("How much change is owed? ");
        c = GetFloat();
    }
    while (c < 1);
    return c;
}

/* Prompts the user for the length of shower in minutes
and returns the equivalent number of bottles of water 

PSet1
Ann Peeters
*/

#include <stdio.h>
#include <cs50.h>

void CalculateBottles();

int main(void)
{
    // ask for length of shower in minutes
    printf("How many minutes do you shower? ");
    unsigned int minutes = GetInt();
    CalculateBottles(minutes);

}

/**
 * Calculate how many bottles
 * */
 
void CalculateBottles(int min)
{
    int b;
    // 1 minute is typially 12 bottles of water
    b = min * 12;
    printf("In those %i minutes, you used %i bottles of water.\n", min, b);
}

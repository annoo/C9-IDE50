#include <stdio.h>
#include <cs50.h>

int GetHeight();

int main(void)
{
    int h = GetHeight();
    fprintf("%#*c", h ,0);    
}

int GetHeight(void)
{
    int h;
    do
    {
        //prompt for half the height
        //non-negative number < 23
        printf("Please give me the height of the pyramid, no greater than 23: ");
        h = GetInt();
    }
    while ((h < 1) || (h > 24));
    return h;
}



/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdlib.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
 //binary version
bool search(int value, int values[], int n)
{
    int f, l, m;
    f = 0;
    l = n;
   
    while (f <= l)
    {
        m = (f + l)/2;
        if (values[m] == value)
            return true;
        else if (values[m] < value)
            f = m + 1;
        else if (values[m] > value)
            l = m - 1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int value, hole;
    
    for (int i = 0; i < n; i++)
    {
        // select the value to be inserted
        value = values[i];
        
        // select the hole position/index where the number should go
        hole = i;
        
        // check if previous value is larger than value to be inserted
        while (hole > 0 && values[hole-1] > value)
        {
            // shove the hole to the left
            values[hole] = values[hole -1];
            hole--;
        }
        if (hole != i)
        {
            // put the value in the hole
            values[hole] = value;
        }
    }
}
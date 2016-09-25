/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (!(n < 0))
        for (int i = 0; i < n; i++)
            if (values[i] == value)
                return true;
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Quicksort
    int l, r, pivot, temp;
    low = values[0];
    
    l = 0;
    r = n;
    pivot = (l+r)/2;
    
    if (n < 2)
        return;
    
    while (l <= r)
    {
        while (values[l] < pivot)
            l++;
        while (pivot < values[r])
            r--;
        if (l <= r)
        {
            temp = values[l];
            values[l] = values[r];
            values[r] = temp;
        }
    }
    sort(values[], l);
    sort(values[] + l, n -l);
}
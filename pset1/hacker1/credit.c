/*
http://cdn.cs50.net/2016/x/psets/1/hacker1/hacker1.html
*/

#include <stdio.h>
#include <cs50.h>

void CheckCompany(long long c);
bool CheckValidity(int n);
    int CheckOne(long long n);
    int CheckTwo(long long n);

int main(void)
{
    // Get input
    printf("Your cards number: ");
    long long n = GetLongLong();
    if CheckValidity(n)
    {
        CheckCompany(n);
    }
    return 0;
}

bool CheckValidity()
{
    int c1 = CheckOne(long long n);
    int c2 = CheckTwo(long long n);
    int c = c1 + c2;
    if c % 10 != 0
    {
        printf("INVALID\n");
    }
}

int CheckOne(long long n)
{
    //TODO
    // second-to-last and every other digit before * 2
    // split number into digits
    // sum of these digits
    // return c1
}

int CheckTwo(long long n)
{
    //TODO
    // sum of every other digit starting from last
    //return c2
}

int CheckCompany(long long c)
{
    // if first two digits are 34 or 37 => AmEX
    if (c[0] == 3) && ((c[1] == 4) || (c[1] == 7))
    {
        printf("AMEX\n");
    }
    
    // if first two digits are 51, 52, 53, 54, 55 => MasterCard
    else if (c[0] == 5) && 
        ((c[1] == 1) || 
         (c[1] == 2)
         (c[1] == 3)
         (c[1] == 4)
         (c[1] == 5))
    {
        printf("MASTERCARD\n");
    }
    
    // if first digit is 4 => VISA
    else if (c[0] == 4) 
    {
        printf("VISA\n");
    }
    else
    {
        printf("INALID\n");
    }
}
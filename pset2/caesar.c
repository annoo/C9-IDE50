/*
 encrypts messages using Caesar's cipher
 accept: single command-line argument: non-negative integer (k)
 
 sept 2016
 Ann Peeters
*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//protocode
int Decipher(string s, int k);
int Fault(void);
bool CheckKeyDigit (string s);
bool CheckKeyPositive (string s);

//main
int main(int argc, string argv[])
{
    // check if key input is valid
    if (
        (!(argc == 2))                  // has to have 1 name + 1 argumetn
        || (! CheckKeyDigit(argv[1]))   // has to be a number
        || (! CheckKeyPositive(argv[1]))// has to be a positive number
        )
    {
        Fault();
    }
    
    else
    {
        // Get code input and check if string is real
        string s = GetString();
        if (s == NULL)
        {
            Fault();
        }

        else
        {
            int k = atoi(argv[1]);
            Decipher(s, k);
        }
    }
}    
    
int Decipher(string s, int k)
{
    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (islower(s[i]))
            printf("%c", (((s[i]) + k - 'a') % 26) + 'a');
        else if (isupper(s[i]))
            printf("%c", (((s[i]) + k - 'A') % 26) + 'A');
        else
            printf("%c", s[i]);
    }
    printf("\n");
    //printf("return 0;\n");
    return 0;
    }    

int Fault(void)
{
    printf("return 1;\n");
    return 1;
}

bool CheckKeyDigit (string s)
{
    int flagNotNumber;
    for (int i = 0, n = strlen(s); i < n ; i++ )
    {
        if (isdigit(s[i]))
        {
            flagNotNumber = 0;
            continue;
        }
        else
        {
            flagNotNumber = 1;
            break;
        }
    }
    if (flagNotNumber == 1)
        return false;
    else
        return true;
}

bool CheckKeyPositive (string s)
{
    int k = atoi(s);
    if (k < 0)
        return false;
    else
        return true;
}
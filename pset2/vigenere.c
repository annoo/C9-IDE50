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
int VigenereCipher(string s, string k);
int Fault(void);
bool CheckKeyNotDigit (string s);
bool CheckKeyPositive (string s);

//main
int main(int argc, string argv[])
{
    // check if key input is valid
    // if not: stop
    if (
        (!(argc == 2))                      // has to have 1 name + 1 argument
        || (! CheckKeyNotDigit(argv[1]))    // has to be letters
        )
    {
        Fault();
    }
    
    // if so: continue
    else
    {
        // Name keyword k
        string k = argv[1];
        // Get code input and check if string is real
        string s = GetString();
        
        
        if (s == NULL)
        {
            Fault();
        }

        else
        {
            VigenereCipher(s, k);
        }
    }
}    
    
int VigenereCipher(string s, string k)
{
    int keyLength = strlen(k);
    //TODO: value of k[j] is wrong; I think it uses char ASCII numbers instead of 0 to 26
    int j  = 0; 
    
    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        
        if (islower(s[i]))
        {
            printf("%c", (((s[i]) + k[j] - 'a') % 26) + 'a'); 
            j = (j + 1) % keyLength;
        }
        else if (isupper(s[i]))
        {
            printf("%c", (((s[i]) + k[j] - 'A') % 26) + 'A');
            j = (j + 1) % keyLength;
        }
        else
        {
            printf("%c", s[i]);
        }
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

bool CheckKeyNotDigit (string s)
{
    int flagNotNumber;
    for (int i = 0, n = strlen(s); i < n ; i++ )
    {
        if (! isdigit(s[i]))
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
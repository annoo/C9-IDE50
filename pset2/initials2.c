#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    
    if (s != NULL)
    {
        if ((int) s[0] > 96)
        {
            printf("%c", (int) s[0] -32); // 'a' - 'A' instead of 32
        }
        else
        {
            printf("%c", s[0]);
        }
        
        for (int i = 0, n = strlen(s); i < n; i++)
        {
        
            if (s[i] == ' ')
            {
                if ((int) s[i+1] > 96)
                {
                    printf("%c", (int) s[i+1] -32);
                }
                else printf("%c", s[i+1]);
            }
        }
        printf("\n");
    }
    
    
}


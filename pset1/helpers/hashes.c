#include <stdio.h>
#include <cs50.h>

void DrawBlocks();

int main(void)
{
    DrawBlocks(4);
}


void DrawBlocks(w)
{
    for (int i = 0; i < w; i++)
    {
        printf("#");
    }
}
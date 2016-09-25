#include <stdio.h>
#include <cs50.h>

int GetHeight();
void DrawBlocks();
void DrawHalfPyramid();

int main(void)
{
    int h = GetHeight();
    DrawHalfPyramid(h);    
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

void DrawHalfPyramid(int height)
{
   
    for (int i = 1; i <= height; i++)
    {
        //print spaces
        printf("%*s", height +1 - i, "");
        
        // print hashes 
        DrawBlocks(i);
        
        // print 2 spaces
        printf("  ");
        
        // print hashes
        DrawBlocks(i);
        
        // print new line
        printf("\n");
    }
}

void DrawBlocks(w)
{
    for (int i = 0; i < w; i++)
    {
        printf("#");
    }
}
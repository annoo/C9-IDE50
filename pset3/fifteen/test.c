#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int d;
int board[d][d];

void init(void)
{
    // Could this be done by simple making 2D array={...}
    // board[d][d] = {15, 14 etc ,..}
    // and let draw take care of the visual representation?
    // I don't find how to do this with a 2D array
    
    int total, tile;
    total = d * d - 1;
    tile = total; // to start with
    
    //vertical lines
    for (int i = 0; i < d; i++)
    {
        //horizontal lines
        for (int j = 0; j < d; j++)
        {
        // exception when d is even at 2 places
        if (d%2 == 0)
            {
            if ((i = d-1) && (j = d-3))
                board[i][j] = 1;
            else if ((i = d-1) && (j = d-2))
                board[i][j] = 2;
            }
        board[i][j] = tile;
        tile--;
        }
    }        
}

void draw(void)
{
    printf("%*s", d * 4, "-");
    //vertical lines
    for (int i = 0; i < d; i++)
    {
        //horizontal lines
        for (int j = 0; j < d; j++)
        {
            printf("| %d |", board[i][j]);
        }
    printf("%*s", d * 4, "-");
    printf("\n");
    }
}

int main(int argc, string argv[])
{
    d = atoi(argv[1]);
    init();
    draw();
}
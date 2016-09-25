// spare code
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
         }
         board[i][j] = tile;
         tile--;
         
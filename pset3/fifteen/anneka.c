#include <stdio.h>
#include <stdlib.h>

/* Sliding Tiles Game
 * pointer version!
 * including Function Pointers!!!
 */

int getLeft(int pos,int dimension){
  // if the positin is a multiple of the dimension, then nothing to the left
  //printf("left: %dimension",pos);
  if (pos%dimension){
    return pos-1;
  }
  else{
    return -1;
  }
}
int getRight(int pos,int dimension){
  // if the position+1 is a multiple of the dimension, then nothing to the right
  if ((pos+1)%dimension){
    return pos+1;
  }
  else{
    return -1;
  }
}
int getDown(int pos,int dimension){
  // if the position is less that the dimension, then nothing to the down
  if (pos<dimension){
    return -1;
  }
  else{
    return pos-dimension;
  }
}
int getUp(int pos,int dimension){
  // if the position is greater than or equal to the dimensionimension^2-n, then nothing to the up
  if (pos>=(dimension*(dimension-1))){
    return -1;
  }
  else{
    return pos+dimension;
  }
}

void fillMoveable(int pos,int dimension,int *moveablePositions){
  /* 4 cases : right, left, above, under
   * note the use of an array of function pointers so as to avoid the cursed 'switch/case'!!!
   */
  
  // define an array of pointers to functions return int and taking (int,int) as arguments,
  // in other words an array of pointers to functions which all look like the 'getFunction' above!
  // and initialize the array appropriately
  int (*offsetFuncs[])(int,int) = {&getLeft,&getRight,&getUp,&getDown};

  // now use the function pointers to fill the moveablePositions vector
  for (int i=0; i< 4;i++){
    moveablePositions[i] = (*offsetFuncs[i])(pos,dimension);
  }
}

int won(int *board, int dimension){
  for (int i=0;i<(dimension*dimension-1);i++){
    if ((i+1)!= *(board+i)){
	return 0;
    }
  }
  return 1;
}

void init(int *board,int dimension){
  // fill the board pointe d in arg with the numbers as per dimension
  // swap last 2 in case of even dimension
  int v = dimension*dimension-1;
  for (int i=0;i<(dimension*dimension);i++){
    *(board+i)=v--;
  }
  if (!(dimension%2)){ // even, swap end tiles
    int temp = *(board+(dimension*dimension-2));
    *(board+(dimension*dimension-2)) = *(board+(dimension*dimension-3));
    *(board+(dimension*dimension-3)) = temp;
  }
}

void display (int *board, int dimension, int* moveablePositions, int* zeroPos){
  // print to screen current layout,
  // while iterating, fill the zero position pointed in arg
  // and fill the moveablePositions vector pointed in arg
  for (int i=0;i<(dimension*dimension);i++){
    if (!(i%dimension)){
      printf("\n");
    }
    if  (*(board+i)){
      printf("\t%2d",*(board+i));
    }
    else{
      printf("\t");
      *zeroPos = i;
      fillMoveable(i,dimension,moveablePositions);
    }
  }
  printf("\n");
}


int moveOk(int tile, int *moveablePositions, int *board){
  // return the offset of the tile to move, or -1 if not possible
  int res = -1;
  for (int i=0;i<4;i++){
    if (*(moveablePositions+i) !=-1){
      if (*(board+moveablePositions[i]) == tile){ // found it
	res = moveablePositions[i];
	break;
      }
    }
  }
  return res;
}

void  move(int offSet,int zero,int *board){
  // exchange the tile at the offSet with the tile at the zero position
  *(board+zero) = *(board+offSet);
  *(board+offSet) = 0;
}

int main(int argc, char **argv){
  // first command line argument must be the dimension!
  if (argc<2){
    printf("must provide dimension as argument!\n");
    exit(0);
  }
  // initialize local variables
  int dimension =atoi(argv[1]);
  int board[dimension*dimension];
  int tile;
  int zero;
  int moveableOffsets[]= {-1,-1,-1,-1};
  // initialize the board
  init(board,dimension);
  // loop until we've won the game!
  while (!won(board,dimension)){
    //display and update moveables and zero
    display(board,dimension,moveableOffsets,&zero);
    // get the tile we want to move
    printf("Tile to move: ");
    scanf("%d",&tile);
    // recover its offset or -1 if it can't be moved
    int offSet = moveOk(tile,moveableOffsets,board);
    // if it's ok, move it
    if (offSet != -1){
      move(offSet,zero,board);
    }
    // continue the loop
  }
  // at this point we won, so display, congratulate and exit
  display(board,dimension,moveableOffsets,&zero);
  printf("Well done, you won!\n");
  exit(0);
}
  

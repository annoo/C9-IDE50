/*
 * pointers.c
 * examples of pointers that work
 */

#include <stdio.h>

int d = 4;

int main(){
  /* define a dxd array of ints,
   * and   
   * define an int with value (d * d )-1 
   */
  int board[d][d],
      total = d*d,
      tile = d*d-1,
      *board_ptr;

  /* define a pointer to an int with value the address of the first int in the
   * dxd array.
   * Note the proper use of & and parenthesis to take the address of an 
   * array element!!!
   */
  board_ptr = &(board[0][0]);
  
  printf("\nFirst, use the pointer dereferencing to fill the array.\n");
  for (int i=0;i<total;i++){
      *(board_ptr+i) = tile--;
  }
    
  printf("\nDone!\nSecond, use the matrix dereferencing to display the array.\n");
  for (int i=0;i<d;i++){
    for (int j=0;j<d;j++){
      printf("%c%d",j%d ? ' ' : '\n',board[i][j]);
    }
  }  
}
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
      tile = d*d-1;

  /* define a pointer to an int with value the address of the first int in the
   * dxd array.
   * Note the proper use of & and parenthesis to take the address of an 
   * array element!!!
   */
  int *intPtr = &(board[0][0]);
  
  printf("\nZero, use the matrix dereferencing to fill the array.\n");
  for (int i=0;i<total;i++){
      *(intPtr+i) = tile--;
  }
  
/*  printf("\nFirst, use the matrix dereferencing to fill the array.\n");
  for (int i=0;i<d;i++){
    for (int j=0;j<d;j++){
      board[i][j] = tile--;
    }
  }*/
  
  printf("\nDone!\nSecond, use the matrix dereferencing to display the array.\n");
  for (int i=0;i<d;i++){
    for (int j=0;j<d;j++){
      printf("%c%d",j%d ? ' ' : '\n',board[i][j]);
    }
  }

  printf("\n\nThird, use the pointer dereferencing to display the array.\n");
  for (int i=0;i<total;i++){
    printf("%c%d",i%d ? ' ' : '\n',*(intPtr+i));
  }
  
  printf("\n\nForth, use the pointer dereferencing to negate the array.\n");
  for (int i=0;i<total;i++){
    *(intPtr+i) = - *(intPtr+i);
  }

  printf("\nDone!\n\nFifth, use the pointer dereferencing to display the NEW array.\n");
    for (int i=0;i<total;i++){
    printf("%c%d",i%d ? ' ' : '\n',*(intPtr+i));
  }

    printf("\nDone!\n\nSixth, use the pointer dereferencing with '++' to display the NEW array.\n");
    for (int i=0;i<total;i++){
    printf("%c%d",i%d ? ' ' : '\n',*intPtr++);
  }
  printf("\nDone!\n");
  return 0;
}
  

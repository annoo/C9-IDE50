/*
 * pointers.c
 * examples of pointers that work
 */

#include <stdio.h>

#define d 4

int board[d][d],
    total = d*d,
    tile;

int *intPtr = &(board[0][0]);
  

//prototypes
void Second(void);
void Third(void);
void Forth(void);
void Fifth(void);
void Sixth(void);

int main(){
  
  tile = total -1;  

  printf("\nFirst, use pointerMath to fill the array.\n");
  for (int i=0; i<total; i++){
      (**board+i) = *tile;
      tile--;
  }
  Second();
  Third();
  Forth();
  Fifth();
  Sixth();

  printf("\nDone!\n");
  return 0;
}

void Second(void){  
  printf("\nDone!\nSecond, use the matrix dereferencing to display the array.\n");
  for (int i=0;i<d;i++){
    for (int j=0;j<d;j++){
      printf("%c%d",j%d ? ' ' : '\n',board[i][j]);
    }
  }
}

void Third(void){
  printf("\n\nThird, use the pointer dereferencing to display the array.\n");
  for (int i=0;i<d*d;i++){
    printf("%c%d",i%d ? ' ' : '\n',*(intPtr+i));
  }
}

void Forth(void){
  printf("\n\nForth, use the pointer dereferencing to negate the array.\n");
  for (int i=0;i<d*d;i++){
    *(intPtr+i) = - *(intPtr+i);
  }
}

void Fifth(void){
  printf("\nDone!\n\nFifth, use the pointer dereferencing to display the NEW array.\n");
    for (int i=0;i<d*d;i++){
    printf("%c%d",i%d ? ' ' : '\n',*(intPtr+i));
  }
}

void Sixth(void){
    printf("\nDone!\n\nSixth, use the pointer dereferencing with '++' to display the NEW array.\n");
    for (int i=0;i<d*d;i++){
    printf("%c%d",i%d ? ' ' : '\n',*intPtr++);
  }
}  

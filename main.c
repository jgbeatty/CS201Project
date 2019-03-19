#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "win.c"
#include "twoplayers.c"


void twoPlayers(char **, int , int);
char **allocateMem(char **, int, int);
char **zeroOut(char **,int, int);

int main() {
  int row;
  int column;
  char again[10] = "yes";
  printf("%s\n", again);
  while ( strcasecmp(again, "yes") == 0 ) {
    char answer[10];
    printf("Enter: two - for two players, or one - for single player against the computer: " );
    scanf("%s", answer);

    while ( (strcasecmp(answer, "two") == 0) && (strcasecmp(answer, "one") == 0) ) {
      printf("Error! please enter \"one\" or \"two\" : ");
      scanf(" %s", answer);
    }
    int point;
    if (strcasecmp(answer, "one") == 0) 
      point = 1;
    else 
      point = 2;

    printf("\nHow many rows do you want? Please enter a number greater than 4  \t: ");
    scanf("%d", &row);

    printf("\nHow many columns do you want? Please enter a number greater than 4\t: ");
    scanf("%d", &column);

    
    char **board;
    board = allocateMem(board, row, column);
    board = zeroOut(board, row, column);

    switch (point) {
      case 1:
        break;
      case 2:
        twoPlayers(board, row, column);
        break;
    }

    
    printf("Do you want to play again? (yes)/(no) : ");
    scanf(" %s", again);
  }

  printf("Thank you for playing!\n");
  return 0;
}
char **allocateMem(char **array, int row, int column) {
  array = malloc (sizeof(char *) * row);
    for (int i = 0; i < row; i++)
        array[i] = malloc (sizeof(char *) * column);
    return array;
}

char **zeroOut(char ** array, int row, int column) {
  for (int a = 0; a < row; a++) 
    for (int b = 0; b < column; b++)
      array[a][b] = ' ';
    
  return array;
}



// Row x Column
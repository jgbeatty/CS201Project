#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mis.c"
#include "twoplayers.c"
#include "oneplayer.c"



void onePlayer(char **, int, int, int *, int*);
void twoPlayers(char **, int , int, int *, int*);
char **allocateMem(char **, int, int);
char **zeroOut(char **,int, int);


int main() {
  int row;
  int column;
  char again[10] = "yes";
  char answer[10];
  char change[10] = "yes";
  int point;
  printf("Enter: two - for two players, or one - for single player against the computer: " );
  scanf("%s", answer);

  while ( (strcasecmp(answer, "two") != 0) && (strcasecmp(answer, "one") != 0) ) {
    printf("Error! please enter \"one\" or \"two\" : ");
    scanf(" %s", answer);
  }
  if (strcasecmp(answer, "one") == 0)
    point = 1;
  else
    point = 2;

  int numwins1 = 0;
  int numwins2 = 0;
  while ( strcasecmp(again, "yes") == 0 ) {
    char **board;
    if(strcasecmp(change, "yes") == 0) {
      printf("\nHow many rows do you want? Please enter a number greater than 4  \t: ");
      scanf("%d", &row);
      printf("How many columns do you want? Please enter a number greater than 4\t: ");
      scanf("%d", &column);
      board = allocateMem(board, row, column);
    }

    board = zeroOut(board, row, column);

    switch (point) {
      case 1:
        onePlayer(board, row, column, &numwins1, &numwins2);
        break;
      case 2:
        twoPlayers(board, row, column, &numwins1, &numwins2);
        break;
    }


    printf("Do you want to play again? (yes)/(no) : ");
    scanf(" %s", again);
    if (strcasecmp(again, "yes") == 0 ){
      printf("Would you like to change the board size?\t:");
      scanf(" %s", change);
    }
  }
  if (point == 1) {
    printf("You won %d matches -- The computer won %d matches\n", numwins1, numwins2);
  }
  if (point == 2) {
    printf("Player 1 won %d matches -- Player 2 won %d matches\n", numwins1, numwins2);
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

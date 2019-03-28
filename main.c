/* Jackson Beatty 03/29/19
This is my portfolio project for CS 201. In this project I coded a connect four game that can be played with another
  or with the computer. The game board size can be adjusted and the game keeps track of total wins.
The computer uses a negamax function to score each of the moves to find the next best move.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "mis.c"
#include "twoplayers.c"
#include "oneplayer.c"

void onePlayer(char **, int, int, int *, int*);
void twoPlayers(char **, int , int, int *, int*);
char **allocateMem(char **, int, int);
char **zeroOut(char **,int, int);
char **goodByeArray(char **, int , int);


int main() {
  int row;
  int column;
  char temp[10] = "no";
  char again[10] = "yes";
  char answer[10];
  char change[10] = "yes";
  int point;
  char **board;
  printf("Enter: two - for two players, or one - for single player against the computer: " );
  scanf("%s", answer);

  while ( (strncasecmp(answer, "two", 3) != 0) && (strncasecmp(answer, "one", 3) != 0) ) {
    printf("Error! please enter \"one\" or \"two\" : ");
    scanf(" %10s", answer);
  }
  printf("%10s\n", answer);
  if (strncasecmp(answer, "one", 3) == 0)
    point = 1;
  else
    point = 2;

  int numwins1 = 0;
  int numwins2 = 0;
  while ( strncasecmp(again, "yes", 3) == 0 ) {
    if(strncasecmp(change, "yes", 3) == 0) {
      strncpy(temp, "no", 2);
      while (!number(temp)) {
        printf("\nHow many rows do you want? Please enter a number greater than 4  \t: ");
        scanf("%10s", temp);
      }
      row = atoi(temp);
      strncpy(temp, "no", 2);
      while (!number(temp)) {
      printf("How many columns do you want? Please enter a number greater than 4\t: ");
        scanf("%10s", temp);
      }
      column = atoi(temp);
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
      scanf(" %3s", change);
    }
    if (strcasecmp(change, "yes") == 0) {
      goodByeArray(board, row, column);
    }
  }
  if (point == 1) {
    printf("You won %d matches -- The computer won %d matches\n", numwins1, numwins2);
  }
  if (point == 2) {
    printf("Player 1 won %d matches -- Player 2 won %d matches\n", numwins1, numwins2);
  }

  goodByeArray(board, row, column);
  printf("Thank you for playing!\n");
  return 0;
}

// this function allocates memory for the array that is the board
char **allocateMem(char **array, int row, int column) {
  array = malloc (sizeof(char *) * row);
    for (int i = 0; i < row; i++)
        array[i] = malloc (sizeof(char *) * column);
    return array;
}

// this function erases the board and clears all stones
char **zeroOut(char ** array, int row, int column) {
  for (int a = 0; a < row; a++)
    for (int b = 0; b < column; b++)
      array[a][b] = ' ';

  return array;
}

// this function deallocates memory to the array.
char **goodByeArray(char **array, int row, int column) {
  for (int i = 0; i < row; i++) {
    free(array[i]);
  }
  free(array);
  return array;
}

// Row x Column

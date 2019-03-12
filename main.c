#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "win.c"
#include "twoplayers.c"


void twoPlayers(char **, int , int);
//void vsComputer(char **);
// void printBoard(char **);
// char **allocateMem(char **);
// char **zeroOut(char **);
// int checkWin(char **, int, char);
// void placeMark(int , char, char **);

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

    printf("How many rows do you want? Please enter a number greater than 4\t: ");
    scanf("%d", &row);

    printf("How many rows do you want? Please enter a number greater than 4\t: ");
    scanf("%d", &column);

    printf("%d\n%d\n%d\n", point, row, column);
    
    char **board;
    board = allocateMem(board, row, column);
    board = zeroOut(board, row, column);

    switch (point) {
      case 1:
        printf("Case 1\n");
        break;
      case 2:
        printf("Case 2\n");
        twoPlayers(board, row, column);
        break;
    }

    
    printf("Do you want to play again? (yes)/(no) : ");
    scanf(" %s", again);
  }

  printf("Thank you for playing!\n");
  return 0;
}



// Row x Column
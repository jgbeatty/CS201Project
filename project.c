#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "win.c"
// #define row 6
// #define column 7

void printBoard(char **);
char **allocateMem(char **);
//void onePlayer(char **);
void twoPlayers(char **);
//void vsComputer(char **);
char **zeroOut(char **);
int checkWin(char **, int, char);
void placeMark(int , char, char **);

int main() {
  char answer;
  printf("Press: s - for single player, t - for two players, or c - for playing agains the computer: " );
  scanf("%c", &answer);

  while ( (answer != 's') && (answer != 't') && (answer != 'c') ) {
    printf("Error: ");
    scanf(" %c", &answer);
  }

  char **board;
  board = allocateMem(board);
  board = zeroOut(board);

  switch(answer) {
    case 's' :
      //onePlayer(board);
      break;
    case 't' :
      twoPlayers(board);
      break;
    case 'c' :
      //vsComputer(board);
      break;
  }
  printf("Whould you like to play again? y/n : ");
  scanf("%c", &answer);
  while ( (answer != 'y') || (answer != 'n') ){
    printf("Error: please enter \"y\" / \"n\" " );
    scanf("%c", &answer);
  }
  while ( answer == 'y') {

  }

  printf("Thank you for playing!\n");
  return 0;
}

char **allocateMem(char **array) {
  array = malloc (sizeof(char *) * 6);
    for (int i = 0; i < 6; i++)
        array[i] = malloc (sizeof(char *) * 7);
    return array;
}

char **zeroOut(char ** array) {
  for (int a = 0; a < 6; a++) 
    for (int b = 0; b < 7; b++)
      array[a][b] = ' ';
    
  return array;
}

void printBoard(char **array) {
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 7; b++) {
            printf("| %c ", array[a][b]);
        }
        printf("|\n");
        printf("-----------------------------\n");
    }
    printf("  1   2   3   4   5   6   7\n");
    return;
}

void twoPlayers(char **board) {
  printf("Welcome to two player\n");
  printBoard(board);
  int win = 0;
  int move = 0;
  char turn = ' ';
  while (1) {
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %d", &move);
    while ( (move != 1) && (move != 2) && (move != 3) && (move != 4) && (move != 5) && (move != 6) && (move != 7) ){
      printf("ERROR: Invalid number. Please enter number from 1 to 7 : ");
      scanf(" %d", &move);
      printf("\n");
    }
    while (board[0][(move-1)] != ' ' ) {
      printf("ERROR: column is filled, please pick a different one : ");
      scanf(" %d", &move);
      printf("\n");

    }
    move--;
    turn = 'X';
    placeMark(move, turn, board);
    win = checkWin(board, move, turn);
    printf("\n\n");
    printBoard(board);
    if (win == 1)
      break;
    printf("Player 2, please enter the column you want to use : ");
    scanf(" %d", &move);
    while ( (move != 1) && (move != 2) && (move != 3) && (move != 4) && (move != 5) && (move != 6) && (move != 7) ){
      printf("ERROR: Invalid number. Please enter number from 1 to 7 : ");
      scanf(" %d", &move);
      printf("\n");
    }
    while (board[0][(move - 1)] != ' ' ) {
      printf("ERROR: column is filled, please pick a different one : ");
      scanf(" %d", &move);
      printf("\n");
    }
    move--;
    turn = 'O';
    placeMark(move, turn, board);
    printf("\n\n");
    printBoard(board);
    win = checkWin(board, move, turn);
    if (win == 1)
      break;
  }
  if (turn == 'X') {
    printf("Congratulations player one, YOU WIN!");
  }
  else 
    printf("Congratulations player two, YOU WIN!");
  
}

void placeMark(int move, char turn, char **board) {
  int check = 5;
  while (board[check][move] != ' ') {
    check--;
  }
  board[check][move] = turn;

  return;
}

int checkWin(char **board, int move, char turn) {
  int count = 0;
  int win = 0;
  win = Vertical(board, move, turn);
  if (win != 1) {
    win = Horizontal(board, move, turn);
  }
  if (win != 1) {
    win = Backslash(board, move, turn);
  }
  if (win != 1) {
    win = Fowardslash(board, move, turn);
  }

  return win;
}



// Row x Column
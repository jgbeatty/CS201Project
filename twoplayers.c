#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printBoard(char **, int , int);
char **allocateMem(char **, int , int);
char **zeroOut(char **, int , int);
int checkWin(char **, int, char, int , int);
void placeMark(int , char, char **, int , int);

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

void printBoard(char **array, int row, int column) {
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < column; b++) {
            printf("| %c ", array[a][b]);
        }
        printf("|\n-");
        for (int b = 0; b < column; b++) {
          printf("----");
        }
        printf("\n");
    }
    for (int a = 1; a <= column; a++) {
      if (a < 10) 
        printf(" %d  ", a);
      else
        printf(" %d ", a);
    }
    printf("\n");
    return;
}

void twoPlayers(char **board, int row, int column) {
  printf("Welcome to two player\n");
  printBoard(board, row, column);
  int win = 0;
  int move = 0;
  char turn = ' ';
  while (1) {
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %d", &move);
    while ( (move > 1 ) && (move >= column) ){
      printf("ERROR: Invalid number. Please enter number from 1 to %d : ", column);
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
    placeMark(move, turn, board, row, column);
    win = checkWin(board, move, turn, row, column);
    printf("\n\n");
    printBoard(board, row, column);
    if (win == 1)
      break;
    printf("Player 2, please enter the column you want to use : ");
    scanf(" %d", &move);
    while ( (move < 1) && (move >= column) ){
      printf("ERROR: Invalid number. Please enter number from 1 to %d : ", column);
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
    placeMark(move, turn, board, row, column);
    printf("\n\n");
    printBoard(board, row, column);
    win = checkWin(board, move, turn, row, column);
    if (win == 1)
      break;
  }
  if (turn == 'X') {
    printf("Congratulations player one, YOU WIN!\n");
  }
  else 
    printf("Congratulations player two, YOU WIN!\n");
  
}

void placeMark(int move, char turn, char **board, int row, int column) {
  int check = (row - 1);
  while (board[check][move] != ' ') {
    check--;
  }
  board[check][move] = turn;

  return;
}

int checkWin(char **board, int move, char turn, int row, int column) {
  int count = 0;
  int win = 0;
  win = Vertical(board, move, turn, row, column);
  if (win != 1) {
    win = Horizontal(board, move, turn, row, column);
  }
  if (win != 1) {
    win = Backslash(board, move, turn, row, column);
  }
  if (win != 1) {
    win = Fowardslash(board, move, turn, row, column);
  }

  return win;
}
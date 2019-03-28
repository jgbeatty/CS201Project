#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void twoPlayers(char **board, int row, int column, int* numwins1, int *numwins2) {
  system("clear");
  printf("Welcome to two player\n");
  printBoard(board, row, column);
  int win = 0;
  int move = 0;
  char turn = ' ';
  char temp[10];
  int tie = 0;
  while (1) {
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %10s", temp);
    while ((!number(temp))) {
      printf("ERROR: enter a valid number from 1 to %d  :", column);
      scanf("%10s", temp);
    }
    move = atoi(temp);
    while ( (move < 1 ) || (move > column) || (board[0][(move-1)] != ' ') ){
      if ((move < 1 ) || (move > column)) {
        printf("ERROR: Invalid number. Please enter number from 1 to %d  : ", column);
      }
      else {
        printf("ERROR: column is filled, please pick a different one : ");
      }
      scanf(" %10s", temp);

      while ((!number(temp))) {
        printf("ERROR: enter a valid number from 1 to %d  :", column);
        scanf("%10s", temp);
      }
      move = atoi(temp);
      printf("\n");
    }

    move--;
    turn = 'X';
    placeMark(move, turn, board, row, column);
    printf("\n\n");
    system("clear");
    printBoard(board, row, column);
    win = checkWin(board, move, turn, row, column);
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie ==1) {
      break;
    }

    if (boardFilled(board, row, column) ) break;
    printf("Player 2, please enter the column you want to use : ");
    scanf(" %10s", temp);
    while ((!number(temp))) {
      printf("ERROR: enter a valid number from 1 to %d  :", column);
      scanf("%10s", temp);
    }
    move = atoi(temp);
    while ( (move < 1 ) || (move > column) || (board[0][(move-1)] != ' ') ){
      if ((move < 1 ) || (move > column)) {
        printf("ERROR: Invalid number. Please enter number from 1 to %d  : ", column);
      }
      else {
        printf("ERROR: column is filled, please pick a different one : ");
      }
      scanf(" %10s", temp);

      while ((!number(temp))) {
        printf("ERROR: enter a valid number from 1 to %d  :", column);
        scanf("%10s", temp);
      }
      move = atoi(temp);
      printf("\n");
    }
    move--;
    turn = 'O';
    placeMark(move, turn, board, row, column);
    printf("\n\n");
    system("clear");
    printBoard(board, row, column);
    win = checkWin(board, move, turn, row, column);
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie == 1) {
      break;
    }
  }
  if (tie) {
    printf("It is a tie. YOU BOTH LOSE\n");
  }
  else if (turn == 'X') {
    printf("Congratulations player one, YOU WIN!\n");
    *numwins1 = *numwins1 + 1;
  }
  else {
    printf("Congratulations player two, YOU WIN!\n");
    *numwins2 = *numwins2 + 1;
  }

}

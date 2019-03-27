#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// int computerMove(char**, int, int);

void onePlayer(char** board, int row, int column) {
  printf("welcome to one player\n");
  printBoard(board, row, column);
  int win = 0;
  int tie = 0;
  int move = 0;
  int turn = ' ';
  while (1) {
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %d", &move);
    while ( (move < 1 ) || (move > column) ){
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
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie == 1) break;

    move = computerMove(board, row, column);
    // move--;
    turn = 'O';
    placeMark(move, turn, board, row, column);
    win = checkWin(board, move, turn, row, column);
    printf("\n\n");
    printBoard(board, row, column);
    if (win == 4) break;
  }
  if (tie == 1) {
    printf("It is a tie. YOU BOTH LOSE\n");
  }
  else if (turn == 'X') {
    printf("Congratulations player one, YOU WIN!\n");
  }
  else {
    printf("THE COMPUTER WON!\n");
  }

}

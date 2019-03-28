#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//player two mode
void twoPlayers(char **board, int row, int column, int* numwins1, int *numwins2) {
  system("clear");
  printf("Welcome to two player\n");
  printBoard(board, row, column);
  int win = 0;
  int move = 0;
  char turn = ' ';
  char temp[10];
  int tie = 0;
  // loop starts the game play
  while (1) {
    // Player 1 chooses a column to play in
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %10s", temp);
    // Test cases that verify a number from 1 - #columns
    while ((!number(temp))) {
      printf("ERROR: enter a valid number from 1 to %d  :", column);
      scanf("%10s", temp);
    }
    //conditional checks
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

    // subtracts one since the array is 0 through (#columns - 1)
    move--;
    turn = 'X';
    placeMark(move, turn, board, row, column);
    // clears screen and prints board
    system("clear");
    printf("\n\n");
    printBoard(board, row, column);
    win = checkWin(board, move, turn, row, column);
    //checks for a win or tie
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie ==1) {
      break;
    }

    //starts player 2's turn and promts for a place
    printf("Player 2, please enter the column you want to use : ");
    scanf(" %10s", temp);
    //conditional checks to verify a legal move
    while ((!number(temp))) {
      printf("ERROR: enter a valid number from 1 to %d  :", column);
      scanf("%10s", temp);
    }
    //more checks
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

    // subtracts one since the array is 0 through (#columns - 1)
    move--;
    turn = 'O';
    placeMark(move, turn, board, row, column);
    //clears screen and prints board
    system("clear");
    printf("\n\n");
    printBoard(board, row, column);
    win = checkWin(board, move, turn, row, column);
    //checks for win or tie
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie == 1) break;
  }
  if (tie) { // tie broke the game
    printf("It is a tie. YOU BOTH LOSE\n");
  }
  else if (turn == 'X') { //Player one won
    printf("Congratulations Player one, YOU WIN!\n");
    *numwins1 = *numwins1 + 1;
  }
  else { //Player two won
    printf("Congratulations Player two, YOU WIN!\n");
    *numwins2 = *numwins2 + 1;
  }

}

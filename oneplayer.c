#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// This is one player mode where the player plays the AI system
void onePlayer(char** board, int row, int column, int *numwins1, int *numwins2) {
  system("clear");
  printf("Welcome to one player\n");
  printBoard(board, row, column);
  int win = 0;
  int tie = 0;
  int move = 0;
  char temp[10];
  int turn = ' ';
  // while loop starts the game play
  while (1) {
    // Player 1 chooses the column they want and the program checks for errors.
    printf("Player 1, please enter the column you want to use : ");
    scanf(" %10s", temp);
    // makes sure that player one enters a legal number
    while ((!number(temp))) {
      printf("ERROR: enter a valid number from 1 to %d  :", column);
      scanf("%10s", temp);
    }
    // conditional checks
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
    win = checkWin(board, move, turn, row, column);
    // checks for wins and ties
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie == 1) break;

    //finds computer's move using function
    move = computerMove(board, row, column);
    // move--;
    turn = 'O';
    // places mark, checks for win
    placeMark(move, turn, board, row, column);
    win = checkWin(board, move, turn, row, column);
    // clears screen and prints board
    system("clear");
    printf("\n\n");
    printBoard(board, row, column);
    if (win == 4) break;
    tie = boardFilled(board, row, column);
    if (tie == 1) break;
  }
  if (tie == 1) { //tie broke the game
    printf("\n\n");
    system("clear");
    printBoard(board, row, column);
    printf("\nIt is a tie. YOU BOTH LOSE\n");

  }
  else if (turn == 'X') { //player one won the game
    system("clear");
    printf("\n\n);
    printBoard(board, row, column);
    printf("\nCongratulations player one, YOU WIN!\n");
    *numwins1 = *numwins1 + 1;
  }
  else { //computer won the game
    system("clear");
    printf("\n\n");
    printBoard(board, row, column);
    printf("\nTHE COMPUTER WON!\n");
    *numwins2 = *numwins2 + 1;
  }

}

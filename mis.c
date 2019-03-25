#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void placeMark(int move, char turn, char **board, int row, int column) {
  int check = (row - 1);
  while (board[check][move] != ' ') {
    check--;
  }
  board[check][move] = turn;

  return;
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
        printf("  %d ", a);
      else
        printf(" %d ", a);
    }
    printf("\n");
    return;
}



bool Vertical(char **board, int move, char turn, int row, int column) {
    int check = (row-1);
    int four = 0;
    bool win = false;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
    }
    if (check != 0)
        check ++;
    while ( (check <= (row - 1)) && (move <=(column - 1)) && (move >= 0) && (board[check][move] == turn)  ) {
        four++;
        if (four == 4) {
            win = true;
            break;
        }
        check++;
    }
    return win;
}

bool Horizontal(char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    bool win = false;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
    }
    if (check != 0)
        check ++;
    while ( ( (move-1) >= 0) && (board[check][move-1] == turn) ) {
        move--;
    }
    while ( (move < column) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = true;
            break;
        }
        move++;
    }
    return win;
}

bool Backslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    bool win = false;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
      printf("else\n");
      while(board[check][move] != ' ') {
          check--;
      }
      check++;
    }
    while ( (check > 0) && (move < column) && (board[(check - 1)][(move + 1)] == turn) ) {
        move++;
        check--;
    }
    while ( (check < row) && (move > 0) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = true;
            break;
        }
        check++;
        move--;
    }
    return win;
}

bool Fowardslash (char **board, int move, char turn, int row, int column) {
    int check = (row - 1);
    int four = 0;
    bool win = false;
    if (board[0][move] != ' ') {
        check = 0;
    }
    else {
        while(board[check][move] != ' ') {
            check--;
        }
        check++;
    }
    while ( (check > 0) && (move > 0) && (board[check - 1][move - 1] == turn) ) {
        move--;
        check--;
    }
    while ( (check < row) && (move < column) && (board[check][move] == turn) ) {
        four++;
        if (four == 4) {
            win = true;
            break;
        }
        check++;
        move++;
    }
    return win;
}

bool checkWin(char **board, int move, char turn, int row, int column) {
  int count = 0;
  bool win = false;
  win = Vertical(board, move, turn, row, column);
  if (!win) {
    win = Horizontal(board, move, turn, row, column);
  }
  if (!win) {
    win = Backslash(board, move, turn, row, column);
  }
  if (!win) {
    win = Fowardslash(board, move, turn, row, column);
  }

  return win;
}

bool boardFilled(char** board, int row, int column) {
  bool all = false;
  for (int i = 0; i < column; i++){
    if(board[0][i] == ' ') {
      all = false;
      break;
    }
    all = true;
  }

  return all;
}

void remove(char** board, int column) {
  int row = 0;
  while (board[row][column] == ' ') {
    row++;
  }
  board[row][column] = ' ';
  return;
}

int scoreMove(char** board, int row, int column, int movecol) {
  int score = 0;
  int moverow;
  while (int i =0; i < row; i++) {
    row++;
  }
  moverow = row;



  return score
}
int computerMove(char** board, int row, int column) {
  int rating[column];
  for (int i = 0; i < column; i++){
    placeMark(i, 'O', )
    for (int j = 0; j < column; j++) {

    }
  }
  return ( rand() % column );
}

int raiting(char** board, int row, int column, int select){

}
